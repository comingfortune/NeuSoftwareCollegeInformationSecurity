#pragma once
//ͨ������ģ��ʵ�ֺ�������
#include<iostream>
using namespace std;
template<typename T>
T max1(T x, T y)
{
	if (x > y)
		return x;
	else
		return y;
}
template<typename T>
T max1(T x, T y, T z)
{
	T temp = x;
	if (y > temp)
		temp = y;
	if (z > temp)
		temp = z;
	return temp;
}
//����
void lab1_3()
{
	float a1, b1, c1;
	int a2, b2, c2;
	cout << "��������������" << endl;
	cin >> a2 >> b2;
	cout << "���ֵΪ��" << max1(a2, b2) << endl;
	cout << "��������������" << endl;
	cin >> a2 >> b2 >> c2;
	cout << "���ֵΪ��" << max1(a2, b2, c2) << endl;
	cout << "����������������" << endl;
	cin >> a1 >> b1;
	cout << max1(a1, b1) << endl;
	cout << "����������������" << endl;
	cin >> a1 >> b1 >> c1;
	cout << "���ֵΪ��" << max1(a1, b1, c1) << endl;
}