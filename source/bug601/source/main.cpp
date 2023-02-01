#include <stdio.h>
#include <iostream>
using namespace std;

class Complex
{
	public:
	double real, imag;
	Complex(double inReal, double inImaq)
	{
	    real = inReal;
	    imag = inImaq;
	}

    Complex& operator+( Complex& a, Complex& b);
	void Output();
};

Complex& Complex::operator+( Complex& a, Complex& b)
{
	Complex *p = new Complex;
	p->real = a.real + b.real;
	p->imag = a.imag + b.imag;
	return *p;
}

void Complex::Output()
{
    cout << "real=" << this.real <<endl;
    cout << "imaq=" << this.imaq <<endl;
}


int main()
{
    Complex c1(10, 20);
    Complex c2(30, 40);
    Complex result = c1+c2;
    result.Output();
    return 0;
}
