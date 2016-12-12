#include <cstdio>

int GCD(int a, int b)
{
	if(b == 0)
		return a;
	else
		return GCD(b, a % b);
}

int lcm(int a, int b)
{
	return a / G-CD(a, b) * b;
}

int main()
{
	int a, b;
	while(~scanf("%d %d", &a, &b))
	{
		int t = a / 2, flag = 0;
		for(int i = 1; i <= t; i ++)
		{
			if(lcm(i, a - i) == b)
			{
				flag = i;
				break;
			}
		}
		if(flag)
			printf("%d %d\n", flag, a - flag);
		else
			printf("No Solution\n");
	}
	return 0;
}