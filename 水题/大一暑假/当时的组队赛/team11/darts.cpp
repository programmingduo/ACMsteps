#include<cstdio>

int solve(int a, int b)
{
    int temp = a * a + b * b;
    if(temp <= 400)
        return 10;
    if(temp <= 1600)
        return 9;
    if(temp <= 3600)
        return 8;
    if(temp <= 6400)
        return 7;
    if(temp <= 10000)
        return 6;
    if(temp <= 14400)
        return 5;
    if(temp <= 19600)
        return 4;
    if(temp <= 25600)
        return 3;
    if(temp <= 180 * 180)
        return 2;
    if(temp <= 40000)
        return 1;
    else
        return 0;
}

int main ()
{
    int T, n, a, b, ans;
    scanf("%d", &T);
    while(T --)
    {
        ans = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i ++)
        {
            scanf("%d%d", &a, &b);
            ans += solve(a, b);
        }
        printf("%d\n", ans);
    }
    return 0;
}
