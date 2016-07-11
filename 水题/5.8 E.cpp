#include<cstdio>
#include<algorithm>
int t[10000];
int main ()
{
    int T, n, time;
    scanf("%d", &T);
    for(int i = 1; i <= T; i ++)
    {
        scanf("%d%d", &n, &time);
        for(int j = 0; j < n; j ++)
        {
            scanf("%d", &t[j]);
        }
        std::sort(t, t+n);
        int a = 0, b = 0, c = 0, j = 0;
        for(; j < n; j ++)
        {
            a += t[j];
            if(a > time)
                break;
            c ++;
            b += a;
        }
        if(j < n)
            a -= t[j];
        printf("Case %d: %d %d %d\n", i, c, a, b);
    }
    return 0;
}
