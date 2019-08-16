# 剑指offer

## note：
- 21题的可扩展解法很有意思，mark

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

### 13：机器人的运动范围
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

### 面试题20：表示数值的字符串
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






