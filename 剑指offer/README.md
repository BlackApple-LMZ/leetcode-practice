# 剑指offer

### 1 赋值运算符
思路：四个细节 
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
- 返回引用，return *this;
- 传入参数常量引用；
- 释放已分配的内存；
- 判断*this是否与输入一样；

### 2 数组中重复的数字：leetcode 217 287
