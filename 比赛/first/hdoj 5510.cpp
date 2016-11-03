#include <cstdio>
#include <cstring>

char s[503][2005];

int main ()
{
	int T, tt = 1, n;
	scanf("%d", &T);
	while(T --)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++)
		{
			scanf("%s", s[i]);
		}
		int ans = -1;

		for(int i = 1, j = 1; i < n && j <= n;)
		{
			if(i == j)
				j ++;
			if(strstr(s[j], s[i]))
				i ++;
			else
			{
				ans = j;
				j ++;
			}
		}
		printf("Case #%d: %d\n", tt ++, ans);
	}
	return 0;
}