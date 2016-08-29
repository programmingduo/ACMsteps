#include<cstdio>

int main ()
{
    int n, b, d, total = 0, ans = 0,a ;
    scanf("%d %d %d", &n, &b, &d);
    for(int i = 0; i < n; i ++)
    {
        scanf("%d", &a);
        if(a <= b)
        {
            total += a;
            if(total > d)
            {
                ans ++;
                total = 0;
            }
        }
    }
    printf("%d\n", ans);
}
