//Project - Macro
#include <iostream>
using namespace std;

#define SQUARE(x)  x*x

int main() {
    cout << SQUARE(3) << endl;      //3的平方，预期输出为9
    cout << SQUARE(3+2) << endl;    //3+2的平方，预期输出为5的平方，即25
    return 0;
}
