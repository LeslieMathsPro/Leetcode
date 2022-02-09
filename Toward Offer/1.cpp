//面试题1：赋值运算符函数
//题目：如下为类型CMyString的声明，请为该类型添加赋值运算符函数。
#include <iostream>
using namespace std;

class CMyString
{
public:
    CMyString (char* pData = NULL);
    CMyString (const CMyString& str);
    CMyString& operator=(const CMyString &str);
    ~CMyString (void);

private:
    char* m_pData;
};

CMyString& CMyString::operator=(const CMyString &str)
{
    if (this == &str)
        return *this;
    
    delete []m_pData;
    m_pData = NULL;
    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);

    return *this;
}

int main(){
    return 0;
}