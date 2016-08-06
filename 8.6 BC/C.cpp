#include<cstdio>

int a[200005];

int main ()
{
    int T, n, m, k;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d %d %d", &n, &m, &k);
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d", &a[i]);
        }

        long long last = 0, now = 0, next = 0, total = 0, ans = 0;
        for(int i = 1; i <= n; i ++)
        {
            if(a[i] >= m)
            {
                if(total == 0)
                    now = i;
                total ++;
                next = i;
            }
            if(total == k)
            {
                ans += (n - next + 1) * (now - last);
                last = now;
                for(int j = now + 1; j <= n; j ++)
                    if(a[j] >= m)
                    {
                        now = j;
                        break;
                    }
                total --;
//                printf("%I64d ", ans);
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
