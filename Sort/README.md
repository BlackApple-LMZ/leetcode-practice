# Sort

### 56 合并重复区间 **
思路：就对区间先排序，然后合并，10分钟AC，然后排序函数如果自己写的话，时间会更快一点，比较简单；

### 57 对于不重叠的区间，给一个新的区间，返回最后合并的区间 *** 大佬的版本可以常熟悉熟悉
思路：56的升级版，其实思路挺简单的，就是有很多坑坑需要踩，提交了好几次弥补完整代码，但是代码写的很乱了……；discuss大佬们给出了很简洁的版本，牛逼，太妙了！！！！！！！！！！！

### 75 颜色排序 三种颜色，相邻颜色排到一起**
思路：桶排序，先统计频次，再重写nums，two pass很快；follow up要求one pass，有人用三个指针，i遍历，j表示最左，k表示右，i遇到0就和j换，遇到2就和k交换，同时移动指针，**妙啊**；

### 179 由vector各个数组合成的最大的数 [3,30,34,5,9] "9534330" **
思路：想到了需要自己重写比较函数，但是比较函数写的太复杂，也不太对…没有通过；solution的比较函数写的很妙啊！！！，直接比较前后相加的结果哦，需要二刷了；
