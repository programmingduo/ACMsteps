#include <cstdio>

int main ()
{
	int T;
	long long n;
	scanf("%d", &T);
	while(T --)
	{
		scanf("%lld", &n);
		printf("%lld\n", (1 + 1 + 2 * (n - 1)) * n / 2 % 10000);
	}
	return 0;
}