#include <iostream>
using namespace std;

class A{
public:
    A();
    ~A();
};

int main()
{
    A a;
    cout << sizeof(a) << endl; //空类型的实例不包含任何信息，本来求sizeof应该是0.
    //但是当我们声明该变量的实例的时候，它必须在内存中占有一定的空间，否则无法使用这些实例。
}