#include<cstdio>

int main ()
{
    int T, n, ans, num;
    while(~scanf("%d", &T))
    {
        num = 0;
        while(T --)
        {
            scanf("%d", &n);
            if(num == 0)
            {
                ans = n;
                num ++;
            }
            else
            {
                if(ans == n)
                    num ++;
                else
                    num --;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
