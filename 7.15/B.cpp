#include<cstdio>
#include<string.h>

int a[105][105], ror[109], roc[106];
long long sumr[105], sumc[106];

int main ()
{
    int r, c;
    while(~scanf("%d %d", &r, &c))
    {
        int flag1 = 0, flag2 = 0;
        memset(sumr, 0, sizeof(sumr));
        memset(sumc, 0, sizeof(sumc));
        for(int i = 0; i < r; i ++)
        {
            for(int j = 0; j < c; j ++)
            {
                scanf("%d", &a[i][j]);
                sumr[i] += a[i][j];
                sumc[j] += a[i][j];
                if(sumr[i] < 0)
                    flag1 ++;
                if(sumc[i] < 0)
                    flag2 ++;
            }
        }
        if(!flag1 && !flag2)
        {
            printf("0\n0\n");
            continue;
        }

        memset(ror, 0, sizeof(ror));
        memset(roc, 0, sizeof(roc));
        while(flag1 || flag2)
        {
            for(int i = 0; i < r; i ++)
            {
                if(sumr[i] < 0)
                {
                    sumr[i] = -sumr[i];
                    for(int j = 0; j < c; j ++)
                    {
                        a[i][j] = -a[i][j];
                        sumc[j] += a[i][j] *( 2);
                        if(sumc[j] < 0)
                            flag2 ++;
                    }
                    ror[i] ++;
                }
                flag1 = 0;
            }
            for(int i = 0; i < c; i ++)
            {
                if(sumc[i] < 0)
                {
                    sumc[i] = -sumc[i];
                    for(int j = 0; j < c; j ++)
                    {
                        a[i][j] = -a[i][j];
                        sumr[j] += a[i][j] * 2;
                        if(sumr[j] < 0)
                            flag1 ++;
                    }
                    roc[i] ++;
                }
                flag2 = 0;
            }
        }
        int ans = 0;
        for(int i =0; i < r; i ++)
        {
            if(ror[i] % 2)
                ans ++;
        }
        printf("%d", ans);
        for(int i = 0; i < r; i ++)
            if(ror[i] % 2)
            printf(" %d", i +1);
        printf("\n");

        ans = 0;
        for(int i =0; i < c; i ++)
        {
            if(roc[i] % 2)
                ans ++;
        }
        printf("%d", ans);
        for(int i = 0; i < c; i ++)
            if(roc[i] % 2)
            printf(" %d", i +1);
        printf("\n");
    }
}
