#include <cstdio>
#include <cstring>

char s[505][2003];

int max(int x, int y)
{
	return x> y? x: y;
}
int main ()
{
	int T, n, tt = 1;
	scanf("%d", &T);
	while(T --)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++)
		{
			scanf("%s", s[i]);
		}

		int ans = -1;
		for(int i = n; i > 1; i --)
		{
			if(!strstr(s[i], s[i - 1]))
			{
				ans = max(ans, i);
				for(int j = i - 1, k = i + 1; k < n; k ++)
				{
					if(!strstr(s[k], s[j]))
					{
						ans = max(ans, k);
					}
				}
			}
		}
		printf("Case #%d: %d\n", tt ++, ans);
	}
}