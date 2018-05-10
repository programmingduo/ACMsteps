#include<iostream>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<memory.h>
#include<queue>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
struct node
{
	int pos,flag,h;
}e[10010];
bool cmp (node a,node b)
{
	if (a.pos!=b.pos)
		return a.pos<b.pos;
	if (a.flag!=b.flag)
		return a.flag<b.flag;
	if (a.flag)
		return a.h<b.h;	
	else
		return a.h>b.h;
}
int cnt;
multiset<int>m;
multiset<int>::iterator ite;
int main ()
{
	bool ok=0;
	int i,a,b,c;
	cnt=0;
	while (scanf("%d%d%d",&a,&c,&b)!=EOF)
	{
		e[cnt].pos=a,e[cnt].flag=0,e[cnt++].h=c;
		e[cnt].pos=b,e[cnt].flag=1,e[cnt++].h=c;
	}
	sort(e,e+cnt,cmp);
	m.insert(0);
	for (i=0;i<cnt;i++)
	{
		if (e[i].flag==0)
		{
			if (e[i].h>*(--m.end()))
			{
				if (ok)
					printf(" ");
				printf("%d %d",e[i].pos,e[i].h);
				ok=1;
			}
			m.insert(e[i].h);
		}
		else
		{
			a=*(--m.end());
			m.erase(m.find(e[i].h));
			b=*(--m.end());
			if (a>b)
			{
				if (ok)
					printf(" ");
				printf("%d %d",e[i].pos,b);
				ok=1;
			}
		}
	}
	printf("\n");
	return 0;
}
