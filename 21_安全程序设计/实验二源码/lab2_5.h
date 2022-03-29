#pragma once
#include<iostream>
using namespace std;
class Vehicle2 //������
{
public:
	virtual void Run()
	{
		cout << "��������	";
	}
	virtual void Stop()
	{
		cout << "��ͣ��" << endl;
	}
};
class Bicycle2 :public Vehicle2 //���г�������
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
class Motorcar2 :public Vehicle2 //����������
{
public:
	void Run()
	{
		cout << "����������	";
	}
	void Stop()
	{
		cout << "����ͣ��" << endl;
	}
};

class Motorcycle2 :public Bicycle2, public Motorcar2 //Ħ�г�������
{
public:
	void Run()
	{
		cout << "Ħ�г�������	";
	}
	void Stop()
	{
		cout << "Ħ�г�ͣ��" << endl;
	}
};
void lab2_5()
{
	cout << "δʹ��ָ�룺" << endl;
	//Vehicle����󲢵�����Run()��Stop()����
	Vehicle2 v;
	v.Run();
	v.Stop();
	//Bicycle����󲢵�����Run()��Stop()����
	Bicycle2 b;
	b.Run();
	b.Stop();
	//Motorcar����󲢵�����Run()��Stop()����
	Motorcar2 m;
	m.Run();
	m.Stop();
	//Motorcycle����󲢵�����Run()��Stop()����
	Motorcycle2 mc;
	mc.Run();
	mc.Stop();
	cout << "ʹ��ָ�룺" << endl;
	//ͨ��ָ��ʵ��
	Vehicle2* p;
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
