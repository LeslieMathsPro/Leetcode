//字符串是由若干字符组成的序列。C/C++中每个字符串都以字符'\0'作为结尾，这样我们就能很方便地找到字符串的最后尾部。
//但也由于这个特点，每个字符串中都有一个额外字符的开销，稍不留神就会造成字符串的越界，
#include <iostream>
using namespace std;

int main()
{
    //str1 与 str2 是两个字符串数组，我们会为他们分配两个长度为12字节的空间，并把"hello, world"的内容分别复制到数组中去。
    //这是两个初始地址不同的数组，因此str1与str2的值也不相同。
    char str1[] = "hello world";
    char str2[] = "hello world";

    //str3 与 str4 是两个指针，我们无须为它们分配内存以存储字符串的内容，而只需要把它们指向"hello world"在内存中的地址就可以了。
    //由于"hello world"是常量字符串，它在内存中只有一个拷贝，因此str3和str4指向的是同一个地址。
    char* str3 = "hello world";
    char* str4 = "hello world";

    if (str1 == str2)
        cout << "str1 and str2 are the same. \n";
    else 
        cout << "str1 and str2 are not the same. \n";

    if (str3 == str4)
        cout << "str3 and str4 are the same. \n";
    else
        cout << "str3 and str4 are not the same. \n";

    return 0;
}