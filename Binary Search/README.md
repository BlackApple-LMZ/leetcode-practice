# Binary Search
notes for Binary Search:

针对已排好序的数组；

递归与循环两种方式：35作为demo 三分搜索：374

int begin(0), end(nums.size()-1);
        while(begin<=end){
            int mid = (begin+end)/2;
            if(target == nums[mid])
                return mid;
            else if(target > nums[mid])
                begin = mid+1;
            else
                end = mid-1;
        }
        
**34 升序重复数组 找target出现范围 递归解决 one pass 

思路：循环二分搜索，每次查找到数的时候更新minl和maxr，并继续查找；solution是分两次查找，第一次查找left，第二次查找right，这个想法很妙，比我的思路好；

*35 升序数组查找target 循环或者递归

**74 二维数组查找数 每行的数都大于上一行的数 第二种方法mark！！！！ 下面240题目的区别

思路：就两次二分查找，先找在哪一行，再找哪一列；discuss大佬们说直接一次二分查找，因为是完全线性的，妙啊！！！

*167 升序数组查找两个不同位置的数和为target  solution方法mark一下！！！

思路：自己的思路，循环第一个数，然后二分查找第二个数;自己的思路很慢了，solution采用左右两边同时夹紧，sum>target,r--,sum<target,l++;很妙很快啊

***174 地牢游戏 在dp里有说

**240 并不是整体严格升序 和74有区别 第二种方法很妙，mark！！！！！

思路：就O(mlog(n))的时间复杂度，很慢；discuss O(m+n)的解决办法，从右上向左下搜索；很妙！！！！

**287 寻找重复数字 必须mark！！！方法2、3要掌握；

思路：1用hashset 时间空间On；2快慢指针，太妙了！！！！！形成了index到val的映射，就像一个有环的链表，和链表求环一样；3二分查找，也很妙的，左右两端点，每次循环整个数组，统计大于mid的数目，然后二分O（nlogn）；

*367 判断一个数是否为完全平方数 这个mark一下！！！！！

思路：就二分查找，开始比较乘积与num，溢出，后来比较商的大小O(log(n))，也可以将乘积表示成long的数据形式；利用1+3+5+……+（2n-1）=n^2进行判断O(sqrt(n))；3用牛顿法计算平方根

*374 猜数的大小

思路：二分搜索；solution给出了三分搜索…随后证明在大部分情况下，二分搜索速度更快，因为用了更少的比较；

