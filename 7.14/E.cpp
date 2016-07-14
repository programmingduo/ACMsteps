#include<cstdio>
#include<string.h>

long long sum[106], a[106][106];

int main ()
{
    int n;
    while(~scanf("%d", &n))
    {
        long long total = 0;
        memset(sum ,0, sizeof(sum));
        for(int i = 0; i < n; i ++)
        {
            for(int j =0; j < n; j ++)
            {
                scanf("%lld", &a[i][j]);
                total += a[i][j];
                sum[i] += a[i][j];
            }

        }
        long long e = total / (n -1);
        for(int i = 0; i < n; i++)
        {
            for(int j =0; j < n; j ++)
            {
                if(j)
                    printf(" ");
                if(i != j)
                    printf("%lld", a[i][j]);
                else
                    printf("%lld", e - sum[i]);
            }
            printf("\n");
        }

    }
    return 0;
}
