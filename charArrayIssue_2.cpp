template<typename T>
inline T const& max(T const& a, T const& b) {
    return a < b ? b : a;
}

int main() {
    //可以编译通过，因为他们都是char const [6]
    max("apple","peach"); 
    //不可以编译通过，因为这两个函数参数的类型分别为char const[6]和char const [5]
    //对于这种情况，我们可以考虑重载一个max函数，其函数参数为T，而不是T const&
    max("apple","pear"); 
    return 0;
}
/* 
$ g++ 3.cpp
3.cpp: In function 'int main()':
3.cpp:11:23: error: no matching function for call to 'max(const char [6], const char [5])'
3.cpp:11:23: note: candidate is:
3.cpp:2:17: note: template<class T> const T& max(const T&, const T&)

 * */
