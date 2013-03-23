#include <stdio.h>

// 所谓的模板的模板参数，是指模板的参数是另外一个模板类
// 该模板类的第3个模板必须是另外一个模板类。
template<typename T, typename T2, template <typename T> class TemplateClass>
class TemplateTemplateClass {
public:
    TemplateTemplateClass(const TemplateClass<T>& tempClass)
        : _internalClass(tempClass) {
    }

    void doTest() {
        _internalClass.doTest();
    }
private:
    TemplateClass<T> _internalClass;
};

template <typename T>
class MyTemplateClass {
public:
    void doTest() {
        printf("This is MyTemplateClass::doTest().\n");
    }
};

int main() {
    MyTemplateClass<int> tempClass;
    TemplateTemplateClass<int, int, MyTemplateClass> tempTempClass(tempClass);
    tempTempClass.doTest();
    return 0;
}
//This is MyTemplateClass::doTest().
