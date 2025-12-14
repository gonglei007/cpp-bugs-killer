#include <iostream>
#include <string>
#include <memory>
using namespace std;

// 有bug的版本：返回局部变量的引用
int& GetReference_Bug()
{
    int value = 42;
    return value;  // Bug: 返回局部变量的引用
}

// 正确的版本1：返回对象
int GetValue_Correct()
{
    int value = 42;
    return value;  // 返回值的副本
}

// 正确的版本2：返回静态变量
int& GetReference_Static()
{
    static int value = 42;  // 静态变量生命周期持续到程序结束
    return value;  // 安全
}

// 正确的版本3：返回传入参数的引用
int& GetMax(int& a, int& b)
{
    return (a > b) ? a : b;  // 返回参数的引用，安全
}

// 返回临时对象的引用（错误示例）
const string& GetName_Bug()
{
    return string("temp");  // Bug: 临时对象在函数返回后销毁
}

// 正确的版本：返回对象
string GetName_Correct()
{
    return string("temp");  // 返回对象，安全
}

// 引用已释放的内存（错误示例）
void DanglingReferenceExample()
{
    int* ptr = new int(42);
    int& ref = *ptr;
    cout << "引用值: " << ref << endl;
    
    delete ptr;  // 释放内存
    // ref = 10;  // Bug: 使用悬空引用，可能导致崩溃，注释掉
    cout << "内存已释放，引用变为悬空引用" << endl;
}

int main()
{
    cout << "=== 返回局部变量引用（未定义行为）===" << endl;
    // int& ref_bug = GetReference_Bug();  // 危险，注释掉
    // cout << ref_bug << endl;  // 未定义行为
    
    cout << "\n=== 正确版本1：返回对象 ===" << endl;
    int val = GetValue_Correct();
    cout << "值: " << val << endl;
    
    cout << "\n=== 正确版本2：返回静态变量 ===" << endl;
    int& ref_static = GetReference_Static();
    cout << "引用值: " << ref_static << endl;
    ref_static = 100;
    cout << "修改后: " << ref_static << endl;
    
    cout << "\n=== 正确版本3：返回参数引用 ===" << endl;
    int a = 10, b = 20;
    int& max_ref = GetMax(a, b);
    cout << "较大值: " << max_ref << endl;
    max_ref = 30;
    cout << "修改后 b: " << b << endl;
    
    cout << "\n=== 返回临时对象引用（错误）===" << endl;
    // const string& name_bug = GetName_Bug();  // 危险，注释掉
    // cout << name_bug << endl;  // 未定义行为
    
    cout << "\n=== 正确版本：返回对象 ===" << endl;
    string name = GetName_Correct();
    cout << "名称: " << name << endl;
    
    cout << "\n=== 引用已释放的内存 ===" << endl;
    DanglingReferenceExample();
    
    return 0;
}

