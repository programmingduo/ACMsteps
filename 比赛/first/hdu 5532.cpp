#include <cstdio>

int n;
int a[100005];

int judgeDSort(int x)
{
	if(x == 0)
	{
		for(int i = 2; i < n; i ++)
		{
			if(a[i] - a[i - 1] > 0)
				return i;
		}
	}
	else
	{
		int last = a[0];
		for(int i = 1; i < n; i ++)
		{
			if(i == x)
				continue;
			if(a[i] - last > 0)
				return i;
			last = a[i];
		}
	}
	return -1;
}

int judgeISort(int x)
{
	if(x == 0)
	{
		for(int i = 2; i < n; i ++)
		{
			if(a[i] - a[i - 1] < 0)
				return i;
		}
	}
	else
	{
		int last = a[0];
		for(int i = 1; i < n; i ++)
		{
			if(i == x)
				continue;
			if(a[i] - last < 0)
				return i;
			last = a[i];
		}
	}
	return -1;
}

int main ()
{
	int T;
	scanf("%d", &T);
	while(T --)
	{
		scanf("%d", &n);
		for(int i = 0; i < n; i ++)
		{
			scanf("%d", &a[i]);
		}

		int flag = 0;
		int t = judgeISort(-1);
		if(t == -1)
			flag = 1;
		if(judgeISort(t) == -1 || judgeISort(t - 1) == -1 || judgeISort(t + 1) == -1)
			flag = 1;

		t = judgeDSort(-1);
		if(t == -1)
			flag = 1;
		if(judgeDSort(t) == -1 ||judgeDSort(t - 1) == -1 || judgeDSort(t + 1) == -1)
			flag = 1;
		
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
}