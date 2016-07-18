/*
因为只从第一个串中删除数字，所以策略是比较两个串的数字，相同时，指针同时后移
不同时，第一个串的指针后移，如果第二个串的指针到最后没能指向最后一个数字的下
一位的时候，我们判定no，否则yes
ps：这个不知道叫不叫贪心 
*/
#include <iostream>
using namespace std;
#define maxn 110
char s1[maxn];
char s2[maxn];
int n;
int main()
{
	int len1,len2,t1,t2,flag;
	while(scanf("%d",&n)!=EOF)
	{
		while(n--)
		{
			scanf("%s",&s1);
			scanf("%s",&s2);
			len1 = strlen(s1);
			len2 = strlen(s2);
			t1 = t2 = 0;
			flag = 0;
			while(t1<len1&&t2<len2)
			{
				if(s1[t1]==s2[t2])
				{
					t1++; t2++;
				}
				else
				{
					t1++;
				}
				if(t2==len2)
				{
					flag = 1;
					break;
				}
			}
			if(flag == 1)
				printf("yes\n");
			else
				printf("no\n");
		}
	}
	return 0;
}
