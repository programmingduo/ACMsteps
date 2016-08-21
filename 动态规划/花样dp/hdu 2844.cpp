#include<cstdio>
#include<string.h>

int a[10006], c[10506];
int dp[1000006];

void multipack(int num, int val, int pack)
{
    //如果总价值大于背包总量，则为完全背包
    if(num*val>=pack)
    {
        for(int i = 0; i < pack; i ++)
        {
            if(val+i>pack)
                break;
            if(!dp[i])
                continue;
            dp[i+val] = 1;
        }
    }
    //如果总价值小于背包总量，则为01背包
    //这里使用二进制优化的01背包
    else
    {
        int i = 1;
        while(i<num)
        {
            int temp = val*i;
            for(int j = pack; j >= temp; j --)
            {
                if(!dp[j-temp])
                    continue;
                dp[j] = 1;
            }
            num -= i;
            i<<= 1;
        }
        int temp = val*num;
        for(int j = pack; j >= temp; j --)
        {
            if(!dp[j-temp])
                continue;
            dp[j] = 1;
        }
    }
}

int main ()
{
    int n, m;
    while(~scanf("%d %d", &n, &m) && (n && m))
    {
        for(int i = 0; i < n; i ++)
        {
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < n; i ++)
        {
            scanf("%d", &c[i]);
        }

        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i = 0; i < n; i ++)
        {
            multipack(c[i], a[i], m);
        }
        int ans = 0;
        for(int i = 1; i <= m; i ++)
        {
            ans += dp[i];
        }
        printf("%d\n", ans);
    }
}
