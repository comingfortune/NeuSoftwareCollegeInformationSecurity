#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>
#include <sys/time.h>
#include "DH.h"
#pragma comment (lib, "ws2_32.lib")  //���� ws2_32.dll
int main(){
    //��ʼ��DLL
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    //�����׽���
    SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
        ll a;
    ll p;
    FILE *fp;
    fp=fopen("prime_number.txt","r");
    fscanf(fp,"%lld",&p);
    fscanf(fp,"%lld",&a);
    fclose(fp);
	srand((unsigned)time(NULL));
    ll Xb = rand() % p;
	ll Yb = q_pow(a, Xb, p);
    printf("�ͻ�����ѡȡ����Ϊ%lld\n",Xb);
    //���������������
    sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));  //ÿ���ֽڶ���0���
    sockAddr.sin_family = PF_INET;
    sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    sockAddr.sin_port = htons(1234);
    connect(sock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
    //���շ��������ص�����
    char szBuffer[MAXBYTE] = {};
    recv(sock, szBuffer, MAXBYTE, 0);
    char ch[100]={};
    itoa(Yb,ch,10);
    char* str=ch;
    send(sock, str, strlen(str)+sizeof(char), 0);
    //������յ�������
    printf("�ӷ������˽��յ�������Ϊ: %s\n", szBuffer);
    int Ya=0;
    for(int i=0;szBuffer[i]!='\0';i++)
    {
        Ya*=10;
        Ya+=szBuffer[i]-'0';
    }
    ll Kb=q_pow(Ya,Xb,p);
    printf("B���������ԿΪ��%lld\n",Kb);
    //�ر��׽���
    closesocket(sock);

    //��ֹʹ�� DLL
    WSACleanup();

    system("pause");
    return 0;
}