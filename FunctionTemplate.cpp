#include <stdio.h>

template <typename T> 

inline T const& max(T const& a, T const& b) {
    return a < b ? b : a;
}

class MyClass {
     public:
         MyClass(int value) : _value(value) {
         }

         bool operator< (const MyClass& other) const { //注意这里的操作符重载方法必需是const函数
             printf("operator < is called.\n");
             return _value < other._value;
         }

         int myValue() const { return _value; }

     private:
         int _value;
};
     
int main()
{
    MyClass m1(30), m2(40);
    printf("The max value is %d\n",::max(m1,m2).myValue());
    return 0;
}
