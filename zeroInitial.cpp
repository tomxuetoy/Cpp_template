#include <stdio.h>

template <typename T>
class TestClass {
public:
    //1. 第一步是为模板类提供一个缺省构造函数，在该函数的初始化列表中显示的完成
    //模参类型成员的变量的初始化。
    //2. 在这个例子中，要求模板类型或者为原始类型，如int、double等。倘若是类类型
    //则该类必须提供缺省构造函数，否则将导致编译失败。
    //3. 对于原始类型，如int，在执行完_value()之后，其值将被初始化为0。
    TestClass() : _value() {
    }
    
    void getValue() {
        printf("_value=%d\n", _value);
    }

private:
    T _value;
};

int main() {
    TestClass<int> t;
    t.getValue();
    return 0;
}
