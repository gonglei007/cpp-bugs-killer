#include <iostream>
#include <vector>
using namespace std;

// 有bug的版本：使用无符号数递减
void ProcessData_Bug(const vector<int>& data)
{
    cout << "=== 有Bug的版本（可能导致无限循环）===" << endl;
    size_t size = data.size();
    cout << "初始size: " << size << endl;
    
    int count = 0;
    while (--size >= 0) {  // Bug: 无符号数下溢问题
        count++;
        cout << "循环中，size = " << size << ", count = " << count << endl;
        
        // 防止真正的无限循环（仅用于演示）
        if (count > 10) {
            cout << "检测到可能的无限循环，强制退出" << endl;
            break;
        }
    }
}

// 正确的版本1：使用有符号整数
void ProcessData_Correct1(const vector<int>& data)
{
    cout << "\n=== 正确版本1：使用有符号整数 ===" << endl;
    int size = static_cast<int>(data.size());
    cout << "初始size: " << size << endl;
    
    int count = 0;
    while (--size >= 0) {
        count++;
        cout << "循环中，size = " << size << ", count = " << count << endl;
    }
    cout << "循环正常结束" << endl;
}

// 正确的版本2：使用递增循环（推荐）
void ProcessData_Correct2(const vector<int>& data)
{
    cout << "\n=== 正确版本2：使用递增循环（推荐）===" << endl;
    size_t size = data.size();
    cout << "size: " << size << endl;
    
    int count = 0;
    for (size_t i = 0; i != size; i++) {
        count++;
        cout << "循环中，i = " << i << ", count = " << count << endl;
    }
    cout << "循环正常结束" << endl;
}

// 正确的版本3：使用递减但检查>0
void ProcessData_Correct3(const vector<int>& data)
{
    cout << "\n=== 正确版本3：使用递减但检查>0 ===" << endl;
    size_t size = data.size();
    cout << "初始size: " << size << endl;
    
    int count = 0;
    while (size > 0) {
        --size;
        count++;
        cout << "循环中，size = " << size << ", count = " << count << endl;
    }
    cout << "循环正常结束" << endl;
}

int main()
{
    vector<int> data = {1, 2, 3, 4, 5};
    
    ProcessData_Bug(data);
    ProcessData_Correct1(data);
    ProcessData_Correct2(data);
    ProcessData_Correct3(data);
    
    return 0;
}

