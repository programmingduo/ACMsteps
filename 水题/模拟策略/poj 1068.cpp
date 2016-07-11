#include<cstdio>
#include<string.h>

int main ()
{
    int T, n;
    int a[25], b[25], ans[25];
    scanf("%d", &T);
    while(T --)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        a[0] = b[0] = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d", &a[i]);
            b[i] = a[i] - a[i - 1];
        }
        for(int i = 1; i <= n; i ++)
        {
            int j = i;
            while(b[j] == 0)
            {
                j --;
            }
            b[j] --;
            a[j] --;
            if(i == j)
                ans[i] = 1;
            else
                ans[i] = a[i] - a[j];
        }
        for(int i = 1; i <= n; i ++)
        {
            if(i != 1)
                printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
