#include<cstdio>

int main ()
{
    int n, a, b, c;
    int v[10005];
    while(~scanf("%d", &n))
    {
        scanf("%d%d%d", &a, &b, &c);
        for(int i = 0; i < n; i ++)
            scanf("%d", &v[i]);
        int temp = 0, ans = 0;
        for(int i = 0; i < n; i ++)
        {
            temp += v[i];
            if(temp >= c)
                temp = 0, ans += 4;
            else if(temp >= b)
                temp  = 0, ans += 3;
            else if(temp >= a)
                temp = 0, ans += 2;
        }
        printf("%d\n", ans);
    }
    return 0;
}
