#pragma once
//���϶�ת���϶�
#include<iostream>
using namespace std;
float Convert(float TempFer)
{
	return 5 * (TempFer - 32) / 9;
}
//����
void lab1_1()
{
	float t1, t2;
	cout << "������Ҫת���Ļ����¶ȣ���λ���H��" << endl;
	cin >> t1;
	t2 = Convert(t1);
	cout << "��Ӧ�������¶�Ϊ��" << t2 << "��" << endl;
}
