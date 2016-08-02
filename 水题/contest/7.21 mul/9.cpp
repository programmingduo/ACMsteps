#include<cstdio>
#include<string.h>

int a[106];

int gcd(int x, int y)
{
    return y == 0? x: gcd(y, x % y);
}

int main()
{
    int T, n, m, id, num;
    scanf("%d", &T);
    while(T --)
    {
        memset(a, -1, sizeof(a));
        scanf("%d %d", &n, &m);
        for(int i = 0; i < m; i ++)
        {
            scanf("%d %d", &id, &num);
            a[id] = num;
        }

        if(a[2] == -1 && a[1] == -1)
            a[2] = 100;
        else if(a[2] == -1)
            a[2] = a[1];
        if(a[1] == -1)
            a[1] = 100;

        int last = 0;
        for(int i = n; i > 2; i --)
        {
            if(a[i] == -1)
                a[i] = last;
            else
            {
                last = a[i];
            }
        }
        int total = 0;
        for(int i = 1; i <= n; i ++)
        {
            total += a[i];
        }
        int x = a[1] + a[2], y = total;
        if(x == 0)
        {
            printf("0/0\n");
            continue;
        }
        int t = gcd(y, x);
        printf("%d/%d\n", x/t, y / t);
    }
    return 0;
}
