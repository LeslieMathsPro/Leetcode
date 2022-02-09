//面试题2: 实现Singleton模式
//题目: 设计一个类，我们只能生成该类的一个实例。
#include <iostream>
using namespace std;
//饿汉式的实现: 即类产生的时候就创建好实例对象，是一种空间换时间的方式
class SingleTon
{
private:
    static SingleTon instance; // 单例对象在这里

private:
    SingleTon() { cout << "单例对象的创建!" << endl; };
    SingleTon(const SingleTon &);
    SingleTon& operator=(const SingleTon &);
    ~SingleTon() { cout << "单例对象的销毁!" << endl; };

public:
    static SingleTon* getInstance()
    {
        return &instance;//第一次调用时才会调用构造函数 
    }
};

//懒汉式的实现: 即在需要的时候，才创建对象，这是一种时间换空间的方式
class SingleTon_L
{
private:
    SingleTon_L() { cout << "单例对象的创建！" << endl;};
    SingleTon_L(const SingleTon_L &);
    SingleTon_L& operator=(const SingleTon_L &);
    ~SingleTon_L() { cout << "单例对象的销毁!" << endl; };

public:
    static SingleTon_L* getInstance()
    {
        static SingleTon_L instance_L; //第一次用到时才创建对象
        return &instance_L;
    }
};