#include<cstdio>

int dp[60];
int compute(int n)
{
    if(n == 1)
        return 1;
    if(n == 2)
        return 3;
    if(dp[n])
        return dp[n];
    return dp[n] = compute(n - 1) + compute(n - 2) * 2;
}

int main()
{
    int T, n;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d", &n);
        printf("%d\n", compute(n));
    }
    return 0;
}
