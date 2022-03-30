#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	//n��Ӳ��
	FILE* Ip, * Op;
	int n;
	Ip = fopen("input.txt", "r");
	fscanf(Ip, "%d", &n);
	//coins����洢����Ӳ������
	int* coins = new int[n];
	for (int i = 0; i < n; i++)
	{
		fscanf(Ip, "%d", &coins[i]);
	}
	//mΪҪʵ�ֵ�Ǯ��
	int m = 0;
	fscanf(Ip, "%d",&m);
	int* dp = new int[m+1];
	fclose(Ip);
	/// 999Ĭ�ϱ�ʾ�Ҳ������ʷ�����������
	for (int i = 1; i <= m; i++)
	{
		dp[i] = 999;
	}
	//0Ԫ��Ҫ0��
	dp[0] = 0;
	//
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i >= coins[j])
			{
				dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
			}
		}
	}
	Op = fopen("output.txt", "w");
	if (dp[m] == 999)
	{
		fprintf(Op, "%s", "��");
	}
	else
	{
		fprintf(Op, "%d", dp[m]);
	}
	fclose(Op);
	delete[]dp;
	delete[]coins;
	return 0;
}