#include <stdio.h>
#include <conio.h>

inline int const& max(int const& a, int const& b) {
    printf("int const& max(int const& a, int const& b) is called.\n");
    return a < b ? b : a;
}

template <typename T> 
inline T const& max(T const& a, T const& b) {
    printf("T const& max(T const& a, T const& b) is called.\n");
    return a < b ? b : a;
}

template <typename T> 
inline T const& max(T const& a, T const& b, T const& c) {
    printf("T const& max(T const& a, T const& b, T const& c) is called.\n");
    return ::max(::max(a,b),c);
}

class MyClass {
public:
    MyClass(int value) : _value(value) {
    }
    bool operator< (const MyClass& other) const {
        printf("operator < is call\n");
        return _value < other._value;
    }
    int myValue() const { return _value; }
private:
    int _value;
};

int main() {
    ::max(5,43,68);    //三个参数的max<int>
    printf("------------------------------------\n"); 
    ::max('a','b');    //两个参数的max<char>
    ::max(7,54);       //int参数类型的非模板函数。
    ::max<>(7,54);     //两个参数的max<int>
    ::max('a',43.2);   //int参数类型的非模板函数。
    getch();
    return 0;
}
/* 
$ a.exe
T const& max(T const& a, T const& b, T const& c) is called.
int const& max(int const& a, int const& b) is called.
int const& max(int const& a, int const& b) is called.
------------------------------------
T const& max(T const& a, T const& b) is called.
int const& max(int const& a, int const& b) is called.
T const& max(T const& a, T const& b) is called.
int const& max(int const& a, int const& b) is called.

 * */
