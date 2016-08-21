#include<cstdio>

int main ()
{
    int n, sum = 1;
    double ans = 1;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
    {
        sum *= i;
        ans += 1 / (double) sum;
    }
    printf("%.4lf\n", ans);
}
