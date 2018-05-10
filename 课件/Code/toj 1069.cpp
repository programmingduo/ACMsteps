#include<iostream>//team177 598660
#include<memory.h>
#include<stdio.h>
#include<map>
#include<string>
#include<queue>
#include<limits.h>
using namespace std;
map<string,int>mm;
string name[100010][2],q[100010];
struct node
{
	int b,c,next;
}e[1000020];
int cnt,v[100100];
void add (int a,int b,int c)
{
	e[cnt].b=b;
	e[cnt].c=c;
	e[cnt].next=v[a];
	v[a]=cnt++;
}
int mark[100010],dis[100010];
void spfa(int s)
{
	int i,a,b,c;
	queue<int>q;
	memset(mark,0,sizeof(mark));
	for (i=0;i<100010;i++)
		dis[i]=INT_MAX;
	mark[s]=1;
	dis[s]=0;
	q.push(s);
	while (!q.empty())
	{
		a=q.front();
		q.pop();
		mark[a]=0;
		for (i=v[a];i!=-1;i=e[i].next)
		{
			b=e[i].b;
			c=e[i].c;
			if (dis[a]+c<dis[b])
			{
				dis[b]=dis[a]+c;
				if (!mark[b])
				{
					mark[b]=1;
					q.push(b);
				}
			}
		}
	}
}
int main ()
{
	int n,m,i,j,k,len,last,tmp,s,ca=0;
	bool flag;
	string str;
	while (scanf("%d%d",&n,&m),n||m)
	{
		mm.clear();//每次要清零！
		cnt=0;
		memset(v,-1,sizeof(v));
		last=1;
		for (i=0;i<n;i++)
		{
			flag=0;
			tmp=last;
			while (1)
			{
				cin>>name[last][0]>>name[last][1];
				len=name[last][1].size();
				if (name[last][1][len-1]=='.')
					flag=1;
				else if (name[last][1][len-1]==':')
				{
					flag=1;
					name[last][1].erase(len-1);
				}
				else
					name[last][1].erase(len-1);
				name[last][0]+=" "+name[last][1];
				if (!mm[name[last][0]])
					mm[name[last][0]]=last;
				if (name[last][0]=="Erdos, P.")
					s=mm[name[last][0]];
				last++;
				if (flag)
					break;
			}
			for (j=tmp;j<last;j++)
			{
				for (k=j+1;k<last;k++)
					add(mm[name[j][0]],mm[name[k][0]],1),add(mm[name[k][0]],mm[name[j][0]],1);
			}
			getline(cin,str);
		}
		spfa(s);
		printf("Database #%d\n",++ca);
		for (i=0;i<m;i++)
		{
			getline(cin,str);
			cout<<str;
			if (dis[mm[str]]!=INT_MAX)
				printf(": %d\n",dis[mm[str]]);
			else
				printf(": infinity\n");
		}
		printf("\n");
	}
	return 0;
}