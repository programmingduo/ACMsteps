/*
��Ϊֻ�ӵ�һ������ɾ�����֣����Բ����ǱȽ������������֣���ͬʱ��ָ��ͬʱ����
��ͬʱ����һ������ָ����ƣ�����ڶ�������ָ�뵽���û��ָ�����һ�����ֵ���
һλ��ʱ�������ж�no������yes
ps�������֪���в���̰�� 
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
