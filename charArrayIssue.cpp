#include <stdio.h>
#include <typeinfo>

template <typename T>
void ref(T const& x) {
    printf("x in ref(T const&): %s.\n",typeid(x).name());
}

template <typename T>
void nonref(T x) {
    printf("x in nonref(T): %s.\n",typeid(x).name());
}

int main() {
    ref("Hello");
    nonref("Hello");
    return 0;
}

/*
x in ref(T const&): char const [6].
x in nonref(T): char const *.

Tom Xue get below result:
$ a.exe
x in ref(T const&): A6_c.
x in nonref(T): PKc.

A6_c表示：array(A) of 6 chars (c)；PKc表示：pointer (P) to const (K) char (c)。

如果函数的参数不是char*而是字符数组的话，由于max的参数为T const&引用类型，
因此在模板函数实例化时将会造成很多限制

A Geek comment:
不同长度的同类型数组长度还是不一样啊，怎么能是同一个类型呢？所以这就有问题了，不同长度的字符串常量还不能作为同一个类型直接传递进模板了？
如果我们用引用传递的话，是；可如果不用的话就行了，这正是解决方法！或者更干脆，直接用std::string。
*/
