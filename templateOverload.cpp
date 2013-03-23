#include <stdio.h>

template<typename T>
int Test(T v) {
    return v;
}

template<typename T>
double Test(T v, T v2) {
    return v;
}

int main() {
    //通过判断返回值的长度来确定调用的是哪个重载函数。
    printf("This size of return value is %d.\n",sizeof(Test(0,0)));
    printf("This size of return value is %d.\n",sizeof(Test(0)));

    return 0;
}
