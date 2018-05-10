#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define maxn 100002

int hp[maxn],tp;
void heapfy(int ind)
{
	int tmp = ind,k;
	int lchild,rchild,min_element;
	int temp;
	int l_flag,r_flag;
	while(tmp<tp)
	{
		l_flag = r_flag = 0;
		if(tmp*2>tp)
			break;
		else
		{
			l_flag = 1;
			lchild = hp[tmp*2];
		}
		if(tmp*2+1<=tp)
		{
			rchild = hp[tmp*2+1];
			r_flag = 1;
		}
		if(r_flag == 0)
		{
			min_element = lchild;
			k = tmp*2;
		}
		else
		{
			if(lchild < rchild)
			{
				min_element = lchild;
				k = tmp*2;
			}
			else
			{
				min_element = rchild;
				k = tmp*2+1;
			}
		}
		if(hp[tmp]<=min_element)
			break;
		else
		{
			temp = hp[k];
			hp[k] = hp[tmp];
			hp[tmp] = temp;
			tmp = k;
		}
	}
}
void pushheap(int k)
{
	int fa,tmp,temp;
	tmp = k;
	while(tmp!=1)
	{
		fa = tmp/2;
		if(hp[fa]>hp[tmp])
		{
			temp = hp[fa];
			hp[fa] = hp[tmp];
			hp[tmp] = temp;
			tmp = fa;
		}
		else
		{
			break;
		}
	}
	return;
}
int main()
{
	int n,element,ans;
	char ch;
	while(scanf("%d",&n)&&n)
	{
		tp = 0;
		for(int i=1;i<=n;i++)
		{
			scanf("%c",&ch);
			scanf("%c",&ch);
			if(ch == 'B')
			{
				scanf("%d",&element);
				hp[++tp] = element;
				pushheap(tp);
			}
			else
			{
				ans = hp[1];
				hp[1] = hp[tp];
				tp--;
				heapfy(1);
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
