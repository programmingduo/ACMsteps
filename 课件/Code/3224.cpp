/*
�������ϸ�۲�ͻ��ҵ���ʽ
����ע��m,n�ķ�Χ m*n�Ľ���ᳬ��2^32
���������ʱ��Ҫ�� long long int  
*/
#include <iostream>
using namespace std;
int t,m,n;
int main()
{
	while(scanf("%d",&t)!=EOF)
	{
		while(t--)
		{
			scanf("%d%d",&m,&n);
			printf("%lld\n",(long long int)(m-1+(long long int)m*(n-1)));
		}
	}
	return 0;
}
