/*
���� 
ss[i]-'0'(���ַ�������ת��������������) 
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
