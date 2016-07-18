#include<stdio.h>
int i, j, n, a[100001], ans[1000001] = {0};
int main()
{
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		ans[ a[i] ]++;
	}
	for(i = 500000; i > 0; i--)
    {
        if( ans[i] )
            for(j = i + i; j <= 1000000; j += i)
                ans[j] += ans[i];
    }
    for(i = 0; i < n; i++)
            printf("%d\n", ans[ a[i] ] - 1 );
    return 0;
}
