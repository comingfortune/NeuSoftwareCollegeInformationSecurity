#pragma once
#include<iostream>
using namespace std;
char* Strfnd(char* a, char* b)
{
	int i=1, j=0;
	char* temp = a;
	//�ַ���b���ַ����ַ���a��ƥ��
	{
		while (*temp != '\0')
		{
			if (*temp == *b)
			{
				//�жϺ����ַ��Ƿ����
				char* p1 = temp, * p2 = b;
				while (*p2 != '\0')
				{
					if (*p1 != *p2)
						goto loop;
					p1++;
					p2++;
				}
				//��ʾ�ַ���b��a��λ��
				char* x = a;
				while (x != temp)
				{
					i++;
					x++;
				}
				x = b+1;
				while (*x++ != '\0')
				{
					j++;
				}
				cout << "�ַ���"<<b<<"λ���ַ���"<<a<<"��" << i << "~" << i + j << "λ" << endl;
				return 0;
			}
loop:		temp++;
		}
	}
	cout << "δ���ַ���"<<a<<"�в��ҵ��ַ���" <<b<< endl;
	return 0;
}
void lab2_3()
{
	char a[100], b[50];
	cout << "�������ַ���1��Ҫ��1�в��ҵ��ַ���2" << endl;
	cin >> a >> b;
	Strfnd(a, b);
}