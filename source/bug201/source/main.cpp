#include <iostream>

typedef const char* LPCSTR;

/**
* 检查一个字符串是否是空字符串。
*/
bool CheckEmptyPassword(LPCSTR m_szPassword)
{
	if (m_szPassword != NULL)
	{
	    return true;
	}
    if (m_szPassword != '\0')
    {
        return true;
    }
	return false;
}

//const char* ClientResponse(LPCSTR ServerChallenge)
//{
//    m_szPassword = "";
////	...
//	if (m_szPassword != NULL)
//	{
////		...
//		if (m_szPassword != '\0')
//		{
////			...
//            std::cout << "密码 " << m_szPassword << " 合法吗?" << std::endl;
//		}
//	}
//	return "";
//}


int main()
{
    std::cout << CheckEmptyPassword("password") << std::endl;
    std::cout << CheckEmptyPassword("") << std::endl;
    return 0;
}