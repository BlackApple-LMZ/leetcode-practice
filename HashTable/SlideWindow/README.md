# SlideWindow

note:滑窗在字符串和数组方面很常用，结合hashmap，一般处理**连续**的字符串，有变长和定长的滑窗。

对于求最大长度的滑窗，一般考虑不收缩左边界的优化！！！！
```
void slidingwindows(vector<int> nums,int k)
{ 
    先预处理 
    然后进行滑动窗的循环，一般是个while循环，同时实现定义好滑动窗的起点和终点，同时还有一个是记录当前状态的数或者数组，比如count 
    int begin = 0, end = 0; 
    int count = 0; 
    while(end<nums.size()){ 
        1.在循环里先是当前end到达的时候，更新count 
        2.判断更新完后是否满足条件，比如count<k 
        3.如果满足的话，可以进行一些处理，如果是求最小长度之类的，会在满足时进行操作 
        4.如果不满足的话，也需要进行一些处理，比如求最大长度之类的，会在此时进行操作 
        以上3,4条常见的操作就是一个while循环，进行左边界begin的收缩处理，一直到收缩到满足/不满足条件为止 
    } 
}
```
### 30 和438差不多，只不过换成了大小相等的string查找 ***
思路：这个题没有做，就看了一下思路，和438不同的地方在于需要对不同的起点进行判断；

### 76 string S和T, 找到S中包含T的所有元素的最短区间 ***
思路：就最短子序列滑窗加hashmap，用count统计目标字符串中比当前扫描的滑动窗中多的字符的个数，3次过，第一次substr第二个参数的含义搞错了，第二次忽略判断res最短size；

### 209 无序数组，求最小满足给定和的长度 ** 再刷！！！
思路：第一次没有做出来，过一段时间看也没有简单想法，看了滑窗之后再刷两次过，第一次没有考虑特殊情况。经典滑窗法，或者说两个指针法：先更新右端，然后满足给定条件之后，缩短左边界，求最小值；

### 219 求数组连续k范围内是否存在相等的数 *
思路：hashmap维护滑窗内的次数，超出窗的部分--，新进来的++，如果新来的数据已经在hashmap里面了，说明有重复，满足要求；

### 220 求数组连续k范围内是否存在差小于t的数 ** fail 二刷
思路：和219思路差不多，有点贪心的地方是|x - nums[i]| <= t  ==> -t <= x - nums[i] <= t ==> x-nums[i] >= -t ==> x >= nums[i]-t 只需要找到满足nums[i]-t的最小值，然后再判断x - nums[i] <= t是否成立；妙啊！！！

### 424 字符串改变K个字母，使得字符串中有最长的一串完全相同的子串 ** 回头多看看
思路：第一次没有做出来，即使知道用滑窗法也是没有想出来；问题转换成找出一个最长的子串，子串需要满足其中个数最多的字母不一样的字母总数不超过K，K大小来维持滑窗;将vector128改成26可以从48ms提高到16ms，**对于求最长子串问题，一个非常trick的优化** 这种题最里面那层收缩左边界长度的while循环是可以省略掉的。即把while循环改成一个if判断，这样做本质上是保存到目前为止滑动窗的最大宽度。也就是说不必让滑动窗收缩，保持滑动窗处于已经找到的最大长度即可，当发现不满足题意时，同时向后移动即可，满足条件时，只用向又扩大即可。妙啊！！！！由16ms提高到4ms；

### 438 在string中找到所有给定的Anagrams * 多刷
思路：虽然是简单题，但是没有做出来啊；用滑窗的话，维持一个固定size，然后比较字符串对应的vector向量，其实挺简单的……；优化方法：比较的过程很费时间，所以**用count变量进行优化，count储存的是目标字符串中比当前扫描的滑动窗中多的字符的个数，很妙啊！！！**

### 567 在string中如果能找到给定的Anagrams 返回true*
思路：是438的简单版，找到就返回true，438要返回所有的index，同样的方法；过了一个中午二刷，四次过，有个==需要改成>=的情况；
