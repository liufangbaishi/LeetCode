#include <iostream>
using namespace std;
class String
{
public:
	String(const char* str = "")  // 注意NULL
	{
		if (str == NULL)
		{
			_str = new char[1];
			*_str = '\0';
		}
		else
		{
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
	}
	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			delete[] _str;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}
		return *this;
	}

	////////////////////拷贝构造函数/////////////////////////////////////
	//String(const String& s)
	//	: _str(NULL)
	//{
	//	String tmp(s._str);
	//	swap(_str, tmp._str);
	//}
	////////////////////赋值////////////////////////////////////////////
	//String& operator=(const String& s)
	//{
	//	if (this != &s)
	//	{
	//		String tmp(s);
	//		swap(_str, tmp._str);
	//	}
	//	return *this;
	//}
	//String& operator=(String s)// 值传递，调用拷贝构造函数，构建临时变量
	//{
	//	swap(_str, s._str);
	//	return *this;
	//}
	////////////////////////////////////////////////////////////////////////
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = NULL;
		}
	}
private:
	char* _str;
};

#include <string>
int main()
{
	String s = NULL; 
	String s1;
	String s2("abcd");
	String s3 = "abcd";
	String s4(s2);
	String s5;
	s5 = s2;
	return 0;
}