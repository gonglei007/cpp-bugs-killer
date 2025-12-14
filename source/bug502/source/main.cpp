#include <iostream>
#include <memory>
using namespace std;

bool someCondition = true;  // 改为false测试不同情况

// 有bug的版本：内存泄漏
void ProcessData_Bug()
{
    int* data = new int[1000];
    cout << "分配了内存" << endl;
    
    // 使用data进行一些操作
    for (int i = 0; i < 1000; i++) {
        data[i] = i;
    }
    
    if (someCondition) {
        cout << "提前返回，内存泄漏！" << endl;
        return;  // Bug: 提前返回，没有释放内存
    }
    
    // ... 更多操作
    delete[] data;
    cout << "释放了内存" << endl;
}

// 正确的版本1：使用智能指针（推荐）
void ProcessData_Correct1()
{
    unique_ptr<int[]> data(new int[1000]);
    cout << "分配了内存（智能指针）" << endl;
    
    // 使用data进行一些操作
    for (int i = 0; i < 1000; i++) {
        data[i] = i;
    }
    
    if (someCondition) {
        cout << "提前返回，但内存会自动释放" << endl;
        return;  // 自动释放内存
    }
    
    // ... 更多操作
    cout << "内存会在智能指针析构时自动释放" << endl;
}

// 正确的版本2：确保所有路径都释放
void ProcessData_Correct2()
{
    int* data = new int[1000];
    cout << "分配了内存" << endl;
    
    // 使用data进行一些操作
    for (int i = 0; i < 1000; i++) {
        data[i] = i;
    }
    
    if (someCondition) {
        delete[] data;  // 提前返回前释放
        cout << "提前返回，但已释放内存" << endl;
        return;
    }
    
    // ... 更多操作
    delete[] data;
    cout << "释放了内存" << endl;
}

int main()
{
    cout << "=== 有Bug的版本 ===" << endl;
    ProcessData_Bug();
    
    cout << "\n=== 正确版本1：智能指针 ===" << endl;
    ProcessData_Correct1();
    
    cout << "\n=== 正确版本2：手动管理 ===" << endl;
    someCondition = false;
    ProcessData_Correct2();
    
    return 0;
}

