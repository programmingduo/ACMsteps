#include <cstdio>
#include <string.h>

int num[55][55];

int main ()
{
	int T, x, y;
	scanf("%d", &T);
	while(T --)
	{
		memset(num, 0, sizeof(num));
		scanf("%d %d", &x, &y);
		for(int i = 1; i <= x; i ++)
		{
			for(int j = 1; j <= y; j ++)
			{
				scanf("%d", &num[i][j]);
			}
		}

		int ans = 0;
		for(int i = 1; i <= x; i ++)
		{
			for(int j = 1; j <= y; j ++)
			{
				if(num[i][j])
					ans ++;

				if(num[i][j] > num[i][j - 1])
					ans += num[i][j] - num[i][j - 1];
				if(num[i][j] > num[i][j + 1])
					ans += num[i][j] - num[i][j + 1];

				if(num[i][j] > num[i + 1][j])
					ans += num[i][j] - num[i + 1][j];
				if(num[i][j] > num[i - 1][j])
					ans += num[i][j] - num[i - 1][j];
			}
		}

		printf("%d\n", ans);
	}
	return 0;
}