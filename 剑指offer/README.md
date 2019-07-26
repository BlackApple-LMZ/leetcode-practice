# 剑指offer

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








