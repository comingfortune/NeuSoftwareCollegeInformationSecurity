#pragma once
//���ƺ�������
#include<iostream>
using namespace std;
int max1(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}
int max1(int x, int y, int z)
{
	int temp = x;
	if (y > temp)
		temp = y;
	if (z > temp)
		temp = z;
	return temp;
}
double max1(double x, double y)
{
	if (x > y)
		return x;
	else
		return y;
}
double max1(double x, double y, double z)
{
	double temp = x;
	if (y > temp)
		temp = y;
	if (z > temp)
		temp = z;
	return temp;
}
//����
void lab1_2()
{
	float a1, b1, c1;
	int a2, b2, c2;
	cout << "��������������" << endl;
	cin >> a2 >> b2;
	cout <<"���ֵΪ��"<< max1(a2, b2) << endl;
	cout << "��������������" << endl;
	cin >> a2 >> b2 >> c2;
	cout << "���ֵΪ��" << max1(a2, b2, c2) << endl;
	cout << "����������������" << endl;
	cin >> a1 >> b1;
	cout << "���ֵΪ��" << max1(a1, b1) << endl;
	cout  << "����������������" << endl;
	cin >> a1 >> b1 >> c1;
	cout << "���ֵΪ��" << max1(a1, b1, c1) << endl;
}