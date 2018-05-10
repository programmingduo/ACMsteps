#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define maxn 100005
int a[maxn];
int ll[maxn];
int rr[maxn];
int lp,rp;
int t,n,m;
char ss[10];
int tmp;
bool cmp1(int aa,int bb)
{
	return aa > bb;
}
bool cmp2(int aa,int bb)
{
	return aa < bb;
}
int main()
{
	int i,j;
	int mid,tmp1,len;
	while(scanf("%d",&t)!=EOF)
	{
		while(t--)
		{
			scanf("%d",&n);
			for(i=1;i<=n;i++)
			{
				scanf("%d",&a[i]);
			}
			sort(a+1,a+n+1);
			mid = a[(1 + n)/2];
			lp = rp = 0;
			for(i=1;i<(1+n)/2;i++)
				ll[lp++] = a[i];
			for(i=(1+n)/2+1;i<=n;i++)
				rr[rp++] = a[i];
			make_heap(ll,ll+lp,cmp2);
			make_heap(rr,rr+rp,cmp1);
			scanf("%d",&m);
			len = n;
			while(m--)
			{
				scanf("%s",&ss);
				if(ss[0] == 'a')
				{
					scanf("%d",&tmp);
					len++;
					if(tmp >= mid)
					{
						rr[rp++] = tmp;
						push_heap(rr,rr+rp,cmp1);
						if(len%2==1)
						{
							pop_heap(rr,rr+rp,cmp1);
							tmp1 = rr[rp-1];
							rp--;
							ll[lp++] = mid;
							push_heap(ll,ll+lp,cmp2);
							mid = tmp1;
						}
					}
					else if(tmp < mid)
					{
						ll[lp++] = tmp;
						push_heap(ll,ll+lp,cmp2);
						if(len%2==0)
						{
							pop_heap(ll,ll+lp,cmp2);
							tmp1 = ll[lp-1];
							lp--;
							rr[rp++] = mid;
							push_heap(rr,rr+rp,cmp1);
							mid = tmp1;
						}
					}
				}
				else if(ss[0] == 'm')
				{
					printf("%d\n",mid);
				}
			}
		}
	}
	return 0;
}
