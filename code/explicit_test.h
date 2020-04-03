#pragma once
#include <iostream>
class CxString//没有使用explicit关键字的类声明，即默认为隐式声明
{
public:
	char* _pstr;
	int _size;
	//CxString() {};
	explicit CxString(int size)
	{
		_size = size;//string的预设大小
		_pstr =(char *) malloc(size+1);//分配string的内存
		memset(_pstr,0,size+1);
	}
	CxString(const char* p)
	{
		int size = strlen(p);
		_pstr = (char*)malloc(size + 1);
		strcpy(_pstr,p);
		_size = strlen(_pstr);
	}
	//析构函数
};

//下面是调用
int main()
{
	CxString string1(24);
//这样是OK的,为CxString预分配24字节的大小的内存
	CxString string2 = 10;
//这样是OK的，为CxString预分配10字节的大小的内存
	CxString string3;
//这样是不行的，因为没有默认构造函数，错误为："CxString":
	//没有合适的默认构造函数可用
	CxString string4("aaaa");
//这样是OK的
	CxString string5 = "bbb";
//这样也是OK的，调用的是CxString(const char *p)
	CxString string6 = 'c';
//这样也是ok的，起始调用的是CxString(int size),且size等于c的ascii码
	string1 = 2;
//这样也是OK的，为CxString预分配2字节的大小的内存
	string2 = 3;
//这样也是ok的，为CXString预分配3字节的大小的内存
	string3 = string1;
//这样也是ok的，至少编译是没问题的，但是如果析构函数里用free释放_pstr
	//内存的时候可能会报错，完整的代码必须重载运算符=，并在其中处理内幕才能释放。
}
