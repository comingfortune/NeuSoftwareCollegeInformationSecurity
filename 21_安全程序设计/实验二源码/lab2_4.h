#pragma once
#include<iostream>
using namespace std;
class Vehicle1 //������
{
public:
	void Run()
	{
		cout << "��������	" ;
	}
	void Stop()
	{
		cout << "��ͣ��" << endl;
	}
};
class Bicycle1:public Vehicle1 //���г�������
{
public:
	void Run()
	{
		cout << "���г�������	";
	}
	void Stop()
	{
		cout << "���г�ͣ��" << endl;
	}
};
class Motorcar1 :public Vehicle1 //����������
{
public:
	void Run()
	{
		cout << "����������	" ;
	}
	void Stop()
	{
		cout << "����ͣ��" << endl;
	}
};

class Motorcycle1 :public Bicycle1, public Motorcar1 //Ħ�г�������
{
public:
	void Run()
	{
		cout << "Ħ�г�������	" ;
	}
	void Stop()
	{
		cout << "Ħ�г�ͣ��" << endl;
	}
};
void lab2_4()
{
	cout << "δʹ��ָ�룺" << endl;
	//Vehicle����󲢵�����Run()��Stop()����
	Vehicle1 v;
	v.Run();
	v.Stop();
	//Bicycle����󲢵�����Run()��Stop()����
	Bicycle1 b;
	b.Run();
	b.Stop();
	//Motorcar����󲢵�����Run()��Stop()����
	Motorcar1 m;
	m.Run();
	m.Stop();
	//Motorcycle����󲢵�����Run()��Stop()����
	Motorcycle1 mc;
	mc.Run();
	mc.Stop();
	cout << "ʹ��ָ�룺" << endl;
	//ͨ��ָ��ʵ��
	Vehicle1* p;
	//Vehicle���͵�ָ��������Vehicle�����ĳ�Ա����
	p = &v;
	p->Run();
	p->Stop();
	//Vehicle���͵�ָ��������Bicycle�����ĳ�Ա����
	p = &b;
	p->Run();
	p->Stop();
	//Vehicle���͵�ָ��������Motorcar�����ĳ�Ա����
	p = &m;
	p->Run();
	p->Stop();
}