#include <iostream>

// 模拟 STDMETHODIMP
#define STDMETHODIMP void

// 模拟 ULONG
typedef unsigned long ULONG;

// 模拟函数
STDMETHODIMP Next(ULONG *pceltFetched)
{
    if (pceltFetched != NULL) {
        // 错误的写法：只递增了指针，没有递增指针指向的值
        *pceltFetched++;  // Bug: 运算符优先级问题
        
        // 正确的写法应该是：
        // (*pceltFetched)++;
    }
}

int main()
{
    ULONG value = 5;
    ULONG *ptr = &value;
    
    std::cout << "初始值: " << value << std::endl;
    std::cout << "指针地址: " << ptr << std::endl;
    
    Next(ptr);
    
    std::cout << "调用后值: " << value << std::endl;
    std::cout << "指针地址: " << ptr << std::endl;
    std::cout << "注意：值没有改变，但指针地址可能改变了" << std::endl;
    
    // 演示正确的写法
    value = 5;
    ptr = &value;
    std::cout << "\n使用正确写法:" << std::endl;
    std::cout << "初始值: " << value << std::endl;
    (*ptr)++;  // 正确的写法
    std::cout << "递增后值: " << value << std::endl;
    
    return 0;
}

