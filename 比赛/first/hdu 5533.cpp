#include <cstdio>

int x[105], y[105];

int dis(int a, int b)
{
	return (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]);
}

int main ()
{
	int T, n;
	scanf("%d", &T);
	while(T --)
	{
		scanf("%d", &n);
		for(int i = 0; i < n; i ++)
		{
			scanf("%d%d", &x[i], &y[i]);
		}

		int total = 0, mindis = 0x3fffffff;
		for(int i = 0; i < n; i ++)
		{
			for(int j = 0; j < n; j ++)
			{
				if(i == j)
					continue;

				if(dis(i, j) < mindis)
				{
					mindis = dis(i, j);
					total = 1;
				}
				else if(dis(i, j) == mindis)
				{
					total ++;
				}
			}
		}

		if(total == n * 2)
			printf("YES\n");
		else	
			printf("NO\n");
	}
	return 0;
}