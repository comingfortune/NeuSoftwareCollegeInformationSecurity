#pragma once
#include<iostream>
using namespace std;
char* Strcpy(char* a,char* b)
{
	while (*b!= '\0')
	{
		*a = *b;
		a++;
		b++;
	}
	*a = '\0';
	return a;
}
void lab2_1()
{
	char a[100], b[100];
	cout << "�������ַ���a,b" << endl;
	cin >> a >> b;
	cout << "����ǰ:" << endl << "a = " << a << endl << "b = " << b << endl;
	Strcpy(a, b);
	cout << "������:" << endl << "a = " << a << endl << "b = " << b << endl;
}
