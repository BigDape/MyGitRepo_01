#pragma once
#include <iostream>
class CxString//û��ʹ��explicit�ؼ��ֵ�����������Ĭ��Ϊ��ʽ����
{
public:
	char* _pstr;
	int _size;
	//CxString() {};
	explicit CxString(int size)
	{
		_size = size;//string��Ԥ���С
		_pstr =(char *) malloc(size+1);//����string���ڴ�
		memset(_pstr,0,size+1);
	}
	CxString(const char* p)
	{
		int size = strlen(p);
		_pstr = (char*)malloc(size + 1);
		strcpy(_pstr,p);
		_size = strlen(_pstr);
	}
	//��������
};

//�����ǵ���
int main()
{
	CxString string1(24);
//������OK��,ΪCxStringԤ����24�ֽڵĴ�С���ڴ�
	CxString string2 = 10;
//������OK�ģ�ΪCxStringԤ����10�ֽڵĴ�С���ڴ�
	CxString string3;
//�����ǲ��еģ���Ϊû��Ĭ�Ϲ��캯��������Ϊ��"CxString":
	//û�к��ʵ�Ĭ�Ϲ��캯������
	CxString string4("aaaa");
//������OK��
	CxString string5 = "bbb";
//����Ҳ��OK�ģ����õ���CxString(const char *p)
	CxString string6 = 'c';
//����Ҳ��ok�ģ���ʼ���õ���CxString(int size),��size����c��ascii��
	string1 = 2;
//����Ҳ��OK�ģ�ΪCxStringԤ����2�ֽڵĴ�С���ڴ�
	string2 = 3;
//����Ҳ��ok�ģ�ΪCXStringԤ����3�ֽڵĴ�С���ڴ�
	string3 = string1;
//����Ҳ��ok�ģ����ٱ�����û����ģ��������������������free�ͷ�_pstr
	//�ڴ��ʱ����ܻᱨ�������Ĵ���������������=���������д�����Ļ�����ͷš�
}
