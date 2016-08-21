#include<cstdio>
#include<string.h>

char a[2005], b[2005], c[2005];
int dp[2005][2005];

int main ()
{
    while(~scanf("%s%s%s", a, b, c))
    {
        memset(dp, 0, sizeof(dp));
        int l1 = strlen(a), l2 = strlen(b), l3 = strlen(c);
        dp[0][0] = 1;
        if(l3 != l1 + l2)
        {
            printf("No\n");
            continue;
        }
        for(int i = 0; i < l1; i ++)
            for(int j = i; j < l3; j ++)
            if(a[i] == c[j])
                dp[i + 1][0] = 1;
        for(int i = 0; i < l2; i ++)
            for(int j = i; j < l3; j ++)
            if(b[i] == c[j])
                dp[0][i + 1] = 1;


        for(int i = 1; i <=l1; i ++)
        {
            for(int j = 1; j <= l2; j ++)
            {
                dp[i][j] = (dp[i - 1][j] && a[i - 1] == c[i + j - 1])
                            ||(dp[i][j - 1] && b[j - 1] == c[j + i - 1])
                            ||dp[i][j];
            }
        }
        if(dp[l1][l2])
            printf("Yes\n");
        else
            printf("No\n");
    }
}
