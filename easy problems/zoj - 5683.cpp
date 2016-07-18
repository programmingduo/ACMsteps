#include<cstdio>

int a, n, ans;

int main ()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        ans = 0;
        scanf("%d", &n);
        while(n --)
        {
            scanf("%d", &a);
            if(a != 0)
                ans ++;
            if(a > ans)
                ans = a;
        }
        printf("%d\n", ans);
    }
    return 0;
}
