#pragma once
#include<iostream>
using namespace std;
char* Strcat(char* p1, char* p2)
{
	char* p = p1;
	//pָ��p1��β
	while (*p1!='\0')
	{
		p1++;
		p++;
	}
	//��p2д��p��ָλ��
	while (*p2!='\0')
	{
		*p = *p2;
		p++;
		p2++;
	}
	*p = '\0';
	return p1;
}

void lab2_2()
{
	char a[100], b[50];
	cout << "�������ַ���a,b" << endl;
	cin >> a >>  b;
	cout << "����ǰ��" << endl << "a = " << a << "\t" << "b = " << b << endl;
	Strcat(a, b);
	cout << "���Ӻ�" << endl << "a = " << a << "\t" << "b = " << b << endl;
}