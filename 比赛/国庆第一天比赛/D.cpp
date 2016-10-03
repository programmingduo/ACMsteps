#include <cstdio>

int abs(int x)
{
	return x< 0? -x: x;
}

int min(int x, int y)
{
	return x< y? x: y;
}
int max(int x, int y)
{
	return x> y? x:y;
}

int main ()
{
	int T, n, a, b;
	scanf("%d", &T);
	for(int tt = 1; tt <= T; tt ++)
	{
		scanf("%d %d %d", &n, &a, &b);
		
		if(a < b)
		{
			int temp = a;
			a = b;
			b = temp;
		}
		while(a != b && a != 1 && b != 1)
		{
			int temp = a - b;
			a = max(temp, b);
			b = min(temp, b);
			// printf("%d %d \n", a, b-);
		}

		if(a == b)
		{
			if((n / a) % 2)
				printf("Case #%d: Yuwgna\n", tt);
			else
				printf("Case #%d: Iaka\n", tt);
		}
		else
		{
			if(n % 2)
				printf("Case #%d: Yuwgna\n", tt);
			else
				printf("Case #%d: Iaka\n", tt);
		}
	}
	return 0;
}