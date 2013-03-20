#include <stdio.h>
#include <string.h>

//1. 这里我们先声明了一个通用类型的模板类。这里要有类型参数必须包含hashCode()方法。
//否则，该类型在编译期实例化时将会导致编译失败。
template <typename T>
class CalcHashClass { //该类为标准模板类(等同于多态中的接口)
public:
    CalcHashClass(T const& v) : _value(v) {
    }

    int hashCode() {
        printf("This is 'template <typename T> class CalcHashClass'.\n");
        return _value.hashCode() + 10000;
    }
private:
    T _value;
};

//2. int类型实例化特化模板类。
template <>
class CalcHashClass<int> {
public:
    CalcHashClass(int const& v) : _value(v) {
    }

    int hashCode() {
        printf("This is 'template <> class CalcHashClass<int>'.\n");
        return _value * 101;
    }
private:
    int _value;
};

//3. const char*类型实例化的特化模板类
template<>
class CalcHashClass<const char*> {
public:
    CalcHashClass(const char* v) {
        _v = new char[strlen(v) + 1];
        strcpy(_v,v);
    }

    ~CalcHashClass() {
        delete [] _v;
    }

    int hashCode() {
        printf("This is 'template <> class CalcHashClass<const char*>'.\n");
        int len = strlen(_v);
        int code = 0;
        for (int i = 0; i < len; ++i)
            code += (int)_v[i];
        return code;
    }

private:
    char* _v;
};

//4. 辅助函数，用于帮助调用者通过函数的参数类型自动进行类型推演，以让编译器决定该
//实例化哪个模板类。这样就可以使调用者不必在显示指定模板类的类型了。这一点和多态有
//点儿类似。
template<typename T>
inline int CalcHashCode(T v) {
    CalcHashClass<T> t(v);
    return t.hashCode();
}

//5. 给出一个范例类，该类必须包含hashCode方法，否则将造成编译错误。
class TestClass {
public:
    TestClass(const char* v) {
        _v = new char[strlen(v) + 1];
        strcpy(_v,v);
    }

    ~TestClass() {
        delete [] _v;
    }
public:
    int hashCode() {
        int len = strlen(_v);
        int code = 0;
        for (int i = 0; i < len; ++i)
            code += (int)_v[i];
        return code;
    }
private:
    char* _v;
};

int main() {
    TestClass tc("Hello");
    CalcHashClass<TestClass> t1(tc);
    printf("The hashcode is %d.\n",t1.hashCode());
    //这里由于为模板类TestClass提供了基于int类型的模板特化类，因此编译器会自动选择
    //更为特化的模板类作为t2的目标类。
    CalcHashClass<int> t2(10);
    printf("The hashcode is %d.\n",t2.hashCode());

    //在上面的示例中，我们通过显示的给出类型信息以实例化不同的模板类，这是因为模板类
    //的类型信息是无法像模板函数那样可以通过函数参数进行推演的，为了弥补这一缺失，我们可以
    //通过一个额外的模板函数来帮助我们完成这一功能。事实上，这一技巧在Thinking in Java中
    //也同样给出了。
    printf("Ths hashcode is %d.\n",CalcHashCode(10));
    printf("Ths hashcode is %d.\n",CalcHashCode("Hello"));
    return 0;
}
//This is 'template <typename T> class CalcHashClass'.
//The hashcode is 10500.
//This is 'template <> class CalcHashClass<int>'.
//The hashcode is 1010.
//This is 'template <> class CalcHashClass<int>'.
//Ths hashcode is 1010.
//This is 'template <> class CalcHashClass<const char*>'.
//Ths hashcode is 500.
//
//
//
//通过上面的示例可以看出，模板特化是依赖于编译器在编译期动态决定该使用哪个特化类，或是标准模板类的。
//相比于多态的后期动态绑定，该方式的运行效率更高，同时灵活性也没有被更多的牺牲
