#include <stdio.h>

template<typename T>
class TestClass {
public:
    virtual ~TestClass() {}  //析构函数是普通的成员函数，因此可以是虚函数。

public:
    template<typename T2>
    virtual void DoTest(T2 const& ) {} //vs2010给出的编译错误提示是: 'member function templates cannot be virtual'
};

int main()
{
    TestClass<int> c;
    return 0;
}
/* 
$ g++ 1.cpp
1.cpp:10:5: error: templates may not be 'virtual'

模板类的成员模板函数不能是虚函数，因为虚函数调用机制的普遍实现都使用了一个大小固定的表，
每个虚函数都对应表的一个入口。然而，成员模板函数的实例化个数则需要等到整个程序都编译完毕后
才能最终确定，即如果某个成员模板函数没有被任何代码调用过，那么该函数将不参与编译，
因此也就不会有对应的函数入口。鉴于此，这就和虚函数表需要固定大小的限制发生了冲突。

然而需要明确指出的是，模板类中的普通成员函数是可以成为虚函数的，因为普通成员函数是随同模板类一同被编译的
 * */
