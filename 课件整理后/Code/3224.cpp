/*
这个题仔细观察就会找到公式
但是注意m,n的范围 m*n的结果会超过2^32
所以输出的时候要用 long long int  
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
