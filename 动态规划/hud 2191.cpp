#include<cstdio>
#include<string.h>

inline int max(int a, int b)
{
    return a > b? a : b;
}

int dp[105];

int main ()
{
    int T, money, kind, a, c, b;
    scanf("%d", &T);
    while(T --)
    {
        memset(dp, 0, sizeof(dp));
        scanf("%d%d", &money, &kind);
        while(kind --)
        {
            scanf("%d%d%d", &a, &b, &c);
            for(int i = money; i >= a; i --)
            {
                for(int j = 1; j <= c; j ++)
                {
                    if(i < j * a)
                        break;
                    dp[i] = max(dp[i], dp[i - j * a] + b * j);
                }
            }
        }
//        for(int i = 0; i <= money; i ++)
//            printf("%d ", dp[i]);
        printf("%d\n", dp[money]);
    }
    return 0;
}
