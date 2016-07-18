/*
排序的简单应用 
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 1003
struct Car
{
	int id,spd,ctrl;
}car[maxn];
int t,n,k;
bool cmp(const Car &c1,const Car &c2)
{
	if(c1.spd != c2.spd)
		return c1.spd > c2.spd;
	else
		return c1.ctrl > c2.ctrl;
}
int main()
{
	int i;
	while(scanf("%d",&t)!=EOF)
	{
		while(t--)
		{
			scanf("%d%d",&n,&k);
			for(i=0;i<n;i++)
			{
				scanf("%d%d%d",&car[i].id,&car[i].spd,&car[i].ctrl);
			}
			sort(car,car+n,cmp);
			printf("%d\n",car[k-1].id);
		}
	}
	return 0;
}
