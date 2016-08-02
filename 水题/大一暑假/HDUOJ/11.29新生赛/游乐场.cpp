#include<cstdio>
#include<algorithm>

int main ()
{
    int T, n, m, k, x[10005], temp;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= n; i ++)
            scanf("%d", &x[i]);
        for(int i = 0; i < m; i ++)
        {
            scanf("%d", &temp);
            if(x[temp] != 1000000005 && k >= 0)
                k -= x[temp];
            x[temp] = 1000000005;
        }
        if(k < 0)
        {
            printf("-1\n");
            continue;
        }
        std::sort(x + 1, x + n + 1);
        int i;
        n -= m;
        for(i = 1; i <= n && k >= 0; i ++)
        {
            k -= x[i];
        }
        if(k < 0)
            printf("%d\n", i + m - 2);
        else
            printf("%d\n", i + m - 1);
    }
    return 0;
}
