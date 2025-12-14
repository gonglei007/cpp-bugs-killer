#include <iostream>
using namespace std;

bool IsLunaMenuStyle() {
    return true;  // 可以改为false测试不同情况
}

bool xp_space_accelerators = false;
bool original_space_accelerators = true;

// 有bug的版本
void InsertSpaces_Bug()
{
    cout << "=== 有Bug的版本 ===" << endl;
    if(IsLunaMenuStyle())
        if(!xp_space_accelerators) {
            cout << "执行了xp_space_accelerators分支" << endl;
            return;
        }
    else  // 这个else实际上匹配的是内层的if
        if(!original_space_accelerators) {
            cout << "执行了original_space_accelerators分支" << endl;
            return;
        }
    cout << "继续执行后续代码" << endl;
}

// 正确的版本
void InsertSpaces_Correct()
{
    cout << "\n=== 正确的版本 ===" << endl;
    if(IsLunaMenuStyle()) {
        if(!xp_space_accelerators) {
            cout << "执行了xp_space_accelerators分支" << endl;
            return;
        }
    } else {
        if(!original_space_accelerators) {
            cout << "执行了original_space_accelerators分支" << endl;
            return;
        }
    }
    cout << "继续执行后续代码" << endl;
}

int main()
{
    InsertSpaces_Bug();
    InsertSpaces_Correct();
    return 0;
}

