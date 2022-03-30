#include<iostream>
using namespace std;
//  ������ջ
typedef struct Stack_Operand
{
	int num;	//��ֵ
	struct Stack_Operand* next; //��ջ˳��
	struct Stack_Operand* prior = NULL; //��ջ˳��
}opd;
// �����ջ
typedef struct Stack_Operator
{
	char op = '\0';
	struct Stack_Operator* next;
	struct Stack_Operator* prior = NULL;
}opr;
int num_temp = 0;
char ch_temp = '\0';
// ��������ջ
opd* opd_push(opd* last, int data)
{
	opd* temp;
	temp = (opd*)malloc(sizeof(opd));
	temp->num = 0;
	temp->next = NULL;
	temp->prior = last;
	last->num = data;
	last->next = temp;
	return temp;
}
//�������ջ
opr* opr_push(opr* last, char ch)
{
	opr* temp;
	temp = (opr*)malloc(sizeof(opr));
	temp->next = NULL;
	temp->prior = last;
	temp->op = '\0';
	last->op = ch;
	last->next = temp;
	return temp;
}
//��������ջ
opd* opd_pop(opd* top)
{
	//ջ���ǿյ�

	//��ǰλ����Ϊ�µ�ջ��
	if (top->prior != NULL)
	{
		opd* temp = top->prior;
		num_temp = temp->num;	//��������Ԫ��
		top = top->prior;
		free(temp->next);
		return top;
	}
}
//�������ջ
opr* opr_pop(opr* top)
{
	//��ǰλ����Ϊ�µ�ջ��
	if (top->prior != NULL)
	{
		opr* temp = top->prior;
		ch_temp = temp->op;
		top->op = '\0';
		top = top->prior;
		free(temp->next);
		return top;
	}
}
//�ı�ջ��Ԫ��
opd* cal(opd* top)
{
	switch (ch_temp)
	{
	case '+':
		top->prior->num += num_temp;
		break;
	case '-':
		top->prior->num -= num_temp;
		break;
	case '*':
		top->prior->num *= num_temp;
		break;
	case '/':
		top->prior->num /= num_temp;
		break;
	default:
		break;
	}
	return top;
}
int pri_opr(char ch1, char ch2) //��������ȼ��Ƚ�
{	
	//ch1Ϊջ���������ch2Ϊ��ǰɨ�赽�����
	//��ǰΪ')'��һ����ջ
	if (ch2 == ')')
	{
		return 0;
	}
	//ջ��Ϊ*/��ֻҪ��ǰ����'('����ջ
	else if ((ch1 == '*' || ch1 == '/') && (ch2 != '('))
	{
		return 0;
	}
	//ջ��Ϊ+-����ǰΪ+-��ջ
	else if ((ch1 == '+' || ch1 == '-') && (ch2 == '+' || ch2 == '-'))
	{
		return 0;
	}
	//�������ջ
	else
	{
		return 1;
	}
}
int init(opd* stack1, opr* stack2)
{
	int ans = 0; //������
	int num = 0; //����������
	char ch='\0',ch1='\0'; //ch1,ch���ڱȽ�����������ȼ�
	while ((ch = getchar()) != ';')
	{
		//������
		if (ch >= '0' && ch <= '9')
		{
			num *= 10;
			num += ch - '0';
		}
		//�����
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')')
		{
			//���������ʱ��������ջ
			if (ch != '(' && ch_temp != '(')
			{
				stack1 = opd_push(stack1, num);
			}
			num = 0;
			if (stack2->prior != NULL)
			{
				ch1 = stack2->prior->op;	//ջ��Ԫ��

			//�ж��������ջ���ǳ�ջ
				if (pri_opr(ch1, ch))
				{
					stack2 = opr_push(stack2, ch);
				}
				else
				{
					//�����ǰ��������ȼ�һֱС��ջ����������ȼ���һֱ��
					//���������Ż�ǰ��������ȼ�����ջ��Ϊֹ
					if (ch == ')')
					{
						while (ch1 != '(')
						{
							stack2 = opr_pop(stack2);
							stack1 = opd_pop(stack1);
							stack1 = cal(stack1);
							ch1 = stack2->prior->op;
						}
						stack2 = opr_pop(stack2);
					}
					else   //���������Ϊ���������Ŷ���ջ��һֱ��
					{
						while (!pri_opr(ch1, ch))
						{
							//�����Ĳ������������
							stack2 = opr_pop(stack2);
							stack1 = opd_pop(stack1);
							stack1 = cal(stack1);
							if (stack2->prior != NULL)
							{
								ch1 = stack2->prior->op;
							}
							else
								break;
						}
						stack2 = opr_push(stack2, ch);
					}
				}
			}
			else
			{
				stack2 = opr_push(stack2, ch);
			}
		}
	}
	//ɨ����������һ������ջ
	if (ch_temp != '(')
	{
		stack1 = opd_push(stack1, num);
	}
	//ȫ��������

	while (stack2->prior != NULL)
	{
		stack2 = opr_pop(stack2);
		stack1 = opd_pop(stack1);
		stack1 = cal(stack1);

	}
	ans = stack1->prior->num;
	return ans;
}
int main()
{
	opd* head1 = (opd*)malloc(sizeof(opd));
	head1->prior = NULL;
	opr* head2 = (opr*)malloc(sizeof(opr));
	head2->prior = NULL;
	cout << "������Ҫ�����������׺���ʽ����;��β" << endl;
	int a = init(head1, head2);
	cout << "������Ϊ";
	cout << a << endl;
	cout << "�Ƿ�������㣿 ��Y����";
	char ch = '\0';
	cin >> ch;
	while (ch == 'Y' || ch == 'y')
	{
		cout << "������Ҫ�����������׺���ʽ����;��β" << endl;
		int a = init(head1, head2);
		cout << "������Ϊ";
		cout << a << endl;
		cout << "�Ƿ�������㣿 ��Y����";
		cin >> ch;
	}
	system("pause");
	return 0;
}