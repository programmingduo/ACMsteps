#include<cstdio>

long long ans[2005][5];

int main()
{
    int T;
    scanf("%d", &T);
    ans[1][1] = 26;
    ans[1][2] = 0;
    ans[1][3] = 0;
    ans[1][4] = 26;
    for(int i = 2; i < 2004; i ++)
    {
        ans[i][1] = (ans[i - 1][4] * 25) % 1000000007;
        ans[i][2] = ans[i - 1][1];
        ans[i][3] = ans[i - 1][2];
        ans[i][4] = (ans[i][1] + ans[i][2] + ans[i][3]) % 1000000007;
    }
    while(T --)
    {
        int n;
        scanf("%d", &n);
        printf("%lld\n", ans[n][4]);
    }
    return 0;
}
