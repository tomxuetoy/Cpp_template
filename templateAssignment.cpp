#include <stdio.h>

template <typename T>
class TestClass {
public:
    TestClass(T v) : _value(v) {
    }

    template<typename T2>
    TestClass<T>& operator= (const TestClass<T2>& other) {
        //这是编写重载赋值操作符的基本技巧，既不能进行自身对自身的赋值。
        if ((void*)this == (void*)&other)
            return *this;
        //需要说明的是，由于other和this是通过不同类型实例化的模板类，因此这里不能
        //像普通类那样直接调用other._value。编译器将他们视为不同的类型，所以也就不
        //能直接访问其私有变量了。
        _value = other.getValue();
        return *this;
    }

    T getValue() const {
        return _value;
    }
private:
    T _value;
};

int main() {
    TestClass<int> intClass(5);
    TestClass<double> doubleClass(6.4);
    printf("The value before assignment is %f.\n",doubleClass.getValue());
    //此时的T为double，T2为int。
    doubleClass = intClass;
    printf("The value after assignment is %f.\n",doubleClass.getValue());
    return 0;
}
//The value before assignment is 6.400000.
//The value after assignment is 5.000000.  
