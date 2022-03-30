#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <winsock2.h>
#include "DH.h"
#pragma comment (lib, "ws2_32.lib")  //���� ws2_32.dll

int main() {
    //��ʼ�� DLL
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    //�����׽���
    SOCKET servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    //���׽���
    sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));  //ÿ���ֽڶ���0���
    sockAddr.sin_family = PF_INET;  //ʹ��IPv4��ַ
    sockAddr.sin_addr.s_addr = INADDR_ANY;  //�����IP��ַ
    sockAddr.sin_port = htons(1234);  //�˿�
    bind(servSock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
    //�������״̬
    listen(servSock, 20);
	//�����������
    ll a;
    ll p;
    FILE *fp;
    fp=fopen("prime_number.txt","r");
    fscanf(fp,"%lld",&p);
    fscanf(fp,"%lld",&a);
    fclose(fp);
	srand((unsigned)time(NULL));
    ll Xa = rand() % p;
	ll Ya = q_pow(a, Xa, p);
    printf("����������ѡȡ����Ϊ%lld\n",Xa);
    //���տͻ�������
    SOCKADDR clntAddr;
    int nSize = sizeof(SOCKADDR);
    char ch[100]={};
    itoa(Ya,ch,10);
    char* str=ch;
    SOCKET clntSock = accept(servSock, (SOCKADDR*)&clntAddr, &nSize);
    //��ͻ��˷�������
    send(clntSock, str, strlen(str)+sizeof(char), 0);
    char szBuffer[MAXBYTE] = {};
    recv(clntSock, szBuffer, MAXBYTE, 0);
    //�ر��׽���
    printf("�ӿͻ��˶˽��յ�������Ϊ: %s\n", szBuffer);
    int Yb=0;
    for(int i=0;szBuffer[i]!='\0';i++)
    {
        Yb*=10;
        Yb+=szBuffer[i]-'0';
    }
    ll Ka=q_pow(Yb,Xa,p);
    printf("B���������ԿΪ��%lld\n",Ka);
    closesocket(clntSock);
    closesocket(servSock);

    //��ֹ DLL ��ʹ��
    WSACleanup();

    return 0;
}