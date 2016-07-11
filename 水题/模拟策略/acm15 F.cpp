#include<cstdio>
#include<string.h>

int main ()
{
    int T, a[16][16];
    scanf("%d",&T);
    while(T --)
    {
        memset(a, 0, sizeof(a));
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        if(k == 0 || n < 3 || m < 3)
        {
            for(int i = 0; i < n; i ++)
            {
                for(int j = 0; j < m; j ++)
                {
                    if(j)
                        printf(" ");
                    printf("1");
                }
                printf("\n");
            }
            continue;
        }
        int temp = k / (m - 2) + 2;
        for(int i = k % (m - 2) + 1; i < m && temp < n; i ++)
            a[temp][i] = 1;
        for(int i = temp + 1; i < n; i ++)
            for(int j = 0; j < m; j ++)
            a[i][j] = 1;
        for(int i = 0; i < n; i ++)
        {
            for(int j = 0; j < m; j ++)
            {
                if(j)
                    printf(" ");
                printf("%d", a[i][j]);
            }
            printf("\n");
        }

    }
    return 0;
}
