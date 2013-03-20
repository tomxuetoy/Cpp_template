#include <stdio.h>

template<typename T>
class MyTestClass {
public:
    //这里的typename是用于通知编译器，其后的MyType是模板T定义的内部类型，从这个代码示例
    //中可以看出，不管是在函数参数、返回值还是定义成员变量定义，都要遵守这一语法规则。
    MyTestClass(typename T::MyType p) : _p(p) {
    }

    typename T::MyType GetData() const {
        return _p; 
    }
public:
    typename T::MyType _p;
};

//在该类中，由于后面的调用需要将其用作MyTestClass的模参，因此他必须typedef名字为MyType的
//内部类型，否则将会导致编译失败。
class TemplateParamClass {
public:
    typedef const char* MyType;
};

int main() {
    MyTestClass<TemplateParamClass> t("Hello");
    printf("The data is %s.\n", t.GetData());
    return 0;
}
