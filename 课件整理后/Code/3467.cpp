/*
简单题 
ss[i]-'0'(将字符型数字转化成数字型数字) 
*/ 
#include <iostream>
using namespace std;
#define maxn 14
char ss[maxn];
int t;
int main()
{
	int ans,i;
	while(scanf("%d",&t)!=EOF)
	{
		while(t--)
		{
			ans = 0;
			scanf("%s",&ss);
			for(i=0;i<strlen(ss);i++)
			{
				ans += ss[i] - '0';
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
