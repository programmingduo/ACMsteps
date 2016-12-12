#include <cstdio>

int main()
{
	int n, x;
	char s;
	while(~scanf("%d", &n))
	{
		getchar();
		int ans = 0;
		for(int i= 0 ; i < n; i ++)
		{
			scanf("%c", &s);
			getchar();
			if(s == 'S')
			{
				ans ++;
			}
			else
			{
				scanf("%d", &x);
				getchar();
				if(x == 1)
					ans ++;
			}
		}
		printf("%d\n", ans);
	
	}
	return 0;
}
