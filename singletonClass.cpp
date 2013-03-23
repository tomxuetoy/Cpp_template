#include <stdio.h>

template<typename T>
class SingletonClass {
public:
    static T* GetInstance() {
        if (NULL == _instance)
            _instance = new T();    // T = MySingletonClass later, by tomxue
        return _instance;
    }

    static void ReleaseInstance() {
        if (NULL != _instance) {
            delete _instance;
            _instance = NULL;
        }
    }
private:
    static T* _instance;
};

template<typename T>
T* SingletonClass<T>::_instance = NULL;

class MySingletonClass : public SingletonClass<MySingletonClass> {
public:
    MySingletonClass() {}
    ~MySingletonClass() {}

public:
    void DoPrint() {
        printf("This is MySingletonClass.\n");
    }
};

int main()
{
    MySingletonClass* myClass = MySingletonClass::GetInstance();
    myClass->DoPrint();
    MySingletonClass::ReleaseInstance();
    return 0;
}
/* 
$ a.exe
This is MySingletonClass.
 * */
