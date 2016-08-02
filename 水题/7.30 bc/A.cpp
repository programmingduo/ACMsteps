#include<cstdio>

int a[1100005], sum[100004];

int main ()
{
    int T, n, m;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d %d", &n, &m);
        sum[0] = 0;
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d", &a[i]);
            sum[i] = a[i] + sum[i - 1];
        }

        int flag = 0;
        for(int i = 1; i <= n && !flag; i ++)
        {
            for(int j = 0; j < i && !flag; j ++)
            {
                if(sum[i] - sum[j] < m)
                    break;
                if((sum[i] - sum[j]) % m == 0)
                    flag = 1;
            }
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
