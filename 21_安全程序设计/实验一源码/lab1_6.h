#pragma once
//����lab1_4���������������Ľ������
#include<iostream>
#include<math.h>
using namespace std;
void lab1_6()
{
	int a, b, c;
	cout << "���������a" << endl;
	cin >> a;
	cout << "������ָ��b" << endl;
	cin >> b;
	if (pow(a, b) <= INT_MAX)
	{
		c = pow(a, b);
		cout << a << "��" << b << "�η�Ϊ" << c << endl;
	}
	else
		cout << "��ֵ�����������" << endl;
}