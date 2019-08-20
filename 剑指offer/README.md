# 剑指offer

## 题目列表
1. 赋值运算符
2. 找出数组中重复的数字
3. 不修改数组找出重复的数字
4. 二维数组中的查找
5. 替换空格
6. 从尾到头打印链表
7. 重建二叉树
8. 二叉树的下一个结点
9. 两个栈实现队列 两个队列实现栈
10. 计算斐波那切数列;跳台阶，铺砖 
11. 旋转数组的最小数字
12. 矩阵中的路径
13. 机器人的运动范围
14.
15. 二进制中1的个数
16. 数值的整数次方
17. 打印1到最大的n位数
18. 在O(1)时间删除链表结点;删除链表中重复的结点
19. 正则表达式匹配
20. 表示数值的字符串
21. 调整数组顺序使奇数位于偶数前面
22. 链表中倒数第k个结点
23. 链表中环的入口结点
24. 反转链表
25. 合并两个排序的链表
26. 树的子结构
27. 二叉树的镜像
28. 对称的二叉树
29. 顺时针打印矩阵
30. 包含min函数的栈
31. 栈的压入、弹出序列
32. 不分行从上往下打印二叉树;分行从上到下打印二叉树;之字形打印二叉树
33. 二叉搜索树的后序遍历序列
34. 二叉树中和为某一值的路径
35. 复杂链表的复制
36. 二叉搜索树与双向链表
37. 序列化二叉树
38. 字符串的排列
39. 数组中出现次数超过一半的数字
40. 最小的k个数
41. 数据流中的中位数
42. 连续子数组的最大和
43. 从1到n整数中1出现的次数
44. 数字序列中某一位的数字
45. 把数组排成最小的数
46. 把数字翻译成字符串
47. 礼物的最大价值
48. 最长不含重复字符的子字符串
49. 丑数
50. 字符串中第一个只出现一次的字符
51. 数组中的逆序对
52. 两个链表的第一个公共结点
53. 数字在排序数组中出现的次数;0到n-1中缺失的数字;数组中数值和下标相等的元素
54. 二叉搜索树的第k个结点
55. 二叉树的深度;平衡二叉树
56. 数组中只出现一次的两个数字;数组中唯一只出现一次的数字
57. 和为s的两个数字;为s的连续正数序列
58. 翻转单词顺序;左旋转字符串
59. 滑动窗口的最大值;队列的最大值
60. n个骰子的点数
61. 扑克牌的顺子
62. 圆圈中最后剩下的数字
63. 股票的最大利润
## note：
- 21题的可扩展解法很有意思，mark
- 46题、51题值得关注
- 56题、57.2、59.1、
```
//根据一个数将数组分成左右两部分的函数，左边小于右边
int Partition(int data[], int length, int start, int end)
{
    if(data == nullptr || length <= 0 || start < 0 || end >= length)
        throw new std::exception("Invalid Parameters");

    int index = RandomInRange(start, end);
    Swap(&data[index], &data[end]);

    int small = start - 1;
    for(index = start; index < end; ++ index){
        if(data[index] < data[end]){
            ++ small;
            if(small != index)
                Swap(&data[index], &data[small]);
        }
    }

    ++ small;
    Swap(&data[small], &data[end]);

    return small;
}
```

### 1 赋值运算符
```
CMyString& CMyString::operator = (const CMyString& str)
{
    if(this == &str)
        return *this;

    delete []m_pData;
    m_pData = nullptr;

    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);

    return *this;
}
```
思路：四个细节 
- 返回引用，return *this;
- 传入参数常量引用；
- 释放已分配的内存；
- 判断*this是否与输入一样；

### 2.1 找出数组中重复的数字
题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
那么对应的输出是重复的数字2或者3。
```
bool duplicate(int numbers[], int length, int* duplication)
{
    if(numbers == nullptr || length <= 0)
        return false;
    for(int i = 0; i < length; ++i){
        if(numbers[i] < 0 || numbers[i] > length - 1)
            return false;
    }
    for(int i = 0; i < length; ++i){
        while(numbers[i] != i){
            if(numbers[i] == numbers[numbers[i]]){
                *duplication = numbers[i];
                return true;
            }
            // 交换numbers[i]和numbers[numbers[i]]             
            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
        }
    }
    return false;
}
```
思路：判断下标与对应的值是否相等，不等就看值与对应下标的值是否相等，妙啊！！！；

### 2.2 不修改数组找出重复的数字 leetcode 287
题目：在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至
少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的
输出是重复的数字2或者3。
```
int getDuplication(const int* numbers, int length)
{
    if(numbers == nullptr || length <= 0)
        return -1;

    int start = 1;
    int end = length - 1;
    while(end >= start)
    {
        int middle = ((end - start) >> 1) + start; //这个写法mark一下！
        int count = countRange(numbers, length, start, middle);
        if(end == start)
        {
            if(count > 1)
                return start;
            else
                break;
        }

        if(count > (middle - start + 1))
            end = middle;
        else
            start = middle + 1;
    }
    return -1;
}

int countRange(const int* numbers, int length, int start, int end)
{
    if(numbers == nullptr)
        return 0;

    int count = 0;
    for(int i = 0; i < length; i++)
        if(numbers[i] >= start && numbers[i] <= end)
            ++count;
    return count;
}
```
思路：用hash，时间O(n)，空间O(n)；用快慢指针，时间O(n)，空间常量，但是只能找到一个重复的数字；用二分查找，这个方法有点妙，1-n的范围，所以每次二分，然后查找数组里对应区间数出现的次数，也是只能找到一个重复的数字，时间O(nlogn)；

### 4 二维数组中的查找 leetcode 240
题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
整数，判断数组中是否含有该整数。
```
bool Find(int* matrix, int rows, int columns, int number)
{
    bool found = false;
    if(matrix != nullptr && rows > 0 && columns > 0){
        int row = 0;
        int column = columns - 1;
        while(row < rows && column >=0){
            if(matrix[row * columns + column] == number){
                found = true;
                break;
            }
            else if(matrix[row * columns + column] > number)
                -- column;
            else
                ++ row;
        }
    }
    return found;
}
```
思路：从右上角向左下角扫描，时间O(m+n);

### 5 替换空格 
题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
则输出“We%20are%20happy.”。
```
/*length 为字符数组str的总容量，大于或等于字符串str的实际长度*/
void ReplaceBlank(char str[], int length)
{
    if(str == nullptr && length <= 0)
        return;

    /*originalLength 为字符串str的实际长度*/
    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;
    while(str[i] != '\0'){
        ++ originalLength;
        if(str[i] == ' ')
            ++ numberOfBlank;
        ++ i;
    }

    /*newLength 为把空格替换成'%20'之后的长度*/
    int newLength = originalLength + numberOfBlank * 2;
    if(newLength > length)
        return;

    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal){
        if(str[indexOfOriginal] == ' '){
            str[indexOfNew --] = '0';
            str[indexOfNew --] = '2';
            str[indexOfNew --] = '%';
        }
        else{
            str[indexOfNew --] = str[indexOfOriginal];
        }
        -- indexOfOriginal;
    }
}
```
思路：用两个指针，从后向前替换；同样两个排好序的数组不开辟新空间的合并，也是这样从后向前；

### 6 从尾到头打印链表
题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。
```
void PrintListReversingly_Iteratively(ListNode* pHead)
{
    std::stack<ListNode*> nodes;

    ListNode* pNode = pHead;
    while(pNode != nullptr){
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }

    while(!nodes.empty()){
        pNode = nodes.top();
        printf("%d\t", pNode->m_nValue);
        nodes.pop();
    }
}
void PrintListReversingly_Recursively(ListNode* pHead)
{
    if(pHead != nullptr){
        if (pHead->m_pNext != nullptr){
            PrintListReversingly_Recursively(pHead->m_pNext);
        }
        printf("%d\t", pHead->m_nValue);
    }
}
```
思路：用栈辅助，或者借助递归，后序遍历；递归本质就是用栈实现的；

### 6 补充 链表的操作，末尾增加链表和删除指定元素的节点，返回节点的形式
```
ListNode* addNode(ListNode * root, int val){
	ListNode * node = new ListNode(val);
	if (root == nullptr)
		return node;
	ListNode * cur = root;
	while (cur->next){
		cur = cur->next;
	}
	cur->next = node;
	return root;
}
ListNode* eraseNode(ListNode * root, int value){
	ListNode * toDelet = nullptr;
	ListNode node(0);
	ListNode * cur = &node;
	cur->next = root;

	while (cur && cur->next){
		if (cur->next->val == value){
			toDelet = cur->next;
			cur->next = cur->next->next;
			delete toDelet; //注意要delete掉 指针还在，但是指针指向的内存块清楚了
			continue;
		}
		cur = cur->next;
	}
	return node.next;
}
```

### 7 重建二叉树 leetcode 105
题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,
2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建出
图2.6所示的二叉树并输出它的头结点。
```
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return pre(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
}
TreeNode* pre(vector<int>& preorder, vector<int>& inorder, int l1, int r1, int l2, int r2){
    if(l1>r1 || l2>r2)
        return NULL;

    int mid;
    for(mid=l2; mid<=r2; mid++){
        if(inorder[mid] == preorder[l1])
            break;
    }

    TreeNode* node = new TreeNode(preorder[l1]);

    node->left = pre(preorder, inorder, l1+1, l1+mid-l2, l2, mid-1);
    node->right = pre(preorder, inorder, l1+mid-l2+1, r1, mid+1, r2);

    return node;
}
```
思路：就用分治的办法，每次传入两个区间，对该区间进行递归构建树

### 8 二叉树的下一个结点
题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。
```
BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
    if(pNode == nullptr)
        return nullptr;

    BinaryTreeNode* pNext = nullptr;
    if(pNode->m_pRight != nullptr){
        BinaryTreeNode* pRight = pNode->m_pRight;
        while(pRight->m_pLeft != nullptr)
            pRight = pRight->m_pLeft;

        pNext = pRight;
    }
    else if(pNode->m_pParent != nullptr){
        BinaryTreeNode* pCurrent = pNode;
        BinaryTreeNode* pParent = pNode->m_pParent;
        while(pParent != nullptr && pCurrent == pParent->m_pRight){
            pCurrent = pParent;
            pParent = pParent->m_pParent;
        }
        pNext = pParent;
    }
    return pNext;
}
```
思路：挺简单的，写的时候要严谨，注意不能有错误

### 9 两个栈实现队列 两个队列实现栈

### 10 计算斐波那切数列 跳台阶，铺砖 letcode 70
题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。
```
long long Fibonacci_Solution2(unsigned n)
{
    int result[2] = {0, 1};
    if(n < 2)
        return result[n];

    long long  fibNMinusOne = 1;
    long long  fibNMinusTwo = 0;
    long long  fibN = 0;
    for(unsigned int i = 2; i <= n; ++ i){
        fibN = fibNMinusOne + fibNMinusTwo;

        fibNMinusTwo = fibNMinusOne;
        fibNMinusOne = fibN;
    }

     return fibN;
}
// ====================方法3：基于矩阵乘法====================
#include <cassert>

struct Matrix2By2
{
    Matrix2By2
    (
        long long m00 = 0, 
        long long m01 = 0, 
        long long m10 = 0, 
        long long m11 = 0
    )
    :m_00(m00), m_01(m01), m_10(m10), m_11(m11) 
    {
    }

    long long m_00;
    long long m_01;
    long long m_10;
    long long m_11;
};

Matrix2By2 MatrixMultiply
(
    const Matrix2By2& matrix1, 
    const Matrix2By2& matrix2
)
{
    return Matrix2By2(
        matrix1.m_00 * matrix2.m_00 + matrix1.m_01 * matrix2.m_10,
        matrix1.m_00 * matrix2.m_01 + matrix1.m_01 * matrix2.m_11,
        matrix1.m_10 * matrix2.m_00 + matrix1.m_11 * matrix2.m_10,
        matrix1.m_10 * matrix2.m_01 + matrix1.m_11 * matrix2.m_11);
}

Matrix2By2 MatrixPower(unsigned int n)
{
    assert(n > 0);

    Matrix2By2 matrix;
    if(n == 1)
    {
        matrix = Matrix2By2(1, 1, 1, 0);
    }
    else if(n % 2 == 0)
    {
        matrix = MatrixPower(n / 2);
        matrix = MatrixMultiply(matrix, matrix);
    }
    else if(n % 2 == 1)
    {
        matrix = MatrixPower((n - 1) / 2);
        matrix = MatrixMultiply(matrix, matrix);
        matrix = MatrixMultiply(matrix, Matrix2By2(1, 1, 1, 0));
    }

    return matrix;
}

long long Fibonacci_Solution3(unsigned int n)
{
    int result[2] = {0, 1};
    if(n < 2)
        return result[n];

    Matrix2By2 PowerNMinus2 = MatrixPower(n - 1);
    return PowerNMinus2.m_00;
}
```
思路：递归，或者循环用动规；或者很骚的矩阵的方法，因为用矩阵可以实现二分，所以更快！！！！；

### 11 旋转数组的最小数字
题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
{3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。
```
```

### 12 矩阵中的路径
题目：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有
字符的路径。路径可以从矩阵中任意一格开始，每一步可以在矩阵中向左、右、
上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入
该格子。例如在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字
母用下划线标出）。但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个
字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
// A B T G
// C F C S
// J D E H
```
bool hasPath(const char* matrix, int rows, int cols, const char* str)
{
    if(matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
        return false;

    bool *visited = new bool[rows * cols];
    memset(visited, 0, rows * cols);

    int pathLength = 0;
    for(int row = 0; row < rows; ++row){
        for(int col = 0; col < cols; ++col){
            if(hasPathCore(matrix, rows, cols, row, col, str,
                pathLength, visited)){
                return true;
            }
        }
    }

    delete[] visited;

    return false;
}

bool hasPathCore(const char* matrix, int rows, int cols, int row,
    int col, const char* str, int& pathLength, bool* visited)
{
    if(str[pathLength] == '\0')
        return true;

    bool hasPath = false;
    if(row >= 0 && row < rows && col >= 0 && col < cols
        && matrix[row * cols + col] == str[pathLength]
        && !visited[row * cols + col]){
        ++pathLength;
        visited[row * cols + col] = true;

        hasPath = hasPathCore(matrix, rows, cols, row, col - 1,
            str, pathLength, visited)
            || hasPathCore(matrix, rows, cols, row - 1, col,
                str, pathLength, visited)
            || hasPathCore(matrix, rows, cols, row, col + 1,
                str, pathLength, visited)
            || hasPathCore(matrix, rows, cols, row + 1, col,
                str, pathLength, visited);

        if(!hasPath){
            --pathLength;
            visited[row * cols + col] = false;
        }
    }

    return hasPath;
}
```
思路：就普通的回溯，一般回溯先试探，试探失败就要返回之前的状态，对于这种格子的，一般用一个visit数组表示是否访问过；

### 13 机器人的运动范围
题目：地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，它
每一次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和
大于k的格子。例如，当k为18时，机器人能够进入方格(35, 37)，因为3+5+3+7=18。
但它不能进入方格(35, 38)，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
```
int movingCount(int threshold, int rows, int cols)
{
    if(threshold < 0 || rows <= 0 || cols <= 0)
        return 0;

    bool *visited = new bool[rows * cols];
    for(int i = 0; i < rows * cols; ++i)
        visited[i] = false;

    int count = movingCountCore(threshold, rows, cols, 0, 0, visited);

    delete[] visited;
    return count;
}

int movingCountCore(int threshold, int rows, int cols, int row,
    int col, bool* visited)
{
    int count = 0;
    if(check(threshold, rows, cols, row, col, visited)){
        visited[row * cols + col] = true;

        count = 1 + movingCountCore(threshold, rows, cols,
            row - 1, col, visited)
            + movingCountCore(threshold, rows, cols,
                row, col - 1, visited)
            + movingCountCore(threshold, rows, cols,
                row + 1, col, visited)
            + movingCountCore(threshold, rows, cols,
                row, col + 1, visited);
    }
    return count;
}

bool check(int threshold, int rows, int cols, int row, int col,
    bool* visited)
{
    if(row >= 0 && row < rows && col >= 0 && col < cols
        && getDigitSum(row) + getDigitSum(col) <= threshold
        && !visited[row* cols + col])
        return true;
    return false;
}

int getDigitSum(int number)
{
    int sum = 0;
    while(number > 0){
        sum += number % 10;
        number /= 10;
    }
    return sum;
}
```
思路：和上一个题差不多；

### 14

### 15 二进制中1的个数
题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如
把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。

相关题目：判断数是否为2的整数次方；输入两个整数，计算需要改变多少位使这两个数相同；
```
int NumberOf1_Solution2(int n)
{
    int count = 0;
    while (n){
        ++count;
        n = (n - 1) & n;
    }
    return count;
}
```
思路：有符号数，右移在右边补上符号位，比如负数右移，在最右边补1；尽量用左右移表示乘除，效率高；将数与其减1做与运算；

### 16 数值的整数次方
题目：实现函数double Power(double base, int exponent)，求base的exponent
次方。不得使用库函数，同时不需要考虑大数问题。
```
double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return base;

    double result = PowerWithUnsignedExponent(base, exponent >> 1);
    result *= result;
    if ((exponent & 0x1) == 1)
        result *= base;

    return result;
}
bool equal(double num1, double num2)
{
    if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
        return true;
    else
        return false;
}
double Power(double base, int exponent)
{
    g_InvalidInput = false;

    if (equal(base, 0.0) && exponent < 0)
    {
        g_InvalidInput = true;
        return 0.0;
    }

    unsigned int absExponent = (unsigned int) (exponent);
    if (exponent < 0)
        absExponent = (unsigned int) (-exponent);

    double result = PowerWithUnsignedExponent(base, absExponent);
    if (exponent < 0)
        result = 1.0 / result;

    return result;
}
//leetcode 简单AC答案 很快
double myPow(double x, int n) {
	if(n<0) return 1/x * myPow(1/x, -(n+1));
	if(n==0) return 1;
	if(n==2) return x*x;
	if(n%2==0) return myPow( myPow(x, n/2), 2);
	else return x*myPow( myPow(x, n/2), 2);
}
```
思路：写出来很简单，注意特殊情况：负指数，0指数，负指数情况也要考虑基数是0的情况；求次方O(logn)的方法也必须掌握！

### 17 打印1到最大的n位数
题目：输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则
打印出1、2、3一直到最大的3位数即999。
```
void Print1ToMaxOfNDigits_1(int n)
{
    if (n <= 0)
        return;

    char *number = new char[n + 1];
    memset(number, '0', n);
    number[n] = '\0';

    while (!Increment(number))
    {
        PrintNumber(number);
    }

    delete[]number;
}

// 字符串number表示一个数字，在 number上增加1
// 如果做加法溢出，则返回true；否则为false
bool Increment(char* number)
{
    bool isOverflow = false;
    int nTakeOver = 0;
    int nLength = strlen(number);

    for (int i = nLength - 1; i >= 0; i--)
    {
        int nSum = number[i] - '0' + nTakeOver;
        if (i == nLength - 1)
            nSum++;

        if (nSum >= 10)
        {
            if (i == 0)
                isOverflow = true;
            else
            {
                nSum -= 10;
                nTakeOver = 1;
                number[i] = '0' + nSum;
            }
        }
        else
        {
            number[i] = '0' + nSum;
            break;
        }
    }

    return isOverflow;
}

// ====================方法二====================
void Print1ToMaxOfNDigits_2(int n)
{
    if (n <= 0)
        return;

    char* number = new char[n + 1];
    number[n] = '\0';

    for (int i = 0; i < 10; ++i)
    {
        number[0] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number, n, 0);
    }

    delete[] number;
}

void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index)
{
    if (index == length - 1)
    {
        PrintNumber(number);
        return;
    }

    for (int i = 0; i < 10; ++i)
    {
        number[index + 1] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
    }
}
// ====================公共函数====================
// 字符串number表示一个数字，数字有若干个0开头
// 打印出这个数字，并忽略开头的0
void PrintNumber(char* number)
{
    bool isBeginning0 = true;
    int nLength = strlen(number);

    for (int i = 0; i < nLength; ++i)
    {
        if (isBeginning0 && number[i] != '0')
            isBeginning0 = false;

        if (!isBeginning0)
        {
            printf("%c", number[i]);
        }
    }

    printf("\t");
}
```
思路：也是注意很多坑，主要是大数问题，超过最大整数的可表示范围，最好用字符串来表示数字；第二种方法排列组合很巧妙了；

### 18.1 在O(1)时间删除链表结点
题目：给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间删除该结点。
```
void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
    if(!pListHead || !pToBeDeleted)
        return;

    // 要删除的结点不是尾结点
    if(pToBeDeleted->m_pNext != nullptr)
    {
        ListNode* pNext = pToBeDeleted->m_pNext;
        pToBeDeleted->m_nValue = pNext->m_nValue;
        pToBeDeleted->m_pNext = pNext->m_pNext;
 
        delete pNext;
        pNext = nullptr;
    }
    // 链表只有一个结点，删除头结点（也是尾结点）
    else if(*pListHead == pToBeDeleted)
    {
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
        *pListHead = nullptr;
    }
    // 链表中有多个结点，删除尾结点
    else
    {
        ListNode* pNode = *pListHead;
        while(pNode->m_pNext != pToBeDeleted)
        {
            pNode = pNode->m_pNext;            
        }
 
        pNode->m_pNext = nullptr;
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}
```
思路：用下一个节点复制到这个节点，然后删掉下一个节点，方法很妙；需要考虑删除节点是否为tail；

### 18.2 删除链表中重复的结点
题目：在一个排序的链表中，如何删除重复的结点？
```
void DeleteDuplication(ListNode** pHead)
{
    if(pHead == nullptr || *pHead == nullptr)
        return;

    ListNode* pPreNode = nullptr;
    ListNode* pNode = *pHead;
    while(pNode != nullptr)
    {
        ListNode *pNext = pNode->m_pNext;
        bool needDelete = false;
        if(pNext != nullptr && pNext->m_nValue == pNode->m_nValue)
            needDelete = true;

        if(!needDelete)
        {
            pPreNode = pNode;
            pNode = pNode->m_pNext;
        }
        else
        {
            int value = pNode->m_nValue;
            ListNode* pToBeDel = pNode;
            while(pToBeDel != nullptr && pToBeDel->m_nValue == value)
            {
                pNext = pToBeDel->m_pNext;

                delete pToBeDel;
                pToBeDel = nullptr;

                pToBeDel = pNext;
            }

            if(pPreNode == nullptr)
                *pHead = pNext;
            else
                pPreNode->m_pNext = pNext;
            pNode = pNext;
        }
    }
}
```
思路：要考虑删除投加点的情况；

### 19 正则表达式匹配 
题目：请实现一个函数用来匹配包含'.'和'*'的正则表达式。模式中的字符'.'
表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题
中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"
和"ab*ac*a"匹配，但与"aa.a"及"ab*a"均不匹配。
```
bool match(const char* str, const char* pattern)
{
    if(str == nullptr || pattern == nullptr)
        return false;

    return matchCore(str, pattern);
}

bool matchCore(const char* str, const char* pattern)
{
    if(*str == '\0' && *pattern == '\0')
        return true;

    if(*str != '\0' && *pattern == '\0')
        return false;

    if(*(pattern + 1) == '*')
    {
        if(*pattern == *str || (*pattern == '.' && *str != '\0'))
            // 进入有限状态机的下一个状态
            return matchCore(str + 1, pattern + 2)
            // 继续留在有限状态机的当前状态 
            || matchCore(str + 1, pattern)
            // 略过一个'*' 
            || matchCore(str, pattern + 2);
        else
            // 略过一个'*'
            return matchCore(str, pattern + 2);
    }

    if(*str == *pattern || (*pattern == '.' && *str != '\0'))
        return matchCore(str + 1, pattern + 1);

    return false;
}
//dp的方法：
bool isMatch(string s, string p) {
	int m = s.size(), n = p.size();
	vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
	dp[0][0] = true;
	for (int i = 0; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (p[j - 1] == '*') {
				dp[i][j] = dp[i][j - 2] || (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
			} else {
				dp[i][j] = i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
			}
		}
	}
	return dp[m][n];
}
```
思路：看了解析之后觉得还行，但是第一次来做的话，可能会忽略不少情况；

### 20 表示数值的字符串
题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，
字符串“+100”、“5e2”、“-123”、“3.1416”及“-1E-16”都表示数值，但“12e”、
“1a3.14”、“1.2.3”、“+-5”及“12e+5.4”都不是
```
// 数字的格式可以用A[.[B]][e|EC]或者.B[e|EC]表示，其中A和C都是
// 整数（可以有正负号，也可以没有），而B是一个无符号整数
bool isNumeric(const char* str)
{
    if(str == nullptr)
        return false;

    bool numeric = scanInteger(&str);

    // 如果出现'.'，接下来是数字的小数部分
    if(*str == '.'){
        ++str;

        // 下面一行代码用||的原因：
        // 1. 小数可以没有整数部分，例如.123等于0.123；
        // 2. 小数点后面可以没有数字，例如233.等于233.0；
        // 3. 当然小数点前面和后面可以有数字，例如233.666
        numeric = scanUnsignedInteger(&str) || numeric;
    }

    // 如果出现'e'或者'E'，接下来跟着的是数字的指数部分
    if(*str == 'e' || *str == 'E'){
        ++str;

        // 下面一行代码用&&的原因：
        // 1. 当e或E前面没有数字时，整个字符串不能表示数字，例如.e1、e1；
        // 2. 当e或E后面没有整数时，整个字符串不能表示数字，例如12e、12e+5.4
        numeric = numeric && scanInteger(&str);
    }

    return numeric && *str == '\0';
}

bool scanUnsignedInteger(const char** str)
{
    const char* before = *str;
    while(**str != '\0' && **str >= '0' && **str <= '9')
        ++(*str);

    // 当str中存在若干0-9的数字时，返回true
    return *str > before;
}

// 整数的格式可以用[+|-]B表示, 其中B为无符号整数
bool scanInteger(const char** str)
{
    if(**str == '+' || **str == '-')
        ++(*str);
    return scanUnsignedInteger(str);
}
```
思路：就是要考虑全面，情况比较多，代码逻辑思路以及各式都很好；

### 21 调整数组顺序使奇数位于偶数前面
题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有
奇数位于数组的前半部分，所有偶数位于数组的后半部分。
```
void ReorderOddEven_2(int *pData, unsigned int length){
    Reorder(pData, length, isEven);
}

void Reorder(int *pData, unsigned int length, bool (*func)(int)){
    if(pData == nullptr || length == 0)
        return;

    int *pBegin = pData;
    int *pEnd = pData + length - 1;

    while(pBegin < pEnd){
        // 向后移动pBegin
        while(pBegin < pEnd && !func(*pBegin))
            pBegin ++;

        // 向前移动pEnd
        while(pBegin < pEnd && func(*pEnd))
            pEnd --;

        if(pBegin < pEnd){
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }
}

bool isEven(int n){
    return (n & 1) == 0;
}
```
思路：这个问题的解法用双指针很好解决，但是将判断标准设置成函数指针的形式，需要get！！！！

### 22 链表中倒数第k个结点
题目：输入一个链表，输出该链表中倒数第k个结点。为了符合大多数人的习惯，
本题从1开始计数，即链表的尾结点是倒数第1个结点。例如一个链表有6个结点，
从头结点开始它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个结点是
值为4的结点。
```
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
    if(pListHead == nullptr || k == 0)
        return nullptr;

    ListNode *pAhead = pListHead;
    ListNode *pBehind = nullptr;
    for(unsigned int i = 0; i < k - 1; ++ i){
        if(pAhead->m_pNext != nullptr)
            pAhead = pAhead->m_pNext;
        else{
            return nullptr;
        }
    }
    pBehind = pListHead;
    while(pAhead->m_pNext != nullptr){
        pAhead = pAhead->m_pNext;
        pBehind = pBehind->m_pNext;
    }

    return pBehind;
}
```
思路：双指针，但是这题主要考虑鲁棒性，就是考虑一些特殊输入带来的特殊情况；k=0，k大于链表长度，输入空链表；

### 23 链表中环的入口结点
题目：一个链表中包含环，如何找出环的入口结点？例如，在图3.8的链表中，环的入口结点是结点3
```
ListNode *detectCycle(ListNode *head) {
	ListNode* slow(head);
	ListNode* fast(head);
	ListNode* meet(NULL);
	while(fast){
		slow = slow->next;
		fast = fast->next;
		if(fast){
			fast = fast->next;
		}
		if(fast == slow){
			meet = fast;
			break;
		}
	}
	if(meet){
		while(true){
			if(meet == head)
				return meet;
			meet = meet->next;
			head = head->next;
		}
	}
	return NULL;
}
```
思路：就快慢指针

### 24 反转链表
题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的头结点。
```
ListNode* ReverseList(ListNode* pHead)
{
    ListNode* pReversedHead = nullptr;
    ListNode* pNode = pHead;
    ListNode* pPrev = nullptr;
    while(pNode != nullptr){
        ListNode* pNext = pNode->m_pNext;

        if(pNext == nullptr)
            pReversedHead = pNode;

        pNode->m_pNext = pPrev;

        pPrev = pNode;
        pNode = pNext;
    }

    return pReversedHead;
}
```
思路：就用多个指针来操作；

### 25 合并两个排序的链表
题目：输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按
照递增排序的。例如输入图3.11中的链表1和链表2，则合并之后的升序链表如链
表3所示。
```
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    if(pHead1 == nullptr)
        return pHead2;
    else if(pHead2 == nullptr)
        return pHead1;

    ListNode* pMergedHead = nullptr;

    if(pHead1->m_nValue < pHead2->m_nValue){
        pMergedHead = pHead1;
        pMergedHead->m_pNext = Merge(pHead1->m_pNext, pHead2);
    }
    else{
        pMergedHead = pHead2;
        pMergedHead->m_pNext = Merge(pHead1, pHead2->m_pNext);
    }

    return pMergedHead;
}
```
思路：就是常规的链表题

### 26 树的子结构
题目：输入两棵二叉树A和B，判断B是不是A的子结构。
```
bool HasSubtree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
    bool result = false;
    if(pRoot1 != nullptr && pRoot2 != nullptr){
        if(Equal(pRoot1->m_dbValue, pRoot2->m_dbValue))
            result = DoesTree1HaveTree2(pRoot1, pRoot2);
        if(!result)
            result = HasSubtree(pRoot1->m_pLeft, pRoot2);
        if(!result)
            result = HasSubtree(pRoot1->m_pRight, pRoot2);
    }

    return result;
}

bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
    if(pRoot2 == nullptr)
        return true;
    if(pRoot1 == nullptr)
        return false;

    if(!Equal(pRoot1->m_dbValue, pRoot2->m_dbValue))
        return false;

    return DoesTree1HaveTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) &&
        DoesTree1HaveTree2(pRoot1->m_pRight, pRoot2->m_pRight);
}
bool Equal(double num1, double num2)
{
    if((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
        return true;
    else
        return false;
}
```
思路：第一次循环树的节点，然后对每个节点判断以该节点为根的树与第二颗树是否相同；判断相同也是用的递归；考虑空指针的情况，double不能直接==比较大小；

### 27 二叉树的镜像
题目：请完成一个函数，输入一个二叉树，该函数输出它的镜像。
```
void MirrorRecursively(BinaryTreeNode *pNode)
{
    if((pNode == nullptr) || (pNode->m_pLeft == nullptr && pNode->m_pRight))
        return;

    BinaryTreeNode *pTemp = pNode->m_pLeft;
    pNode->m_pLeft = pNode->m_pRight;
    pNode->m_pRight = pTemp;
    
    if(pNode->m_pLeft)
        MirrorRecursively(pNode->m_pLeft);  

    if(pNode->m_pRight)
        MirrorRecursively(pNode->m_pRight); 
}
void MirrorIteratively(BinaryTreeNode* pRoot)
{
    if(pRoot == nullptr)
        return;

    std::stack<BinaryTreeNode*> stackTreeNode;
    stackTreeNode.push(pRoot);

    while(stackTreeNode.size() > 0){
        BinaryTreeNode *pNode = stackTreeNode.top();
        stackTreeNode.pop();

        BinaryTreeNode *pTemp = pNode->m_pLeft;
        pNode->m_pLeft = pNode->m_pRight;
        pNode->m_pRight = pTemp;

        if(pNode->m_pLeft)
            stackTreeNode.push(pNode->m_pLeft);

        if(pNode->m_pRight)
            stackTreeNode.push(pNode->m_pRight);
    }
}
```
思路：就常规的左右调换 然后再递归调用；

### 28 对称的二叉树
题目：请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
```
bool isSymmetrical(BinaryTreeNode* pRoot)
{
    return isSymmetrical(pRoot, pRoot);
}
bool isSymmetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
    if(pRoot1 == nullptr && pRoot2 == nullptr)
        return true;

    if(pRoot1 == nullptr || pRoot2 == nullptr)
        return false;

    if(pRoot1->m_nValue != pRoot2->m_nValue)
        return false;

    return isSymmetrical(pRoot1->m_pLeft, pRoot2->m_pRight)
        && isSymmetrical(pRoot1->m_pRight, pRoot2->m_pLeft);
}
```
思路：就很常规，很上一题差不多；

### 29 顺时针打印矩阵
题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
```
void PrintMatrixClockwisely(int** numbers, int columns, int rows)
{
    if(numbers == nullptr || columns <= 0 || rows <= 0)
        return;

    int start = 0;

    while(columns > start * 2 && rows > start * 2)
    {
        PrintMatrixInCircle(numbers, columns, rows, start);

        ++start;
    }
}

void PrintMatrixInCircle(int** numbers, int columns, int rows, int start)
{
    int endX = columns - 1 - start;
    int endY = rows - 1 - start;

    // 从左到右打印一行
    for(int i = start; i <= endX; ++i){
        int number = numbers[start][i];
        printNumber(number);
    }

    // 从上到下打印一列
    if(start < endY){
        for(int i = start + 1; i <= endY; ++i){
            int number = numbers[i][endX];
            printNumber(number);
        }
    }

    // 从右到左打印一行
    if(start < endX && start < endY){
        for(int i = endX - 1; i >= start; --i){
            int number = numbers[endY][i];
            printNumber(number);
        }
    }

    // 从下到上打印一行
    if(start < endX && start < endY - 1){
        for(int i = endY - 1; i >= start + 1; --i){
            int number = numbers[i][start];
            printNumber(number);
        }
    }
}
void printNumber(int number)
{
    printf("%d\t", number);
}
```
思路：就是逻辑题，没啥数据结构与算法的东西；

### 30 包含min函数的栈
题目：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min函数。在该栈中，调用min、push及pop的时间复杂度都是O(1)。
思路：就用一个辅助栈来维护最小值；

### 31 栈的压入、弹出序列
题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是
否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1、2、3、4、
5是某栈的压栈序列，序列4、5、3、2、1是该压栈序列对应的一个弹出序列，但
4、3、5、1、2就不可能是该压栈序列的弹出序列。
```
bool IsPopOrder(const int* pPush, const int* pPop, int nLength)
{
    bool bPossible = false;

    if(pPush != nullptr && pPop != nullptr && nLength > 0){
        const int* pNextPush = pPush;
        const int* pNextPop = pPop;

        std::stack<int> stackData;

        while(pNextPop - pPop < nLength){
            // 当辅助栈的栈顶元素不是要弹出的元素
            // 先压入一些数字入栈
            while(stackData.empty() || stackData.top() != *pNextPop){
                // 如果所有数字都压入辅助栈了，退出循环
                if(pNextPush - pPush == nLength)
                    break;

                stackData.push(*pNextPush);

                pNextPush ++;
            }

            if(stackData.top() != *pNextPop)
                break;

            stackData.pop();
            pNextPop ++;
        }
        if(stackData.empty() && pNextPop - pPop == nLength)
            bPossible = true;
    }
    return bPossible;
}
//leetcode 更简单 少了很多条件判断 以及非法输入的判断 就看的很简单
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
	stack<int> temp;
	int j=0;
	for(int i=0; i<pushed.size(); i++){
		temp.push(pushed[i]);
		while(!temp.empty() && temp.top()==popped[j]){
			temp.pop();
			j++;
		}
	}
	return temp.empty();
}
```
思路：用一个辅助栈来模拟压入的过程，如果与弹出栈栈顶元素相同，就弹出，不同就压入元素；最后如果栈是非空，说明序列不合法；

### 32.1 不分行从上往下打印二叉树
题目：从上往下打印出二叉树的每个结点，同一层的结点按照从左到右的顺序打印。
```
void PrintFromTopToBottom(BinaryTreeNode* pRoot)
{
    if(pRoot == nullptr)
        return;

    std::deque<BinaryTreeNode *> dequeTreeNode;
    dequeTreeNode.push_back(pRoot);
    while(dequeTreeNode.size()){
        BinaryTreeNode *pNode = dequeTreeNode.front();
        dequeTreeNode.pop_front();

        printf("%d ", pNode->m_nValue);

        if(pNode->m_pLeft)
            dequeTreeNode.push_back(pNode->m_pLeft);

        if(pNode->m_pRight)
            dequeTreeNode.push_back(pNode->m_pRight);
    }
}
```
思路：就是用一个辅助队列来实现；挺简单的

### 32.2 分行从上到下打印二叉树
题目：从上到下按层打印二叉树，同一层的结点按从左到右的顺序打印，每一层打印到一行。
```
void Print(BinaryTreeNode* pRoot)
{
    if(pRoot == nullptr)
        return;

    std::queue<BinaryTreeNode*> nodes;
    nodes.push(pRoot);
    int nextLevel = 0;
    int toBePrinted = 1;
    while(!nodes.empty()){
        BinaryTreeNode* pNode = nodes.front();
        printf("%d ", pNode->m_nValue);

        if(pNode->m_pLeft != nullptr){
            nodes.push(pNode->m_pLeft);
            ++nextLevel;
        }
        if(pNode->m_pRight != nullptr){
            nodes.push(pNode->m_pRight);
            ++nextLevel;
        }

        nodes.pop();
        --toBePrinted;
        if(toBePrinted == 0){
            printf("\n");
            toBePrinted = nextLevel;
            nextLevel = 0;
        }
    }
}
```
思路：自己做的话就用两个栈，一个作为辅助；

### 32.3 之字形打印二叉树
题目：请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。
```
void Print(BinaryTreeNode* pRoot)
{
    if(pRoot == nullptr)
        return;

    std::stack<BinaryTreeNode*> levels[2];
    int current = 0;
    int next = 1;

    levels[current].push(pRoot);
    while(!levels[0].empty() || !levels[1].empty()){
        BinaryTreeNode* pNode = levels[current].top();
        levels[current].pop();

        printf("%d ", pNode->m_nValue);

        if(current == 0){
            if(pNode->m_pLeft != nullptr)
                levels[next].push(pNode->m_pLeft);
            if(pNode->m_pRight != nullptr)
                levels[next].push(pNode->m_pRight);
        }
        else{
            if(pNode->m_pRight != nullptr)
                levels[next].push(pNode->m_pRight);
            if(pNode->m_pLeft != nullptr)
                levels[next].push(pNode->m_pLeft);
        }

        if(levels[current].empty()){
            printf("\n");
            current = 1 - current;
            next = 1 - next;
        }
    }
}
//leetcode 代码 感觉比较好理解 有点妙
vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    if (root == NULL) {
        return vector<vector<int> > ();
    }
    vector<vector<int> > result;

    queue<TreeNode*> nodesQueue;
    nodesQueue.push(root);
    bool leftToRight = true;

    while ( !nodesQueue.empty()) {
        int size = nodesQueue.size();
        vector<int> row(size);
        for (int i = 0; i < size; i++) {
            TreeNode* node = nodesQueue.front();
            nodesQueue.pop();

            // find position to fill node's value
            int index = (leftToRight) ? i : (size - 1 - i);

            row[index] = node->val;
            if (node->left) {
                nodesQueue.push(node->left);
            }
            if (node->right) {
                nodesQueue.push(node->right);
            }
        }
        // after this level
        leftToRight = !leftToRight;
        result.push_back(row);
    }
    return result;
}
```
思路：就用辅助栈，然后再来一个变量控制一下奇偶层，奇层从左向右，偶层从右向左这样的；

### 33 二叉搜索树的后序遍历序列
题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则返回true，否则返回false。假设输入的数组的任意两个数字都互不相同。
```
// BST：Binary Search Tree，二叉搜索树
bool VerifySquenceOfBST(int sequence[], int length)
{
    if(sequence == nullptr || length <= 0)
        return false;

    int root = sequence[length - 1];

    // 在二叉搜索树中左子树的结点小于根结点
    int i = 0;
    for(; i < length - 1; ++ i){
        if(sequence[i] > root)
            break;
    }

    // 在二叉搜索树中右子树的结点大于根结点
    int j = i;
    for(; j < length - 1; ++ j){
        if(sequence[j] < root)
            return false;
    }

    // 判断左子树是不是二叉搜索树
    bool left = true;
    if(i > 0)
        left = VerifySquenceOfBST(sequence, i);

    // 判断右子树是不是二叉搜索树
    bool right = true;
    if(i < length - 1)
        right = VerifySquenceOfBST(sequence + i, length - i - 1);

    return (left && right);
}
```
思路：就利用二叉搜索树的性质，开始以为给的是树的结构，所以觉得挺简单的，其实输入是一个数组，不过也还是挺简单的；

### 34 二叉树中和为某一值的路径
题目：输入一棵二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
```
void FindPath(BinaryTreeNode* pRoot, int expectedSum)
{
    if(pRoot == nullptr)
        return;

    std::vector<int> path;
    int currentSum = 0;
    FindPath(pRoot, expectedSum, path, currentSum);
}
void FindPath
(
    BinaryTreeNode*   pRoot,        
    int               expectedSum,  
    std::vector<int>& path,         
    int&              currentSum
)
{
    currentSum += pRoot->m_nValue;
    path.push_back(pRoot->m_nValue);

    // 如果是叶结点，并且路径上结点的和等于输入的值
    // 打印出这条路径
    bool isLeaf = pRoot->m_pLeft == nullptr && pRoot->m_pRight == nullptr;
    if(currentSum == expectedSum && isLeaf){
        printf("A path is found: ");
        std::vector<int>::iterator iter = path.begin();
        for(; iter != path.end(); ++ iter)
            printf("%d\t", *iter);
        
        printf("\n");
    }

    // 如果不是叶结点，则遍历它的子结点
    if(pRoot->m_pLeft != nullptr)
        FindPath(pRoot->m_pLeft, expectedSum, path, currentSum);
    if(pRoot->m_pRight != nullptr)
        FindPath(pRoot->m_pRight, expectedSum, path, currentSum);

    // 在返回到父结点之前，在路径上删除当前结点，
    // 并在currentSum中减去当前结点的值
    currentSum -= pRoot->m_nValue;
    path.pop_back();
} 
```
思路：就有点回溯的思想在里面，挺简单的；

### 35 复杂链表的复制
题目：请实现函数ComplexListNode* Clone(ComplexListNode* pHead)，复
制一个复杂链表。在复杂链表中，每个结点除了有一个m_pNext指针指向下一个
结点外，还有一个m_pSibling 指向链表中的任意结点或者nullptr。
```
ComplexListNode* Clone(ComplexListNode* pHead)
{
    CloneNodes(pHead);
    ConnectSiblingNodes(pHead);
    return ReconnectNodes(pHead);
}
void CloneNodes(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while(pNode != nullptr){
        ComplexListNode* pCloned = new ComplexListNode();
        pCloned->m_nValue = pNode->m_nValue;
        pCloned->m_pNext = pNode->m_pNext;
        pCloned->m_pSibling = nullptr;
 
        pNode->m_pNext = pCloned;
        pNode = pCloned->m_pNext;
    }
}
void ConnectSiblingNodes(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while(pNode != nullptr){
        ComplexListNode* pCloned = pNode->m_pNext;
        if(pNode->m_pSibling != nullptr){
            pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
        }
        pNode = pCloned->m_pNext;
    }
}
ComplexListNode* ReconnectNodes(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    ComplexListNode* pClonedHead = nullptr;
    ComplexListNode* pClonedNode = nullptr;
 
    if(pNode != nullptr){
        pClonedHead = pClonedNode = pNode->m_pNext;
        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }
 
    while(pNode != nullptr){
        pClonedNode->m_pNext = pNode->m_pNext;
        pClonedNode = pClonedNode->m_pNext;
 
        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }
    return pClonedHead;
} 
```
思路：用hash map映射原始节点与新对应节点的关系，空间复杂度有点高；方法是在原始链表后面插入新构造的链表，最后偶数位置的链表就组成了新的复制链表；

### 36 二叉搜索树与双向链表
题目：输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
```
BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree)
{
    BinaryTreeNode *pLastNodeInList = nullptr;
    ConvertNode(pRootOfTree, &pLastNodeInList);

    // pLastNodeInList指向双向链表的尾结点，
    // 我们需要返回头结点
    BinaryTreeNode *pHeadOfList = pLastNodeInList;
    while(pHeadOfList != nullptr && pHeadOfList->m_pLeft != nullptr)
        pHeadOfList = pHeadOfList->m_pLeft;
    return pHeadOfList;
}
void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList)
{
    if(pNode == nullptr)
        return;

    BinaryTreeNode *pCurrent = pNode;
    if (pCurrent->m_pLeft != nullptr)
        ConvertNode(pCurrent->m_pLeft, pLastNodeInList);

    pCurrent->m_pLeft = *pLastNodeInList; 
    if(*pLastNodeInList != nullptr)
        (*pLastNodeInList)->m_pRight = pCurrent;

    *pLastNodeInList = pCurrent;

    if (pCurrent->m_pRight != nullptr)
        ConvertNode(pCurrent->m_pRight, pLastNodeInList);
}
```
思路：二叉搜索树中序遍历；整一个形参作为当前树的最大节点；

### 37 序列化二叉树
题目：请实现两个函数，分别用来序列化和反序列化二叉树。
```
void Serialize(const BinaryTreeNode* pRoot, ostream& stream)
{
    if(pRoot == nullptr){
        stream << "$,";
        return;
    }

    stream << pRoot->m_nValue << ',';
    Serialize(pRoot->m_pLeft, stream);
    Serialize(pRoot->m_pRight, stream);
}
bool ReadStream(istream& stream, int* number)
{
    if(stream.eof())
        return false;

    char buffer[32];
    buffer[0] = '\0';

    char ch;
    stream >> ch;
    int i = 0;
    while(!stream.eof() && ch != ','){
        buffer[i++] = ch;
        stream >> ch;
    }

    bool isNumeric = false;
    if(i > 0 && buffer[0] != '$'){
        *number = atoi(buffer);
        isNumeric = true;
    }

    return isNumeric;
}
void Deserialize(BinaryTreeNode** pRoot, istream& stream)
{
    int number;
    if(ReadStream(stream, &number)){
        *pRoot = new BinaryTreeNode();
        (*pRoot)->m_nValue = number;
        (*pRoot)->m_pLeft = nullptr;
        (*pRoot)->m_pRight = nullptr;

        Deserialize(&((*pRoot)->m_pLeft), stream);
        Deserialize(&((*pRoot)->m_pRight), stream);
    }
}
```
思路：用前序遍历来序列化二叉树，节点数值用‘，’隔开，空节点用特殊字符来表示；注意如果是序列化二叉搜索树，就不需要对空节点序列化，这是区别！！！

### 38 字符串的排列
题目：输入一个字符串，打印出该字符串中字符的所有排列。例如输入字符串abc，则打印出由字符a、b、c所能排列出来的所有字符串abc、acb、bac、bca、cab和cba。
```
void Permutation(char* pStr)
{
    if(pStr == nullptr)
        return;
    Permutation(pStr, pStr);
}
void Permutation(char* pStr, char* pBegin)
{
    if(*pBegin == '\0'){
        printf("%s\n", pStr);
    }
    else{
        for(char* pCh = pBegin; *pCh != '\0'; ++ pCh){
            char temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;

            Permutation(pStr, pBegin + 1);

            temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;
        }
    }
}
```
思路：这种排列组合的问题就用回溯来做；

### 39 数组中出现次数超过一半的数字
题目：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例
如输入一个长度为9的数组{1, 2, 3, 2, 2, 2, 5, 4, 2}。由于数字2在数组中
出现了5次，超过数组长度的一半，因此输出2。
```
//方法一分治
int MoreThanHalfNum_Solution1(int* numbers, int length)
{
    if(CheckInvalidArray(numbers, length))
        return 0;
 
    int middle = length >> 1;
    int start = 0;
    int end = length - 1;
    int index = Partition(numbers, length, start, end);
    while(index != middle){
        if(index > middle){
            end = index - 1;
            index = Partition(numbers, length, start, end);
        }
        else{
            start = index + 1;
            index = Partition(numbers, length, start, end);
        }
    }
 
    int result = numbers[middle];
    if(!CheckMoreThanHalf(numbers, length, result))
        result = 0;

    return result;
}

// ====================方法2====================
int MoreThanHalfNum_Solution2(int* numbers, int length)
{
    if(CheckInvalidArray(numbers, length))
        return 0;
 
    int result = numbers[0];
    int times = 1;
    for(int i = 1; i < length; ++i){
        if(times == 0){
            result = numbers[i];
            times = 1;
        }
        else if(numbers[i] == result)
            times++;
        else
            times--;
    }
 
    if(!CheckMoreThanHalf(numbers, length, result))
        result = 0;
 
    return result;
}
```
思路：方法一就是分治，用快排的思想，找一个基数，并找基数的位置，如果位置在n/2处，就是中位数，出现最多次数的数；方法二就比较适合特定的情况，mark；

### 40 最小的k个数
题目：输入n个整数，找出其中最小的k个数。例如输入4、5、1、6、2、7、3、8
这8个数字，则最小的4个数字是1、2、3、4。
```
// ====================方法1====================
void GetLeastNumbers_Solution1(int* input, int n, int* output, int k)
{
    if(input == nullptr || output == nullptr || k > n || n <= 0 || k <= 0)
        return;

    int start = 0;
    int end = n - 1;
    int index = Partition(input, n, start, end);
    while(index != k - 1){
        if(index > k - 1){
            end = index - 1;
            index = Partition(input, n, start, end);
        }
        else{
            start = index + 1;
            index = Partition(input, n, start, end);
        }
    }

    for(int i = 0; i < k; ++i)
        output[i] = input[i];
}

// ====================方法2====================
typedef multiset<int, std::greater<int> >            intSet;
typedef multiset<int, std::greater<int> >::iterator  setIterator;
void GetLeastNumbers_Solution2(const vector<int>& data, intSet& leastNumbers, int k)
{
    leastNumbers.clear();

    if(k < 1 || data.size() < k)
        return;

    vector<int>::const_iterator iter = data.begin();
    for(; iter != data.end(); ++ iter){
        if((leastNumbers.size()) < k)
            leastNumbers.insert(*iter);

        else{
            setIterator iterGreatest = leastNumbers.begin();

            if(*iter < *(leastNumbers.begin())){
                leastNumbers.erase(iterGreatest);
                leastNumbers.insert(*iter);
            }
        }
    }
}
```
思路：方案一就是分治的思想，找到第k个数；方法二用最大堆，或者红黑树的数据结构；方法一更快，但是要修改输入数组，方法二虽然慢，但是适合k小，n大的情况；

### 41 数据流中的中位数
题目：如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么
中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，
那么中位数就是所有数值排序之后中间两个数的平均值。
```
template<typename T> class DynamicArray
{
public:
    void Insert(T num)
    {
        if(((min.size() + max.size()) & 1) == 0){
            if(max.size() > 0 && num < max[0]){
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<T>());

                num = max[0];

                pop_heap(max.begin(), max.end(), less<T>());
                max.pop_back();
            }

            min.push_back(num);
            push_heap(min.begin(), min.end(), greater<T>());
        }
        else{
            if(min.size() > 0 && min[0] < num){
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<T>());

                num = min[0];

                pop_heap(min.begin(), min.end(), greater<T>());
                min.pop_back();
            }

            max.push_back(num);
            push_heap(max.begin(), max.end(), less<T>());
        }
    }

    T GetMedian()
    {
        int size = min.size() + max.size();
        if(size == 0)
            throw exception("No numbers are available");

        T median = 0;
        if((size & 1) == 1)
            median = min[0];
        else
            median = (min[0] + max[0]) / 2;

        return median;
    }

private:
    vector<T> min;
    vector<T> max;
};
```
思路：维护一个最大堆和最小堆，数据量保持平衡，中位数就是最大堆的最大值与最小堆的最小值的平均值，或者中间值；

### 42 连续子数组的最大和
题目：输入一个整型数组，数组里有正数也有负数。数组中一个或连续的多个整
数组成一个子数组。求所有子数组的和的最大值。要求时间复杂度为O(n)。
```
bool g_InvalidInput = false;
int FindGreatestSumOfSubArray(int *pData, int nLength)
{
    if((pData == nullptr) || (nLength <= 0)){
        g_InvalidInput = true;
        return 0;
    }

    g_InvalidInput = false;

    int nCurSum = 0;
    int nGreatestSum = 0x80000000;
    for(int i = 0; i < nLength; ++i){
        if(nCurSum <= 0)
            nCurSum = pData[i];
        else
            nCurSum += pData[i];

        if(nCurSum > nGreatestSum)
            nGreatestSum = nCurSum;
    }

    return nGreatestSum;
} 
```
思路：动态规划的思想，还算行？

### 43 从1到n整数中1出现的次数
题目：输入一个整数n，求从1到n这n个整数的十进制表示中1出现的次数。例如
输入12，从1到12这些整数中包含1 的数字有1，10，11和12，1一共出现了5次。
```
// ====================方法一====================
int NumberOf1Between1AndN_Solution1(unsigned int n)
{
    int number = 0;

    for(unsigned int i = 1; i <= n; ++ i)
        number += NumberOf1(i);

    return number;
}

int NumberOf1(unsigned int n)
{
    int number = 0;
    while(n)
    {
        if(n % 10 == 1)
            number ++;

        n = n / 10;
    }

    return number;
}

// ====================方法二====================
int NumberOf1Between1AndN_Solution2(int n)
{
    if(n <= 0)
        return 0;

    char strN[50];
    sprintf(strN, "%d", n);

    return NumberOf1(strN);
}

int NumberOf1(const char* strN)
{
    if(!strN || *strN < '0' || *strN > '9' || *strN == '\0')
        return 0;

    int first = *strN - '0';
    unsigned int length = static_cast<unsigned int>(strlen(strN));

    if(length == 1 && first == 0)
        return 0;

    if(length == 1 && first > 0)
        return 1;

    // 假设strN是"21345"
    // numFirstDigit是数字10000-19999的第一个位中1的数目
    int numFirstDigit = 0;
    if(first > 1)
        numFirstDigit = PowerBase10(length - 1);
    else if(first == 1)
        numFirstDigit = atoi(strN + 1) + 1;

    // numOtherDigits是01346-21345除了第一位之外的数位中1的数目
    int numOtherDigits = first * (length - 1) * PowerBase10(length - 2);
    // numRecursive是1-1345中1的数目
    int numRecursive = NumberOf1(strN + 1);

    return numFirstDigit + numOtherDigits + numRecursive;
}
```
思路：方法一就是暴力；方法二有点东西，可以再看看；

### 44 数字序列中某一位的数字
题目：数字以0123456789101112131415…的格式序列化到一个字符序列中。在这
个序列中，第5位（从0开始计数）是5，第13位是1，第19位是4，等等。请写一个函数求任意位对应的数字。
```
int digitAtIndex(int index)
{
	if(index < 0)
		return -1;

	int digits = 1;
	while(true)
	{
		int numbers = countOfIntegers(digits);
		if(index < numbers * digits)
			return digitAtIndex(index, digits);

		index -= digits * numbers;
		digits++;
	}

	return -1;
}

int countOfIntegers(int digits)
{
	if(digits == 1)
		return 10;

	int count = (int) std::pow(10, digits - 1);
	return 9 * count;
}

int digitAtIndex(int index, int digits)
{
	int number = beginNumber(digits) + index / digits;
	int indexFromRight = digits - index % digits;
	for(int i = 1; i < indexFromRight; ++i)
		number /= 10;
	return number % 10;
}

int beginNumber(int digits)
{
	if(digits == 1)
		return 0;

	return (int) std::pow(10, digits - 1);
}
```
思路：按照位数计算个数，然后比较多出来的数，很快就完成了；

### 45 把数组排成最小的数
题目：输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼
接出的所有数字中最小的一个。例如输入数组{3, 32, 321}，则打印出这3个数
字能排成的最小数字321323。
```
string largestNumber(vector<int> &num) {
	vector<string> arr;
	bool flag(false);
	for(auto i:num){
		if(i)
			flag = true;
		arr.push_back(to_string(i));
	}
	if(!flag)
		return "0";
	sort(begin(arr), end(arr), [](string &s1, string &s2){ return s1+s2>s2+s1; });
	string res;
	for(auto s:arr)
		res+=s;
	return  res;
}
```
思路：这个比较排序的方法很妙了啊；

### 46 把数字翻译成字符串
题目：给定一个数字，我们按照如下规则把它翻译为字符串：0翻译成"a"，1翻
译成"b"，……，11翻译成"l"，……，25翻译成"z"。一个数字可能有多个翻译。例
如12258有5种不同的翻译，它们分别是"bccfi"、"bwfi"、"bczi"、"mcfi"和
"mzi"。请编程实现一个函数用来计算一个数字有多少种不同的翻译方法。
```
int GetTranslationCount(int number)
{
    if(number < 0)
        return 0;

    string numberInString = to_string(number);
    return GetTranslationCount(numberInString);
}

int GetTranslationCount(const string& number)
{
    int length = number.length();
    int* counts = new int[length];
    int count = 0;

    for(int i = length - 1; i >= 0; --i){
        count = 0;
         if(i < length - 1)
               count = counts[i + 1];
         else
               count = 1;

        if(i < length - 1){
            int digit1 = number[i] - '0';
            int digit2 = number[i + 1] - '0';
            int converted = digit1 * 10 + digit2;
            if(converted >= 10 && converted <= 25){
                if(i < length - 2)
                    count += counts[i + 2];
                else
                    count += 1;
            }
        }

        counts[i] = count;
    }

    count = counts[0];
    delete[] counts;

    return count;
}
```
思路：就是动态规划的想法；

### 47 礼物的最大价值
题目：在一个m×n的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值
 （价值大于0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向左或
者向下移动一格直到到达棋盘的右下角。给定一个棋盘及其上面的礼物，请计
算你最多能拿到多少价值的礼物？
```
int getMaxValue_solution2(const int* values, int rows, int cols)
{
    if(values == nullptr || rows <= 0 || cols <= 0)
        return 0;

    int* maxValues = new int[cols];
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            int left = 0;
            int up = 0;

            if(i > 0)
                up = maxValues[j];

            if(j > 0)
                left = maxValues[j - 1];

            maxValues[j] = std::max(left, up) + values[i * cols + j];
        }
    }

    int maxValue = maxValues[cols - 1];
    delete[] maxValues;
    return maxValue;
}
```
思路：动态规划，计算路径和；

### 48 最长不含重复字符的子字符串
题目：请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子
字符串的长度。假设字符串中只包含从'a'到'z'的字符。
```
int lengthOfLongestSubstring(string s) {
	int used[128] = {-1};
	int start(-1);
	int length(0);
	for(int i=0; i<s.size(); i++){
		if(used[s[i]]>start){
			start = used[s[i]];
		}
		length = max(length, i-start);
		used[s[i]] = i;
	}
	return length;
}
```
思路：说是动态规划，其实用哈希表更合适；

### 49 丑数
题目：我们把只包含因子2、3和5的数称作丑数（Ugly Number）。求按从小到
大的顺序的第1500个丑数。例如6、8都是丑数，但14不是，因为它包含因子7。
习惯上我们把1当做第一个丑数。
```
int nthUglyNumber(int n) {
	vector<int> dp(n+1, 0);

	dp[1] = 1;
	int i2(1), i3(1), i5(1);
	for(int i=2; i<=n; i++){
		dp[i] = min(2*dp[i2], min(3*dp[i3], 5*dp[i5]));

		if(dp[i] == 2*dp[i2]) 
			i2++;
		if(dp[i] == 3*dp[i3]) 
			i3++;
		if(dp[i] == 5*dp[i5]) 
			i5++;
	}
	return dp[n];
}
```
思路：类似动态规划的思路，用哈希表记录；

### 50 字符串中第一个只出现一次的字符
题目：在字符串中找出第一个只出现一次的字符。如输入"abaccdeff"，则输出'b'。
```
char FirstNotRepeatingChar(const char* pString)
{
    if(pString == nullptr)
        return '\0';

    const int tableSize = 256;
    unsigned int hashTable[tableSize];
    for(unsigned int i = 0; i < tableSize; ++i)
        hashTable[i] = 0;

    const char* pHashKey = pString;
    while(*(pHashKey) != '\0')
        hashTable[*(pHashKey++)] ++;

    pHashKey = pString;
    while(*pHashKey != '\0'){
        if(hashTable[*pHashKey] == 1)
            return *pHashKey;

        pHashKey++;
    }
    return '\0';
}
```
思路：用哈希表两次遍历；

### 51 数组中的逆序对
题目：在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组
成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
```
int InversePairs(int* data, int length)
{
    if(data == nullptr || length < 0)
        return 0;

    int* copy = new int[length];
    for(int i = 0; i < length; ++i)
        copy[i] = data[i];

    int count = InversePairsCore(data, copy, 0, length - 1);
    delete[] copy;
    return count;
}
int InversePairsCore(int* data, int* copy, int start, int end)
{
    if(start == end) {
        copy[start] = data[start];
        return 0;
    }

    int length = (end - start) / 2;

    int left = InversePairsCore(copy, data, start, start + length);
    int right = InversePairsCore(copy, data, start + length + 1, end);

    // i初始化为前半段最后一个数字的下标
    int i = start + length;
    // j初始化为后半段最后一个数字的下标
    int j = end;
    int indexCopy = end;
    int count = 0;
    while(i >= start && j >= start + length + 1){
        if(data[i] > data[j]){
            copy[indexCopy--] = data[i--];
            count += j - start - length;
        }
        else{
            copy[indexCopy--] = data[j--];
        }
    }

    for(; i >= start; --i)
        copy[indexCopy--] = data[i];

    for(; j >= start + length + 1; --j)
        copy[indexCopy--] = data[j];

    return left + right + count;
}
```
思路：用归并的办法来做；

### 52 两个链表的第一个公共结点
题目：输入两个链表，找出它们的第一个公共结点。
```
ListNode* FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
{
    // 得到两个链表的长度
    unsigned int nLength1 = GetListLength(pHead1);
    unsigned int nLength2 = GetListLength(pHead2);
    int nLengthDif = nLength1 - nLength2;

    ListNode* pListHeadLong = pHead1;
    ListNode* pListHeadShort = pHead2;
    if(nLength2 > nLength1){
        pListHeadLong = pHead2;
        pListHeadShort = pHead1;
        nLengthDif = nLength2 - nLength1;
    }

    // 先在长链表上走几步，再同时在两个链表上遍历
    for(int i = 0; i < nLengthDif; ++i)
        pListHeadLong = pListHeadLong->m_pNext;

    while((pListHeadLong != nullptr) &&
        (pListHeadShort != nullptr) &&
        (pListHeadLong != pListHeadShort)){
        pListHeadLong = pListHeadLong->m_pNext;
        pListHeadShort = pListHeadShort->m_pNext;
    }

    // 得到第一个公共结点
    ListNode* pFisrtCommonNode = pListHeadLong;
    return pFisrtCommonNode;
}

unsigned int GetListLength(ListNode* pHead)
{
    unsigned int nLength = 0;
    ListNode* pNode = pHead;
    while(pNode != nullptr){
        ++nLength;
        pNode = pNode->m_pNext;
    }
    return nLength;
}
```
思路：公共祖先，就是从头走到尾，再从另一个头走到尾，然后第二次会走到相同的位置；

### 53.1 数字在排序数组中出现的次数
题目：统计一个数字在排序数组中出现的次数。例如输入排序数组{1, 2, 3, 3,
3, 3, 4, 5}和数字3，由于3在这个数组中出现了4次，因此输出4。
```
int GetNumberOfK(const int* data, int length, int k)
{
    int number = 0;

    if(data != nullptr && length > 0){
        int first = GetFirstK(data, length, k, 0, length - 1);
        int last = GetLastK(data, length, k, 0, length - 1);
        
        if(first > -1 && last > -1)
            number = last - first + 1;
    }

    return number;
}
// 找到数组中第一个k的下标。如果数组中不存在k，返回-1
int GetFirstK(const int* data, int length, int k, int start, int end)
{
    if(start > end)
        return -1;

    int middleIndex = (start + end) / 2;
    int middleData = data[middleIndex];

    if(middleData == k){
        if((middleIndex > 0 && data[middleIndex - 1] != k) 
            || middleIndex == 0)
            return middleIndex;
        else
            end  = middleIndex - 1;
    }
    else if(middleData > k)
        end = middleIndex - 1;
    else
        start = middleIndex + 1;

    return GetFirstK(data, length, k, start, end);
}
// 找到数组中最后一个k的下标。如果数组中不存在k，返回-1
int GetLastK(const int* data, int length, int k, int start, int end)
{
    if(start > end)
        return -1;

    int middleIndex = (start + end) / 2;
    int middleData = data[middleIndex];

    if(middleData == k){
        if((middleIndex < length - 1 && data[middleIndex + 1] != k) 
            || middleIndex == length - 1)
            return middleIndex;
        else
            start  = middleIndex + 1;
    }
    else if(middleData < k)
        start = middleIndex + 1;
    else
        end = middleIndex - 1;

    return GetLastK(data, length, k, start, end);
}
```
思路：递增数组，求指定数出现的次数：就两次循环，第一次找最左边的数，第二次找最右边的数，然后求差；

### 53.2 0到n-1中缺失的数字
题目：一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字
都在范围0到n-1之内。在范围0到n-1的n个数字中有且只有一个数字不在该数组
中，请找出这个数字。
```
int GetMissingNumber(const int* numbers, int length)
{
    if(numbers == nullptr || length <= 0)
        return -1;

    int left = 0;
    int right = length - 1;
    while(left <= right){
        int middle = (right + left) >> 1;
        if(numbers[middle] != middle){
            if(middle == 0 || numbers[middle - 1] == middle - 1)
                return middle;
            right = middle - 1;
        }
        else
            left = middle + 1;
    }

    if(left == length)
        return length;

    // 无效的输入，比如数组不是按要求排序的，
    // 或者有数字不在0到n-1范围之内
    return -1;
}
```
思路：用二分查找，如果数和下标一样，就查找右边，否则查找左边；

### 53.3 数组中数值和下标相等的元素
题目：假设一个单调递增的数组里的每个元素都是整数并且是唯一的。请编程实
现一个函数找出数组中任意一个数值等于其下标的元素。例如，在数组{-3, -1, 1, 3, 5}中，数字3和它的下标相等。
```
int GetNumberSameAsIndex(const int* numbers, int length)
{
    if(numbers == nullptr || length <= 0)
        return -1;

    int left = 0;
    int right = length - 1;
    while(left <= right){
        int middle = left + ((right - left) >> 1);
        if(numbers[middle] == middle)
            return middle;

        if(numbers[middle] > middle)
            right = middle - 1;
        else
            left = middle + 1;
    }
    return -1;
}
```
思路：就类似二分查找，如果m大于下标，那么右边都大于下标；同理如果m小于下标，那么左边的数都小于下标；所以可以用二分；

### 54 二叉搜索树的第k个结点
题目：给定一棵二叉搜索树，请找出其中的第k大的结点。
```
const BinaryTreeNode* KthNode(const BinaryTreeNode* pRoot, unsigned int k)
{
    if(pRoot == nullptr || k == 0)
        return nullptr;

    return KthNodeCore(pRoot, k);
}
const BinaryTreeNode* KthNodeCore(const BinaryTreeNode* pRoot, unsigned int& k)
{
    const BinaryTreeNode* target = nullptr;

    if(pRoot->m_pLeft != nullptr)
        target = KthNodeCore(pRoot->m_pLeft, k);

    if(target == nullptr){
        if(k == 1)
            target = pRoot;

        k--;
    }

    if(target == nullptr && pRoot->m_pRight != nullptr)
        target = KthNodeCore(pRoot->m_pRight, k);

    return target;
}
```
思路：就二叉搜索树的中序遍历；

### 55.1 二叉树的深度
题目：输入一棵二叉树的根结点，求该树的深度。从根结点到叶结点依次经过的
结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
```
int TreeDepth(const BinaryTreeNode* pRoot)
{
    if(pRoot == nullptr)
        return 0;

    int nLeft = TreeDepth(pRoot->m_pLeft);
    int nRight = TreeDepth(pRoot->m_pRight);

    return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}
```
思路：就常规的求树的深度；

### 55.2 平衡二叉树
题目：输入一棵二叉树的根结点，判断该树是不是平衡二叉树。如果某二叉树中
任意结点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
```
// ====================方法1====================
int TreeDepth(const BinaryTreeNode* pRoot)
{
    if(pRoot == nullptr)
        return 0;

    int nLeft = TreeDepth(pRoot->m_pLeft);
    int nRight = TreeDepth(pRoot->m_pRight);

    return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}

bool IsBalanced_Solution1(const BinaryTreeNode* pRoot)
{
    if(pRoot == nullptr)
        return true;

    int left = TreeDepth(pRoot->m_pLeft);
    int right = TreeDepth(pRoot->m_pRight);
    int diff = left - right;
    if(diff > 1 || diff < -1)
        return false;

    return IsBalanced_Solution1(pRoot->m_pLeft) 
        && IsBalanced_Solution1(pRoot->m_pRight);
}

// ====================方法2====================
bool IsBalanced(const BinaryTreeNode* pRoot, int* pDepth);

bool IsBalanced_Solution2(const BinaryTreeNode* pRoot)
{
    int depth = 0;
    return IsBalanced(pRoot, &depth);
}

bool IsBalanced(const BinaryTreeNode* pRoot, int* pDepth)
{
    if(pRoot == nullptr){
        *pDepth = 0;
        return true;
    }

    int left, right;
    if(IsBalanced(pRoot->m_pLeft, &left) 
        && IsBalanced(pRoot->m_pRight, &right)){
        int diff = left - right;
        if(diff <= 1 && diff >= -1){
            *pDepth = 1 + (left > right ? left : right);
            return true;
        }
    }

    return false;
}
```
思路：就是第一问的升级版；

### 56.1 数组中只出现一次的两个数字
题目：一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序
找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
```
void FindNumsAppearOnce(int data[], int length, int* num1, int* num2)
{
    if(data == nullptr || length < 2)
        return;

    int resultExclusiveOR = 0;
    for(int i = 0; i < length; ++i)
        resultExclusiveOR ^= data[i];

    unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);

    *num1 = *num2 = 0;
    for(int j = 0; j < length; ++j){
        if(IsBit1(data[j], indexOf1))
            *num1 ^= data[j];
        else
            *num2 ^= data[j];
    }
}
// 找到num从右边数起第一个是1的位
unsigned int FindFirstBitIs1(int num)
{
    int indexBit = 0;
    while(((num & 1) == 0) && (indexBit < 8 * sizeof(int))){
        num = num >> 1;
        ++indexBit;
    }
    return indexBit;
}
// 判断数字num的第indexBit位是不是1
bool IsBit1(int num, unsigned int indexBit)
{
    num = num >> indexBit;
    return (num & 1);
}
```
思路：面试很容易出现的问题，异或分组；

### 56.2 数组中唯一只出现一次的数字
题目：在一个数组中除了一个数字只出现一次之外，其他数字都出现了三次。请找出那个吃出现一次的数字。
```
int FindNumberAppearingOnce(int numbers[], int length)
{
    if(numbers == nullptr || length <= 0)
        throw new std::exception("Invalid input.");

    int bitSum[32] = {0};
    for(int i = 0; i < length; ++i){
        int bitMask = 1;
        for(int j = 31; j >= 0; --j){
            int bit = numbers[i] & bitMask;
            if(bit != 0)
                bitSum[j] += 1;

            bitMask = bitMask << 1;
        }
    }

    int result = 0;
    for(int i = 0; i < 32; ++i){
        result = result << 1;
        result += bitSum[i] % 3;
    }
    return result;
}
```
思路：用位运算，统计各个位出现1的次数，如果能被3整除，说明单一的数这位是0；如果不能被3整除，说明这一位不是0；

### 57.1 和为s的两个数字
题目：输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，输出任意一对即可。
```
bool FindNumbersWithSum(int data[], int length, int sum, 
                        int* num1, int* num2)
{
    bool found = false;
    if(length < 1 || num1 == nullptr || num2 == nullptr)
        return found;

    int ahead = length - 1;
    int behind = 0;

    while(ahead > behind){
        long long curSum = data[ahead] + data[behind];

        if(curSum == sum){
            *num1 = data[behind];
            *num2 = data[ahead];
            found = true;
            break;
        }
        else if(curSum > sum)
            ahead --;
        else
            behind ++;
    }
    return found;
}
```
思路：排好序的数组查找，就用双指针来查找；

### 57.2 为s的连续正数序列
题目：输入一个正数s，打印出所有和为s的连续正数序列（至少含有两个数）。
例如输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以结果打印出3个连续序列1～5、4～6和7～8。
```
void FindContinuousSequence(int sum)
{
    if(sum < 3)
        return;

    int small = 1; 
    int big = 2;
    int middle = (1 + sum) / 2;
    int curSum = small + big;

    while(small < middle){
        if(curSum == sum)
            PrintContinuousSequence(small, big);

        while(curSum > sum && small < middle){
            curSum -= small;
            small ++;

            if(curSum == sum)
                PrintContinuousSequence(small, big);
        }

        big ++;
        curSum += big;
    }
}
void PrintContinuousSequence(int small, int big)
{
    for(int i = small; i <= big; ++ i)
        printf("%d ", i);

    printf("\n");
}
//等差数列求和
int consecutiveNumbersSum(int N) {
	int ans = 0;
	for (int m = 1; ; m++) {
		int mx = N - m * (m-1) / 2;
		if (mx <= 0)
			break;
		if (mx % m == 0)
			ans++;
	}
	return ans;
}
```
思路：也是双指针，维护一个滑窗，求和；其实就是等差数列求和：妙啊！！

### 58.1 翻转单词顺序
题目：输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。
```
char* ReverseSentence(char *pData)
{
    if(pData == nullptr)
        return nullptr;

    char *pBegin = pData;

    char *pEnd = pData;
    while(*pEnd != '\0')
        pEnd ++;
    pEnd--;

    // 翻转整个句子
    Reverse(pBegin, pEnd);

    // 翻转句子中的每个单词
    pBegin = pEnd = pData;
    while(*pBegin != '\0'){
        if(*pBegin == ' '){
            pBegin ++;
            pEnd ++;
        }
        else if(*pEnd == ' ' || *pEnd == '\0'){
            Reverse(pBegin, --pEnd);
            pBegin = ++pEnd;
        }
        else
            pEnd ++;
    }
    return pData;
}
```
思路：先整个翻转，然后再对每个单词进行一次翻转；

### 58.2 左旋转字符串
题目：字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
请定义一个函数实现字符串左旋转操作的功能。比如输入字符串"abcdefg"和数字2，该函数将返回左旋转2位得到的结果"cdefgab"。
```
char* LeftRotateString(char* pStr, int n)
{
    if(pStr != nullptr){
        int nLength = static_cast<int>(strlen(pStr));
        if(nLength > 0 && n > 0 && n < nLength){
            char* pFirstStart = pStr;
            char* pFirstEnd = pStr + n - 1;
            char* pSecondStart = pStr + n;
            char* pSecondEnd = pStr + nLength - 1;

            // 翻转字符串的前面n个字符
            Reverse(pFirstStart, pFirstEnd);
            // 翻转字符串的后面部分
            Reverse(pSecondStart, pSecondEnd);
            // 翻转整个字符串
            Reverse(pFirstStart, pSecondEnd);
        }
    }
    return pStr;
}
//还有一个问题是判断b字符串是否为a旋转后的结果；
return A.size() == B.size() && (A + A).find(B) != string::npos;
```
思路：这个题很妙啊，先把前k个 和后面的分别翻转 然后再整个翻转；


### 59.1 滑动窗口的最大值
题目：给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值。例如，
如果输入数组{2, 3, 4, 2, 6, 2, 5, 1}及滑动窗口的大小3，那么一共存在6个滑动窗口，它们的最大值分别为{4, 4, 6, 6, 6, 5}，
```
vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
    vector<int> maxInWindows;
    if(num.size() >= size && size >= 1){
        deque<int> index;

        for(unsigned int i = 0; i < size; ++i){
            while(!index.empty() && num[i] >= num[index.back()])
                index.pop_back();

            index.push_back(i);
        }

        for(unsigned int i = size; i < num.size(); ++i){
            maxInWindows.push_back(num[index.front()]);

            while(!index.empty() && num[i] >= num[index.back()])
                index.pop_back();
            if(!index.empty() && index.front() <= (int) (i - size))
                index.pop_front();

            index.push_back(i);
        }
        maxInWindows.push_back(num[index.front()]);
    }

    return maxInWindows;
}
```
思路：

### 59.2 队列的最大值
题目：给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值。例如，
如果输入数组{2, 3, 4, 2, 6, 2, 5, 1}及滑动窗口的大小3，那么一共存在6个
滑动窗口，它们的最大值分别为{4, 4, 6, 6, 6, 5}，
```
template<typename T> class QueueWithMax
{
public:
    QueueWithMax() : currentIndex(0)
    {
    }

    void push_back(T number){
        while(!maximums.empty() && number >= maximums.back().number)
            maximums.pop_back();

        InternalData internalData = { number, currentIndex };
        data.push_back(internalData);
        maximums.push_back(internalData);

        ++currentIndex;
    }

    void pop_front(){
        if(maximums.empty())
            throw new exception("queue is empty");

        if(maximums.front().index == data.front().index)
            maximums.pop_front();

        data.pop_front();
    }

    T max() const{
        if(maximums.empty())
            throw new exception("queue is empty");

        return maximums.front().number;
    }

private:
    struct InternalData{
        T number;
        int index;
    };

    deque<InternalData> data;
    deque<InternalData> maximums;
    int currentIndex;
};
```

### 60 n个骰子的点数
题目：把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。
```
// ====================方法一====================
void Probability(int number, int* pProbabilities);
void Probability(int original, int current, int sum, int* pProbabilities);

void PrintProbability_Solution1(int number)
{
    if(number < 1)
        return;
 
    int maxSum = number * g_maxValue;
    int* pProbabilities = new int[maxSum - number + 1];
    for(int i = number; i <= maxSum; ++i)
        pProbabilities[i - number] = 0;
 
    Probability(number, pProbabilities);
 
    int total = pow((double)g_maxValue, number);
    for(int i = number; i <= maxSum; ++i){
        double ratio = (double)pProbabilities[i - number] / total;
        printf("%d: %e\n", i, ratio);
    }
 
    delete[] pProbabilities;
}
void Probability(int number, int* pProbabilities)
{
    for(int i = 1; i <= g_maxValue; ++i)
        Probability(number, number, i, pProbabilities);
}
void Probability(int original, int current, int sum, 
                 int* pProbabilities)
{
    if(current == 1){
        pProbabilities[sum - original]++;
    }
    else{
        for(int i = 1; i <= g_maxValue; ++i){
            Probability(original, current - 1, i + sum, pProbabilities);
        }
    }
} 
// ====================方法二====================
void PrintProbability_Solution2(int number)
{
    if(number < 1)
        return;

    int* pProbabilities[2];
    pProbabilities[0] = new int[g_maxValue * number + 1];
    pProbabilities[1] = new int[g_maxValue * number + 1];
    for(int i = 0; i < g_maxValue * number + 1; ++i){
        pProbabilities[0][i] = 0;
        pProbabilities[1][i] = 0;
    }
 
    int flag = 0;
    for (int i = 1; i <= g_maxValue; ++i) 
        pProbabilities[flag][i] = 1; 
    
    for (int k = 2; k <= number; ++k) {
        for(int i = 0; i < k; ++i)
            pProbabilities[1 - flag][i] = 0;

        for (int i = k; i <= g_maxValue * k; ++i) {
            pProbabilities[1 - flag][i] = 0;
            for(int j = 1; j <= i && j <= g_maxValue; ++j) 
                pProbabilities[1 - flag][i] += pProbabilities[flag][i - j];
        }
 
        flag = 1 - flag;
    }

    double total = pow((double)g_maxValue, number);
    for(int i = number; i <= g_maxValue * number; ++i){
        double ratio = (double)pProbabilities[flag][i] / total;
        printf("%d: %e\n", i, ratio);
    }
 
    delete[] pProbabilities[0];
    delete[] pProbabilities[1];
}
```
思路：动态规划的思想，第n项等于另一个第n-1、n-2、n-3、n-4、n-5、n-6的和

### 61 扑克牌的顺子
题目：从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王可以看成任意数字。
```
bool IsContinuous(int* numbers, int length)
{
    if(numbers == nullptr || length < 1)
        return false;

    qsort(numbers, length, sizeof(int), Compare);

    int numberOfZero = 0;
    int numberOfGap = 0;

    // 统计数组中0的个数
    for(int i = 0; i < length && numbers[i] == 0; ++i)
        ++numberOfZero;

    // 统计数组中的间隔数目
    int small = numberOfZero;
    int big = small + 1;
    while(big < length){
        // 两个数相等，有对子，不可能是顺子
        if(numbers[small] == numbers[big])
            return false;

        numberOfGap += numbers[big] - numbers[small] - 1;
        small = big;
        ++big;
    }
    return (numberOfGap > numberOfZero) ? false : true;
}
int Compare(const void *arg1, const void *arg2)
{
    return *(int*) arg1 - *(int*) arg2;
}
```
思路：先排序，然后计算0的个数，计算gap的个数，如果gap的个数小于0的个数，说明可以满足顺子；

### 62 圆圈中最后剩下的数字
题目：0, 1, …, n-1这n个数字排成一个圆圈，从数字0开始每次从这个圆圈里
删除第m个数字。求出这个圆圈里剩下的最后一个数字。
```
// ====================方法1====================
int LastRemaining_Solution1(unsigned int n, unsigned int m)
{
    if(n < 1 || m < 1)
        return -1;

    unsigned int i = 0;

    list<int> numbers;
    for(i = 0; i < n; ++ i)
        numbers.push_back(i);

    list<int>::iterator current = numbers.begin();
    while(numbers.size() > 1){
        for(int i = 1; i < m; ++ i){
            current ++;
            if(current == numbers.end())
                current = numbers.begin();
        }

        list<int>::iterator next = ++ current;
        if(next == numbers.end())
            next = numbers.begin();

        -- current;
        numbers.erase(current);
        current = next;
    }
    return *(current);
}
// ====================方法2====================
int LastRemaining_Solution2(unsigned int n, unsigned int m)
{
    if(n < 1 || m < 1)
        return -1;

    int last = 0;
    for (int i = 2; i <= n; i ++) 
        last = (last + m) % i;

    return last;
}
```
思路：方法一就是模拟约瑟夫环问题，时间复杂度O(mn)；第二种数学的方法很牛逼啊；

### 63 股票的最大利润
题目：假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖交易该股
票可能获得的利润是多少？例如一只股票在某些时间节点的价格为{9, 11, 8, 5,
7, 12, 16, 14}。如果我们能在价格为5的时候买入并在价格为16时卖出，则能收获最大的利润11。
```
int MaxDiff(const int* numbers, unsigned length)
{
    if(numbers == nullptr && length < 2)
        return 0;

    int min = numbers[0];
    int maxDiff = numbers[1] - min;

    for(int i = 2; i < length; ++i){
        if(numbers[i - 1] < min)
            min = numbers[i - 1];

        int currentDiff = numbers[i] - min;
        if(currentDiff > maxDiff)
            maxDiff = currentDiff;
    }
    return maxDiff;
}
```
思路：不断更新最小值与最大的差；

### 64 求1+2+…+n
题目：求1+2+…+n，要求不能使用乘除法、for、while、if、else、switch、case
等关键字及条件判断语句（A?B:C）。
```
// ====================方法一====================
class Temp
{
public:
    Temp() { ++ N; Sum += N; }

    static void Reset() { N = 0; Sum = 0; }
    static unsigned int GetSum() { return Sum; }

private:
    static unsigned int N;
    static unsigned int Sum;
};

unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;

unsigned int Sum_Solution1(unsigned int n)
{
    Temp::Reset();

    Temp *a = new Temp[n];
    delete []a;
    a = NULL;

    return Temp::GetSum();
}

// ====================方法二====================
class A;
A* Array[2];

class A
{
public:
    virtual unsigned int Sum (unsigned int n) 
    { 
        return 0; 
    }
};

class B: public A
{
public:
    virtual unsigned int Sum (unsigned int n) 
    { 
        return Array[!!n]->Sum(n-1) + n; 
    }
};

int Sum_Solution2(int n)
{
    A a;
    B b;
    Array[0] = &a;
    Array[1] = &b;

    int value = Array[1]->Sum(n);

    return value;
}

// ====================方法三====================
typedef unsigned int (*fun)(unsigned int);

unsigned int Solution3_Teminator(unsigned int n) 
{
    return 0;
}

unsigned int Sum_Solution3(unsigned int n)
{
    static fun f[2] = {Solution3_Teminator, Sum_Solution3}; 
    return n + f[!!n](n - 1);
}

// ====================方法四====================
template <unsigned int n> struct Sum_Solution4
{
    enum Value { N = Sum_Solution4<n - 1>::N + n};
};

template <> struct Sum_Solution4<1>
{
    enum Value { N = 1};
};

template <> struct Sum_Solution4<0>
{
    enum Value { N = 0};
};
```

### 65 不用加减乘除做加法
题目：写一个函数，求两个整数之和，要求在函数体内不得使用＋、－、×、÷四则运算符号。
```
int Add(int num1, int num2)
{
    int sum, carry;
    do{
        sum = num1 ^ num2;
        carry = (num1 & num2) << 1;

        num1 = sum;
        num2 = carry;
    }
    while(num2 != 0);

    return num1;
}
```

### 66 构建乘积数组
题目：给定一个数组A[0, 1, …, n-1]，请构建一个数组B[0, 1, …, n-1]，其
中B中的元素B[i] =A[0]×A[1]×… ×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。
```
void BuildProductionArray(const vector<double>& input, vector<double>& output)
{
    int length1 = input.size();
    int length2 = output.size();

    if(length1 == length2 && length2 > 1){
        output[0] = 1;
        for(int i = 1; i < length1; ++i){
            output[i] = output[i - 1] * input[i - 1];
        }

        double temp = 1;
        for(int i = length1 - 2; i >= 0; --i){
            temp *= input[i + 1];
            output[i] *= temp;
        }
    }
}
```

### 67 把字符串转换成整数
题目：请你写一个函数StrToInt，实现把字符串转换成整数这个功能。当然，不
能使用atoi或者其他类似的库函数。
```
int StrToInt(const char* str)
{
    g_nStatus = kInvalid;
    long long num = 0;

    if(str != nullptr && *str != '\0') {
        bool minus = false;
        if(*str == '+')
            str ++;
        else if(*str == '-') {
            str ++;
            minus = true;
        }

        if(*str != '\0') 
            num = StrToIntCore(str, minus);
    }

    return (int)num;
}
long long StrToIntCore(const char* digit, bool minus)
{
    long long num = 0;

    while(*digit != '\0') {
        if(*digit >= '0' && *digit <= '9') {
            int flag = minus ? -1 : 1;
            num = num * 10 + flag * (*digit - '0');

            if((!minus && num > 0x7FFFFFFF) 
                || (minus && num < (signed int)0x80000000)){
                num = 0;
                break;
            }

            digit++;
        }
        else {
            num = 0;
            break;
        }
    }

    if(*digit == '\0') 
        g_nStatus = kValid;

    return num;
}
```

### 68 树中两个结点的最低公共祖先
题目：输入两个树结点，求它们的最低公共祖先。
```
bool GetNodePath(const TreeNode* pRoot, const TreeNode* pNode, list<const TreeNode*>& path)
{
    if(pRoot == pNode)
        return true;
 
    path.push_back(pRoot);
 
    bool found = false;

    vector<TreeNode*>::const_iterator i = pRoot->m_vChildren.begin();
    while(!found && i < pRoot->m_vChildren.end()){
        found = GetNodePath(*i, pNode, path);
        ++i;
    }
 
    if(!found)
        path.pop_back();
 
    return found;
}
const TreeNode* GetLastCommonNode
(
    const list<const TreeNode*>& path1, 
    const list<const TreeNode*>& path2
){
    list<const TreeNode*>::const_iterator iterator1 = path1.begin();
    list<const TreeNode*>::const_iterator iterator2 = path2.begin();
    
    const TreeNode* pLast = nullptr;
 
    while(iterator1 != path1.end() && iterator2 != path2.end()){
        if(*iterator1 == *iterator2)
            pLast = *iterator1;
 
        iterator1++;
        iterator2++;
    }
    return pLast;
}
const TreeNode* GetLastCommonParent(const TreeNode* pRoot, const TreeNode* pNode1, const TreeNode* pNode2)
{
    if(pRoot == nullptr || pNode1 == nullptr || pNode2 == nullptr)
        return nullptr;
 
    list<const TreeNode*> path1;
    GetNodePath(pRoot, pNode1, path1);
 
    list<const TreeNode*> path2;
    GetNodePath(pRoot, pNode2, path2);
 
    return GetLastCommonNode(path1, path2);
}
```



