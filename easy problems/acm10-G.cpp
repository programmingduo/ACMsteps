#include<cstdio>

int a[100005], b[100005];

int main ()
{
    int n, m, x, y, k, c;
    while(~scanf("%d%d", &n, &m))
    {
        for(int i = 1; i <= n; i ++)
            scanf("%d", &a[i]);
        for(int i = 1; i <= n; i ++)
            scanf("%d", &b[i]);
        while(m --)
        {
            scanf("%d", &c);
            if(c == 1)
            {
                scanf("%d%d%d", &x, &y, &k);
                for(int i = 0; i < k; i ++)
                {
                    b[y + i] = a[x + i];
                }
            }
            if(c == 2)
            {
                scanf("%d", &k);
                printf("%d\n", b[k]);
            }
        }
    }
    return 0;
}
