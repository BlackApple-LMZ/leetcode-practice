# Binary Search
notes for Binary Search:

针对已排好序的数组；

递归与循环两种方式：35作为demo

**34 升序重复数组 找target出现范围 递归解决 one pass 

思路：循环二分搜索，每次查找到数的时候更新minl和maxr，并继续查找；solution是分两次查找，第一次查找left，第二次查找right，这个想法很妙，比我的思路好；

*35 升序数组查找target 循环或者递归

*167 升序数组查找两个不同位置的数和为target  solution方法mark一下！！！

思路：自己的思路，循环第一个数，然后二分查找第二个数;自己的思路很慢了，solution采用左右两边同时夹紧，sum>target,r--,sum<target,l++;很妙很快啊

***174 地牢游戏 在dp里有说
