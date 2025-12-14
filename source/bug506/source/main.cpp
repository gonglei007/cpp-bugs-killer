#include <iostream>
using namespace std;

// 有bug的版本：C风格强制转换
void ProcessData_Bug(void* data)
{
    int* intPtr = (int*)data;  // Bug: C风格强制转换
    *intPtr = 100;
}

// 正确的版本：使用C++风格转换
void ProcessData_Correct(void* data)
{
    int* intPtr = static_cast<int*>(data);  // 明确表示这是指针转换
    *intPtr = 100;
}

// 继承层次结构
class Base {
public:
    virtual ~Base() {}  // 必须有虚函数才能使用dynamic_cast
    virtual void f() { cout << "Base::f()" << endl; }
};

class Derived : public Base {
public:
    void f() override { cout << "Derived::f()" << endl; }
    void derivedMethod() { cout << "Derived::derivedMethod()" << endl; }
};

// 有bug的版本：不安全的向下转换
void Process_Bug(Base* base)
{
    Derived* derived = (Derived*)base;  // Bug: 不安全的向下转换
    derived->derivedMethod();  // 如果base不是Derived类型，会导致未定义行为
}

// 正确的版本：使用dynamic_cast
void Process_Correct(Base* base)
{
    Derived* derived = dynamic_cast<Derived*>(base);
    if (derived != nullptr) {  // 检查转换是否成功
        derived->derivedMethod();  // 安全使用
    } else {
        cout << "转换失败，base不是Derived类型" << endl;
    }
}

// 类型转换示例
void TypeCastExamples()
{
    cout << "=== static_cast示例 ===" << endl;
    double d = 3.14159;
    int i = static_cast<int>(d);  // 明确的数值转换
    cout << "double: " << d << " -> int: " << i << endl;
    
    cout << "\n=== const_cast示例 ===" << endl;
    const int value = 42;
    const int* constPtr = &value;
    int* mutablePtr = const_cast<int*>(constPtr);
    cout << "移除const: " << *mutablePtr << endl;
    
    cout << "\n=== reinterpret_cast示例（危险）===" << endl;
    int num = 0x12345678;
    void* voidPtr = &num;
    char* charPtr = reinterpret_cast<char*>(voidPtr);
    cout << "重新解释为char*: " << hex << (int)*charPtr << endl;
}

int main()
{
    cout << "=== C风格转换 vs C++风格转换 ===" << endl;
    int value = 42;
    ProcessData_Bug(&value);
    cout << "C风格转换后值: " << value << endl;
    
    value = 42;
    ProcessData_Correct(&value);
    cout << "C++风格转换后值: " << value << endl;
    
    cout << "\n=== 不安全的向下转换 ===" << endl;
    Base* base1 = new Base();
    Base* base2 = new Derived();
    
    cout << "使用Base对象（危险）: ";
    // Process_Bug(base1);  // 危险，可能导致崩溃，注释掉
    
    cout << "使用Derived对象（虽然能工作但不安全）: ";
    Process_Bug(base2);  // 虽然能工作，但不安全
    
    cout << "\n=== 安全的向下转换 ===" << endl;
    cout << "使用Base对象: ";
    Process_Correct(base1);
    
    cout << "使用Derived对象: ";
    Process_Correct(base2);
    
    cout << "\n=== 类型转换示例 ===" << endl;
    TypeCastExamples();
    
    delete base1;
    delete base2;
    
    return 0;
}

