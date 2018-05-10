/*
简单的计算几何练习题 
*/
#include <iostream>
using namespace std;
#define maxn 505
struct Point
{
	int x,y;
}p[maxn];
int n;
int dis(Point a,Point b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int main()
{
	int i,j,dmax;
	int ans1,ans2,len;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&p[i].x,&p[i].y);
		}
		dmax = -1;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				len = dis(p[i],p[j]);
				if(len > dmax)
				{
					dmax = len;
					ans1 = i + 1;
					ans2 = j + 1;
				}
			}
		}
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}
