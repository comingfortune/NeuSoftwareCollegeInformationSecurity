#include<iostream>
#include<string>
using namespace std;
int main()
{
	char ch = '\0';
	char key[20] = {};
	char temp[27] = {};
	int i = 0, j = 0;
	cin >> key;
	int flag = 1;
	//���ɶ��ձ�
	//key����
	for (i = 0; i < strlen(key); i++) {		//��ȡkey
		flag = 1;
		for (j = 0; j < strlen(temp); j++) {
			if (temp[j] == key[i])
				flag = 0;
		}
		if (flag)
		{
			temp[j] = key[i];
		}

	}
	//ʣ�ಿ��
	for (i = 0; i < 26; i++)
	{
		flag = 1;
		for (j = 0; j < strlen(temp); j++)
		{
			if (temp[j] == (char)(i + 'a'))
			{
				flag = 0;
			}
		}
		if (flag)
		{
			temp[strlen(temp)] = (char)(i + 'a');
		}
	}
	//����
/*	while ((ch = getchar()) != ';')
	{
		if (ch >= 'a' && ch <= 'z')
		{
			cout << temp[ch - 'a'];
		}
	}*/
	//����
	while ((ch = getchar()) != ';')
	{
		if (ch >= 'a' && ch <= 'z')
		{
			int i = 0;
			while (temp[i]!=ch)
			{
				i++;
			}
			cout << (char)(i + 'a');
		}
	}
	return 0;
}