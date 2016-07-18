#include<cstdio>

int main ()
{
    int T, n;
    scanf("%d", &T);
    while(T --)
    {
        long long least, total;
        double  rating;
        scanf("%d %lld", &n, &total);
        double now = -1;
        int ans;
        for(int i = 1; i <= n; i ++)
        {
            scanf("%lld %lf", &least, &rating);
            if(total >= least)
            {
                if(1.0 * total * (1.0 + rating / 100) > now)
                {
                    ans = i;
                    now = 1.0 * total * (1.0 + rating / 100);
                }
            }
        }
        printf("%d\n", ans);
    }
}
