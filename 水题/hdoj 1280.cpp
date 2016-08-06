#include<cstdio>
#include<algorithm>

int cmp(int x, int y)
{
    return x>y;
}

int a[40000], sum[10000000];

int main ()
{
    int n, m;
    while(~scanf("%d %d", &n, &m))
    {
        int k = 0;
        for(int i = 0; i < n; i ++)
        {
            scanf("%d", &a[i]);
            for(int j = 0; j < i; j ++)
            {
                sum[k ++] = a[i] + a[j];
            }
        }
        std::sort(sum, sum + k, cmp);
//        for(int i = 0; i < k; i ++)
//            printf("%d ", sum[i]);
        for(int i = 0; i < m; i ++)
        {
            if(i)
                printf(" ");
            printf("%d", sum[i]);
        }
        printf("\n");
    }
    return 0;
}
