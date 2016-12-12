#include <cstdio>
#include <string.h>

int flag;
int x[5], y[5], use[5];

void find(int a, int b, int id)
{
	if(id == 4 || !flag)
	{
		flag = 0;
		return ;
	}
	for(int i = 1; i <= 4; i ++)
	{
		if(use[i])
			continue;
		use[i] = 1;
		if(a == x[i])
			find(a, b + y[i], id + 1);	
		if(a == y[i])
			find(a, b + x[i], id + 1);
		if(b == x[i])
			find(a + y[i], b, id + 1);
		if(b == y[i])
			find(a + x[i], b, id + 1);

		use[i] = 0;
	}
}

int main ()
{
	int T;
	scanf("%d", &T);
	while(T --)
	{
		for(int i = 1; i <= 4; i ++)
		{
			scanf("%d %d", &x[i], &y[i]);	
		}

		memset(use, 0, sizeof(use));
		flag = 1;
		for(int i = 1; i <= 4; i ++)
		{
			use[i] = 1;
			for(int j = 1; j <= 4; j ++)
			{
				use[j] = 1;
				find(x[j], y[j], 2);
				use[j] = 0;
			}
			use[i] = 0;
		}
		if(flag)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}
