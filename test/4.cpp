#include <iostream>
class Foo {
public:
    explicit Foo(int a)
    {
        std::cout << "explicit Foo(int a)" << std::endl;
    }
    void func()
    {
        std::cout << "void func()" << std::endl;
    }
private:
    Foo(const Foo& foo)
    {
        std::cout << "Foo(const Foo& foo)" << std::endl;
    }
};
int main()
{
    Foo a;//1
    Foo b();//2
    Foo c(1);//3
    Foo d = c;//4
    return 0;
}