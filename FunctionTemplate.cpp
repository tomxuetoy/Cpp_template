#include <stdio.h>
#include <conio.h>

template <typename T> 

inline T const& max(T const& a, T const& b) {
    static int i = 0;
    printf("The value of i is %d\n",i++);
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
    ::max(4,5);     //for max<int>
    ::max(5,6);     //for max<int>
    ::max(5.3,5.4); //for max<float>
    ::max(5.3,5.4); //for max<float>
    
    MyClass m1(30), m2(40);
    printf("The max value is %d\n",::max(m1,m2).myValue());

    getch();
    return 0;
}
/*
$ a.exe
The value of i is 0
The value of i is 1
The value of i is 0
The value of i is 1
The value of i is 0
operator < is called.
The max value is 40

由(value of i)此可见，max模板函数确实在代码段中被生成三份
*/
