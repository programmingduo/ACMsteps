#include<cstdio>

int main ()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        int n, num, ans = 0, cnt[100] = {0};
        scanf("%d", &n);
        for(int j = 0; j < n; j ++)
        {
            scanf("%d", &num);
            for(int i = 0; i < 17; i ++)
            {
                if(num % 2 == 0)
                {
                    cnt[i] ++;
                }
                num >>= 1;
            }
        }
        for(int i = 0; i < 17; i ++)
            ans += (1 << i) * (n * n - cnt[i] * cnt[i]);

        printf("%d\n", ans);
    }
    return 0;
}
