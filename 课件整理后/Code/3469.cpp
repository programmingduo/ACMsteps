/*
������Ŀ���������ǿ���֪��ÿ������װ��ƻ������һ����
�����Ǽ�ȥ�����ƻ����ʱ�򣬾�������������ƻ��
n-b1,m-b2�����⹫Լ����������Ϊ����װƻ��������������Ҫ�����
��Ȼ�������Լ����
����������Ƿ���a,b�����Լ�� 
int gcd(int a,int b)
{
	if(b == 0)
		return a;
	else
		return gcd(b,a%b);
} 
*/
#include <iostream>
using namespace std;
int n,m,b1,b2;
int t;
int gcd(int a,int b)
{
	if(b == 0)
		return a;
	else
		return gcd(b,a%b);
} 
int main()
{
	while(scanf("%d",&t)!=EOF)
	{
		while(t--)
		{
			scanf("%d%d%d%d",&n,&m,&b1,&b2);
			printf("%d\n",gcd(n-b1,m-b2));
		}
	}
	return 0;
}
