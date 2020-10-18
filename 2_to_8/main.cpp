/*
 *Description
 *Code��2 to 8
 *Auther:banned
 *Last Edit time:2020/10/18 13:00 
 */



#include<cstdio>
#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

#define N 114514

stack <int> Que_2;
stack <int> Que_8;
int Long_Q;
char Read_que[N];

void char_to_bit2()//���ַ���һ��һ����������Ƶ�ջ��
{
	for (int i = Long_Q; i >= 0; i--)
	{
		Que_2.push(Read_que[i] - '0');//�ȴ��λ�������ӵ�λ�ã�ת8����
	}
	Long_Q++;
	return;
}

void bit2_to_bit8()//ÿ3λ����һ��2ת8
{
	int j = 1,sum=0;
	int x, y, z;
	for(int i=1;i*3<=Long_Q;i++)//һ����������
	{
		sum = 0;
		x = Que_2.top();
		Que_2.pop();
		y = Que_2.top();
		Que_2.pop();
		z = Que_2.top();
		Que_2.pop();

		sum += x + y * 2 + z * 4;
		//cout << sum;
		Que_8.push(sum);//�����λ����8���ƣ�����Ӹ��������
	}
	
	x = 0; y = 0;//����2ת8��3λһת���������û3λ�ģ�����x��y�ǵ�Ҫ��ʼ��
	if(!Que_2.empty())
	{
		x = Que_2.top();
		Que_2.pop();
	}
	if (!Que_2.empty())
	{
		y = Que_2.top();
		Que_2.pop();
	}
	sum = x + 2 * y;
	if (sum)Que_8.push(sum);//0������ջ����Ȼ��λ�����0
	return;
}
void print()
{
	int x;
	while(!Que_8.empty())//�Ӹ�λ���
	{
		x = Que_8.top();
		Que_8.pop();
		cout << x;
	}
	return;
}
int main()
{
	cin >> Read_que;
	Long_Q = strlen(Read_que)-2;
	//cout << Long_Q;
	char_to_bit2();
	bit2_to_bit8();
	print();
	return 0;
}

