/*
��Ŀ���������ڶ��ֲ���
����2���ƣ���ϸ����
1->1
2->2
3->2
4->3
..
..
8->4
����֪����2^n--2^(n+1)֮��(������2^(n+1))�Ľ����n
����˳��ö�پͺ� 
ps��1<<ans ��Ϥλ���� 2^ans  
*/
#include <iostream>
using namespace std;
int t,n;
int main()
{
	int ans;
	while(scanf("%d",&t)!=EOF)
	{
		while(t--)
		{
			ans = 0;
			scanf("%d",&n);
			while(1)
			{
				if(n<(1<<ans))
					break;
				else
					ans++;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
