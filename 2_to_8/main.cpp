/*
 *Description
 *Code：2 to 8
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

void char_to_bit2()//将字符串一个一个存入二进制的栈中
{
	for (int i = Long_Q; i >= 0; i--)
	{
		Que_2.push(Read_que[i] - '0');//先存高位，这样从低位拿，转8方便
	}
	Long_Q++;
	return;
}

void bit2_to_bit8()//每3位进行一次2转8
{
	int j = 1,sum=0;
	int x, y, z;
	for(int i=1;i*3<=Long_Q;i++)//一次拿三个数
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
		Que_8.push(sum);//从最低位存入8进制，输出从高往低输出
	}
	
	x = 0; y = 0;//由于2转8是3位一转，则可能有没3位的，这里x和y记得要初始化
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
	if (sum)Que_8.push(sum);//0不存入栈，不然首位会出现0
	return;
}
void print()
{
	int x;
	while(!Que_8.empty())//从高位输出
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

