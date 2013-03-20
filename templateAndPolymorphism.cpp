#include <stdio.h>
#include <string.h>

//1. 定义一个接口
class BaseInterface {
public:
    virtual ~BaseInterface() {}
    virtual void doPrint() = 0;
};

//2. 标准模板类继承该接口，同时给出自己的doPrint()实现。
template<typename T>
class DeriveClass : public BaseInterface {
public:    
    void doPrint() {
        printf("This is 'template<typename T> class DeriveClass'.\n");
    }
};

//3. 基于int类型特化后的DeriveClass模板类，同样继承了该接口，也给出了自己的DoPrint()实现。
template<>
class DeriveClass<int> : public BaseInterface {
public:    
    void doPrint() {
        printf("This is 'template<> class DeriveClass<int>'.\n");
    }
};

//4. 对象创建辅助函数，该函数可以通过参数类型的不同，实例化不同的接口子类。
template<typename T>
inline BaseInterface* DoTest(T t) {
    return new DeriveClass<T>;
}

int main() {
    BaseInterface* b1 = DoTest(4.5f);
    b1->doPrint();
    BaseInterface* b2 = DoTest(5);
    b2->doPrint();
    delete b1;
    delete b2;
    return 0;
}
//This is 'template<typename T> class DeriveClass'.
//This is 'template<> class DeriveClass<int>'.
//
//
//
//这是结合模板特化和多态的示例
