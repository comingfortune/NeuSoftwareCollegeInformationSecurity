#include<iostream>
#include"lab1_1.h"
#include"lab1_2.h"
#include"lab1_3.h"
#include"lab1_4.h"
#include"lab1_5.h"
#include"lab1_6.h"
using namespace std;
//���϶�ת���϶�
void fun()
{
	cout << "������Ҫ���еĳ�����,��0�˳�(1,2,3��)��" << endl;
	cout << "1.���϶�ת���϶�" << endl;
	cout << "2.�ֶ���д��������" << endl;
	cout << "3.ͨ������ģ��ʵ�ֺ�������" << endl;
	cout << "4.ʹ��ϵͳ�������a��b�η�" << endl;
	cout << "5.��쳲��������е�n��" << endl;
	cout << "6.ʹ��ϵͳ������a��b�η�������жϣ�" << endl;
}
int main()
{
	int a;
	fun();
	cin >> a;
	while (a)
	{
		switch (a)
		{
		case 1:
			lab1_1();
			break;
		case 2:
			lab1_2();
			break;
		case 3:
			lab1_3();
			break;
		case 4:
			lab1_4();
			break;
		case 5:
			lab1_5();
			break;
		case 6:
			lab1_6();
			break;
		default:
			cout<<"�����������������:";
		}
		system("pause");
		system("cls");
		fun();
		cin >> a;
	}
	cout << "^_^���ε��Խ�������ӭ�´�ʹ�á�^_^" << endl;
	return 0;
}
