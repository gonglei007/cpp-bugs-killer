#include <iostream>
#include <cstdlib>
using namespace std;

// 有bug的版本：未初始化变量
int CalculateSum_Bug(int count)
{
    int sum;  // Bug: 未初始化
    for (int i = 0; i < count; i++) {
        sum += i;  // 使用未初始化的变量
    }
    return sum;
}

// 正确的版本
int CalculateSum_Correct(int count)
{
    int sum = 0;  // 正确：初始化为0
    for (int i = 0; i < count; i++) {
        sum += i;
    }
    return sum;
}

// 结构体未初始化示例
struct Point_Bug {
    int x, y;  // 未初始化
};

struct Point_Correct {
    int x = 0, y = 0;  // C++11: 成员初始化器
};

// 数组未初始化示例
void ArrayExample()
{
    int arr_bug[5];  // 所有元素的值不确定
    int arr_correct[5] = {};  // 所有元素初始化为0
    int arr_partial[5] = {1, 2, 3};  // 前3个元素有值，其余为0
    
    cout << "未初始化数组（值不确定）: ";
    for (int i = 0; i < 5; i++) {
        cout << arr_bug[i] << " ";
    }
    cout << endl;
    
    cout << "正确初始化数组: ";
    for (int i = 0; i < 5; i++) {
        cout << arr_correct[i] << " ";
    }
    cout << endl;
}

// 指针未初始化示例
void PointerExample()
{
    int* ptr_bug;  // 指向随机地址
    // *ptr_bug = 10;  // 危险：可能崩溃，注释掉
    
    int* ptr_correct = nullptr;  // 初始化为空指针
    if (ptr_correct != nullptr) {
        *ptr_correct = 10;
    } else {
        cout << "指针为空，不能使用" << endl;
    }
}

int main()
{
    cout << "=== 未初始化变量示例 ===" << endl;
    cout << "有Bug的版本（结果不确定）: " << CalculateSum_Bug(10) << endl;
    cout << "正确的版本: " << CalculateSum_Correct(10) << endl;
    
    cout << "\n=== 结构体初始化 ===" << endl;
    Point_Bug p_bug;
    cout << "未初始化结构体: x=" << p_bug.x << ", y=" << p_bug.y << endl;
    
    Point_Correct p_correct;
    cout << "正确初始化结构体: x=" << p_correct.x << ", y=" << p_correct.y << endl;
    
    cout << "\n=== 数组初始化 ===" << endl;
    ArrayExample();
    
    cout << "\n=== 指针初始化 ===" << endl;
    PointerExample();
    
    return 0;
}

