/*
对于每次查询我们要知道它所属的区间
属于区间的条件 (tt<=s[mid].v&&tt>=s[mid].u)
tt为查询目标
顺序查找可以，但是时间上不允许
这里看出区间左右端点相互连续，是递增的
因此可以利用二分查找
当 tt > s[mid].v 说明查询肯定在我当前考虑区间的右边
所以我们不再查找左边的区间，去查找右边的即可 查找左区间变为st = mid + 1
当 tt < s[mid].u 说明查询肯定在我当前考虑区间的左边
同理查找右区间变为 ed = mid - 1
当 tt<=s[mid].v&&tt>=s[mid].u 说明查询在考虑的区间内部
输出结果 
*/
#include <iostream>
#include <cstring>
using namespace std;
#define maxn  50003
int n,q;
struct SS
{
	int u,v;
}s[maxn];
int main()
{
	int tmp,i,tt,ans;
	int st,ed,mid;
	while(scanf("%d%d",&n,&q)!=EOF)
	{
		tmp = 0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&tt);
			s[i].u = tmp;
			s[i].v = tmp + tt - 1;
			tmp = s[i].v + 1;
		}
		while(q--)
		{
			scanf("%d",&tt);
			st = 0; ed = n;
			while(st <= ed)
			{
				mid = (st + ed)>>1;
				if(tt<=s[mid].v&&tt>=s[mid].u)
				{
					ans = mid + 1;
					break;
				}
				else if(tt > s[mid].v)
				{
					st = mid + 1;
				}
				else
					ed = mid - 1;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
