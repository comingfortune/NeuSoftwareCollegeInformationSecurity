#include "DH.h"
#include<stdio.h>
#include <sys/time.h>

int main()
{
    int m = 1000;
	ll* ptr = initprime(m);
	srand((unsigned)time(NULL));
	ll p = ptr[rand() % m];
	//����p����Сԭ��a
	ll a = pri_root(p);
    printf("��Կp:%lld,a:%lld",p,a);
    FILE *fp;
    fp=fopen("prime_number.txt","w");
    fprintf(fp,"%lld\n",p);
    fprintf(fp,"%lld",a);
    fclose(fp);
    return 0;
}