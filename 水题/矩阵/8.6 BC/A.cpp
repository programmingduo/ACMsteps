#include<cstdio>

int main ()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        int n, m, a;
        long long total = 0, b;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i ++)
        {
            scanf("%d", &a);
            total += a;
        }
        for(int i = 0; i < m; i ++)
        {
            scanf("%I64d", &b);
            if(b > total )
                printf("1");
            else
                printf("0");
        }
        printf("\n");
    }
    return 0;
}
