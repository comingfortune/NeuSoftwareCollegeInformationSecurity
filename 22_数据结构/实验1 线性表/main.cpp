#include<iostream>
#include<string>
#include<math.h>
using namespace std;
//����
typedef struct Node {
	int num;
	struct Node* prior, * next;
}Dlink;
//��ʼ��,����ͷ�ڵ�
Dlink *init()
{
	Dlink* head=NULL, * last=NULL, * p=NULL;
	char ch = {};
	int num = 0,flag=1;	//flag�����ж�����
	head = (Dlink*)malloc(sizeof(Dlink));
	head->next = NULL;
	head->prior = NULL;
	head->num = 0;
	while ((ch = getchar()) != ';')
	{
		//�����ڶ���������ǰ�Ļس�Ӱ�졣
		if (ch == '\n')
		{
			continue;
		}
		//�����ж�
		else if (ch == '-')
		{
			flag = -1;
		}
		else if (ch != ',')
		{
			num *= 10;
			num += ch - '0';
		}
		else
		{
			//��ֵ
			if (head->next == NULL)
			{
				head->num = num * flag;
			}
			else
			{
				p->num = num * flag;
			}
			p = (Dlink*)malloc(sizeof(Dlink));
			if (head->next == NULL)
			{
				head->next = p;
				p->prior = head;
				last = p;
			}
			else
			{
				p->prior = last;
				last->next = p;
				last = p;
			}
			num = 0;
			flag = 1;
		}
	}
	//ѭ��,ͷβ������
	if (head->next == NULL)
	{
		head->num = num * flag;
		head->next = head;
		head->prior = head;
	}
	else
	{
		p->num = num * flag;
		p->next = head;
		head->prior = p;
	}
	return head;	
}
//�ӷ����㣬����β���
Dlink* add(Dlink* a, Dlink* b)
{
	Dlink* a_temp = a->prior, * b_temp = b->prior;
	Dlink* tail,*p,*last=NULL;
	tail = (Dlink*)malloc(sizeof(Dlink)); //�Ӻ���ǰ������
	int temp = 0;	//��ʱ���������
	int flag = 1; //�жϽ������
	int num = 0; //�����ж�ѭ���ִ�
	last = tail;	//����ѭ������
	//ͬ�����
	if ((a->num >= 0 && b->num >= 0) || (a->num <= 0 && b->num <= 0))
	{
		//�ж�����
		if (a->num < 0)
		{
			flag = -1;
		}
/*		//�Ӻ���ǰ��
		temp = abs(a_temp->num) + abs(b_temp->num);
		tail->num = temp % 10000;
		temp /= 10000;
		//������ǰ��
		a_temp = a_temp->prior;
		b_temp = b_temp->prior;
		if (a_temp != a->prior || b_temp != b->prior)	//����δ������
		{
			p = (Dlink*)malloc(sizeof(Dlink));
			tail->prior = p;
			p->next = tail;
			last = p;
		}
		else if (temp == 1)				//���굫Ҫ��λ
		{
			p = (Dlink*)malloc(sizeof(Dlink));
			tail->prior = p;
			p->next = tail;
			p->prior = tail;
			tail->next = p;
			p->num = flag;
			return p;		//��λ��λ��1�ͺ����һ���ڵ㡣
		}
		else		//�������ȴ����.
		{
			tail->prior = tail;
			tail->next = tail;
			tail->num = tail->num * flag;
			return tail;	//����һ���ڵ�
		}*/
		//δ���������ǰ��
		while ((a_temp != a->prior && b_temp != b->prior) || num == 0)
		{
			last->num = (abs(a_temp->num) + abs(b_temp->num) + temp) % 10000;
			temp = (abs(a_temp->num) + abs(b_temp->num) + temp) / 10000;
			a_temp = a_temp->prior;
			b_temp = b_temp->prior;
			if (a_temp == a->prior)		
			{
				num = 1;
			}
			//�����������,���������ڴ�
			if (a_temp != a->prior || b_temp != b->prior)
			{
			p = (Dlink*)malloc(sizeof(Dlink));
			last->prior = p;
			p->next = last;
			last = p;
			}
			else if (temp==1) //�����޵�Ҫ��λ
			{
				p = (Dlink*)malloc(sizeof(Dlink));
				last->prior = p;
				p->next = last;
				p->num = flag;
				p->prior = tail;
				tail->next = p;
				return tail;
			}
			else   //�����λ
			{
				last->prior = tail;
				tail->next = last;
				last->num = last->num * flag;
				return tail;
			}
		}
		//�϶̳��ȵĶ���
		//a�ϳ�
		while (a_temp != a->prior)
		{
			last->num = (abs(a_temp->num) + temp) % 10000;
			temp = (abs(a_temp->num) + temp) / 10000;
			a_temp = a_temp->prior;
			if (a_temp != a->prior)
			{
				p = (Dlink*)malloc(sizeof(Dlink));
				last->prior = p;
				p->next = last;
				last = p;
			}
			else if (temp==1)	//��λ
			{
				p = (Dlink*)malloc(sizeof(Dlink));
				tail->prior = p;
				p->next = tail;
				p->prior = tail;
				tail->next = p;
				p->num = flag;
				return tail;
			}
			else
			{
				last->prior = tail;
				tail->next = last;
				last->num = last->num * flag;
				return tail;
			}

		}
		//b�ϳ�
		while(b_temp != b->prior)
		{
			last->num = (abs(b_temp->num) + temp) % 10000;
			temp = (abs(b_temp->num) + temp) / 10000;
			b_temp = b_temp->prior;
			if (b_temp != b->prior)
			{
				p = (Dlink*)malloc(sizeof(Dlink));
				last->prior = p;
				p->next = last;
				last = p;
			}
			else if (temp == 1)	//��λ
			{
				p = (Dlink*)malloc(sizeof(Dlink));
				tail->prior = p;
				p->next = tail;
				p->prior = tail;
				tail->next = p;
				p->num = flag;
				return tail;
			}
			else
			{
				last->prior = tail;
				tail->next = last;
				last->num = last->num * flag;
				return tail;
			}
		}
	}
	//������(���)
	else
	{
	// Ĭ�Ͻϴ��������С������
		int alen = 0, blen = 0, t = 0;	//t�����жϵȳ�ʱ˭�ϴ�
		while (a_temp != a->prior || alen == 0)
		{
			alen++;
			a_temp = a_temp->prior;
		}
		while (b_temp != b->prior || blen == 0)
		{
			blen++;
			b_temp = b_temp->prior;
		}
		if (alen == blen)
		{
			//�ȳ�����ǰ�����жϴ�С
			a_temp = a;
			b_temp = b;
			//��ȼ��������
			while (abs(a_temp->num) == abs(b_temp->num)&&num==0)
			{
				a_temp = a_temp->prior;
				b_temp = b_temp->prior;
				if (a_temp == a->prior)
				{
					num = 1;
				}
			}
			//�������ȳ�ʱ�˳�ѭ����
			if (abs(a_temp->num) == abs(b_temp->num))	//a+b=0
			{
				//a��b��Ϊ�෴����ֱ�ӷ���
				p = (Dlink*)malloc(sizeof(Dlink));
				p->prior = p;
				p->next = p;
				p->num = 0;
				return p;
			}
			else if (abs(a_temp->num) > abs(b_temp->num))
			{
				t = 1;
			}
			else
			{
				t = -1;
			}
		}
		//��ʼ��
		a_temp = a->prior;
		b_temp = b->prior;
		num = 0;
		if ((alen > blen) || t == 1)		//a����ֵ����
		{
			if (a->num < 0)
			{
				flag = -1;
			}
			while (a_temp != a->prior && b_temp != b->prior || num == 0)
			{
				if ((abs(a_temp->num) - abs(b_temp->num) + temp) >= 0)			//�����λ
				{
					last->num = abs(a_temp->num) - abs(b_temp->num) + temp;
					temp = 0;
				}
				else		//��λ
				{
					last->num = abs(a_temp->num) - abs(b_temp->num) + temp + 10000;
					temp = -1;
				}
				a_temp = a_temp->prior;
				b_temp = b_temp->prior;
					num = 1;
				p = (Dlink*)malloc(sizeof(Dlink));
				p->num = 0;   //������0����������ʵ�ʳ��Ƚ���ɾ����
				last->prior = p;
				p->next = last;
				last = p;
			}
			while (a_temp != a->prior)		//���ȳ�
			{
				if ((abs(a_temp->num) + temp) >= 0)
				{
					last->num = abs(a_temp->num) + temp;
					temp = 0;
				}
				else
				{
					last->num = 10000 + temp;
					temp = -1;
				}
				a_temp = a_temp->prior;
				p = (Dlink*)malloc(sizeof(Dlink));
				p->num = 0;   //������0����������ʵ�ʳ��Ƚ���ɾ����
				last->prior = p;
				p->next = last;
				last = p;
			}
		}
		if ((alen < blen) || t == -1)	//b�ľ���ֵ��
		{
			if (b->num < 0)
			{
				flag = -1;
			}
			while (a_temp != a->prior && b_temp != b->prior || num == 0)
			{
				if ((abs(b_temp->num) - abs(a_temp->num) + temp) >= 0)		//�����λ
				{
					last->num = abs(b_temp->num) - abs(a_temp->num) + temp;
					temp = 0;
				}
				else		//��λ
				{
					last->num = abs(b_temp->num) - abs(a_temp->num) + temp + 10000;
					temp = -1;
				}
				a_temp = a_temp->prior;
				b_temp = b_temp->prior;
				num = 1;
				p = (Dlink*)malloc(sizeof(Dlink));
				p->num = 0;   //������0����������ʵ�ʳ��Ƚ���ɾ����
				last->prior = p;
				p->next = last;
				last = p;
			}
			while (b_temp != b->prior)		//���ȳ�
			{
				if ((abs(b_temp->num) +temp) >= 0)
				{
					last->num = abs(b_temp->num) + temp;
					temp = 0;
				}
				else
				{
					last->num = 10000 + temp;
					temp = -1;
				}
				b_temp = b_temp->prior;
				p = (Dlink*)malloc(sizeof(Dlink));
				p->num = 0;   //������0����������ʵ�ʳ��Ƚ���ɾ����
				last->prior = p;
				p->next = last;
				last = p;
			}
		}
		while (last->num == 0)
		{
			last = last->next;
		}
		if (last != tail)
		{
			last->prior = tail;
			tail->next = last;
			last->num = last->num * flag;
		}
		else
		{
			tail->next = tail;
			tail->prior = tail;
			tail->num = tail->num * flag;
		}
		return tail;
	}
	return tail;
}
void putout(Dlink* p)
{
	Dlink* temp = p->next;
	cout << temp->num;
	if (temp != p)
	{
		cout << ",";
	}
	temp = temp->next;
	while ((temp != p->next))
	{
		if (temp->num >= 1000)//��λ��ֱ�����
		{
			cout << temp->num;
		}
		else if (temp->num >= 100)	//��λ������һ��0
		{
			cout << "0" << temp->num;
		}
		else if (temp->num >= 10)
		{
			cout << "00" << temp->num;	//��λ����������0
		}
		else if(temp->num > 0)
		{
			cout << "000" << temp->num;		//һλ������3��0
		}
		else
		{
			cout << "0000";		//0������ĸ�0
		}
		if (temp != p)
		{
			cout << ",";
		}
		temp = temp->next;

	}
}
int main()
{
	Dlink* a, * b, *tail;
	cout << "������a��ֵ�����ŷ�����Ʊ�ʾ����Ӣ�ķֺŽ�β��" << endl;
	a = init();
	cout << "������b��ֵ�����ŷ�����Ʊ�ʾ����Ӣ�ķֺŽ�β��" << endl;
	b = init();
	tail = add(a, b);
	cout << "����֮��Ϊ��" << endl;
	putout(tail);
	return 0;
}