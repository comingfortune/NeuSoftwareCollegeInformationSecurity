#pragma once
//�ݹ���쳲���������
#include<iostream>
using namespace std;
int fib( int n)
{
	if (n > 2)
		return fib(n - 1) + fib(n - 2);
	else
		return 1;
}
void lab1_5()
{
	int n;
	cout << "������Ҫ���쳲��������еĵڼ��" << endl;
	cin >> n;
	cout << "����Ϊ" << fib(n) << endl;
}