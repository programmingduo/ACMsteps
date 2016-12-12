#include <string.h>
#include <cstdio>

const int N = 20004;
bool a[N];
int prime[N], num;

void Prime()
{
	memset(a, 0, sizeof(a));
	num = 0;
	a[0] = a[1] = 1;

	for(int i = 2; i < N; i ++)
	{
		if(!a[i]) prime[num ++] = i;	
		for(int j = 0; j < num && i * prime[j] < N; j ++)
		{
			a[i * prime[j]] = 1;
			if(!(i % prime[j]))
				break;
		}
	}	
}

int min(int a, int b)
{
	return a< b? a: b;
}

int main()
{
	Prime();
	int n, inp;
	scanf("%d", &n);
	int ans = -1, maxx = -1;
	while(n --)
	{
		scanf("%d", &inp);
		int temp = 1;
		for(int i = 0; i < num; i ++)
		{
			if(inp % prime[i] == 0)
				temp = prime[i];
		}
		if(temp > maxx)
		{
			maxx = temp;
			ans = inp;
		}
		else if(temp == maxx)
		{
			ans = min(ans, inp);
		}
	}
	printf("%d\n", ans);
	return 0;

}