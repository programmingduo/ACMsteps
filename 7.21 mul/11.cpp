#include<cstdio>

int a[100006];

int main ()
{
    int T, n;
    scanf("%d", &T);
    while(T --)
    {
        long long odd = 0, total = 0;
        scanf("%d", &n);
        for(int i =0; i < n; i ++)
        {
            scanf("%d", a+i);
            if(a[i] % 2)
            {
                odd ++;
                total += a[i] - 1;
            }
            else
            {
                total += a[i];
            }
        }

        if(odd == 0)
        {
            printf("%d\n", total);
            continue;
        }

        int ans = total / odd;
        if(ans % 2 && ans != 1)
        {
            printf("%d\n", ans);
        }
        else
        {
            printf("%d\n", ans + 1);
        }
    }
    return 0;
}

