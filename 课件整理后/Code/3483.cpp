#include <iostream>
#include <cstring>
using namespace std;
#define maxn 65536
int m,n;
int cnt[maxn];
int prime[maxn+10];
int s[maxn];
int stp;
int tt;
int gcd(int a,int b)
{
	int k1,k2;
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
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
	for(i=0;s[i]*s[i]<=k;i++)
	{
		while(tmp%s[i]==0)
		{
			cnt[i]++;
			tmp = tmp/s[i];
		}
	}
	if(tmp!=1)
		flag = 1;
	int ans = 1;
	for(i=0;i<maxn;i++)
	{
		ans = ans*(cnt[i]+1);
	}
	if(flag == 1)
		ans = ans*2;
	printf("%d\n",ans);
}
int main()
{
	int t,tmp;
	Prime();
	while(scanf("%d",&t)!=EOF)
	{
		while(t--)
		{
			scanf("%d%d",&m,&n);
			tmp = gcd(m,n);
		//	printf("%d\n",tmp);
			solve(tmp);
		}
	}
	return 0;
}
