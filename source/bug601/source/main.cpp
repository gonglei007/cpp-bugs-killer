#include <iostream>
using namespace std;

class Complex
{
public:
    double real, imag;
    
    Complex() : real(0.0), imag(0.0) {}
    Complex(double r, double i) : real(r), imag(i) {}
    
    void print() const {
        cout << "(" << real << ", " << imag << ")" << endl;
    }
};

// 有bug的版本：返回引用
Complex& operator+(Complex& a, Complex& b)
{
    Complex *p = new Complex;  // Bug: 内存泄漏
    p->real = a.real + b.real;
    p->imag = a.imag + b.imag;
    return *p;  // Bug: 返回局部分配对象的引用
}

// 正确的版本1：返回对象（推荐）
Complex operator+(const Complex& a, const Complex& b)
{
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;  // 返回对象，编译器会进行优化（RVO）
}

int main()
{
    Complex a(1.0, 2.0);
    Complex b(3.0, 4.0);
    
    cout << "a = ";
    a.print();
    cout << "b = ";
    b.print();
    
    // 有bug的版本（注释掉，避免内存泄漏）
    // Complex& c_bug = a + b;  // Bug: 无法释放内存
    // cout << "c_bug = ";
    // c_bug.print();
    // delete &c_bug;  // 这样写很危险且不符合习惯
    
    // 正确的版本
    Complex c = a + b;  // 正确：返回对象
    cout << "c = a + b = ";
    c.print();
    
    return 0;
}
