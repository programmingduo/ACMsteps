#include <iostream>
#include <cstring>
using namespace std;
#define maxn 65536
int m,n;
int cnt[maxn];
int e[maxn];
int prime[maxn+10];
int s[maxn];
int stp;
int tp;
void Prime()
{
	int i,j;
	stp = 0;
	memset(prime,0,sizeof(prime));
	for(i=2;i*i<=maxn;i++)
	{
		for(j=2*i;j<=maxn;j+=i)
		{
			prime[j] = 1;
		}
	}
	for(i=2;i<=maxn;i++)
	{
		if(prime[i]==0) s[stp++] = i;
	}
	return;
}
void solve(int k)
{
	memset(cnt,0,sizeof(cnt));
	int tmp = k;
	int i;
	int flag = 0;
	tp = 0;
	for(i=0;s[i]*s[i]<=k;i++)
	{
		if(tmp%s[i]==0)
			e[tp++] = s[i];
		while(tmp%s[i]==0)
		{
			cnt[s[i]]++;
			tmp = tmp/s[i];
		}	
	}
	if(tmp!=1)
	{
		e[tp++] = tmp;
		cnt[tmp] = 1;
	} 
}
int main()
{
	int n,tmp,i;
	Prime();
	while(scanf("%d",&n)!=EOF)
	{
		if(n == 0 || n == 1)	
			printf("%d\n",n);
		else
		{
			solve(n);
			for(i=0;i<tp;i++)
			{
				printf("%d ^ %d\n",e[i],cnt[e[i]]);
			}
		}
	}
	return 0;
}
