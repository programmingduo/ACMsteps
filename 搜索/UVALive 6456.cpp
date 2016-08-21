#include<cstdio>

int a[305][305], b[305][305], c[305][305];

int cmp(int n)
{
    int res = 0;
    for(int i = 0; i < n; i ++)
    {
        for(int j =  0; j < n; j ++)
        {
            if(a[i][j] == b[i][j])
                res ++;
        }
    }
    return res;
}

int overf(int n)
{
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < n; j ++)
        {
            c[n - 1 - j][i] = b[i][j];
        }
    }
    for(int i = 0; i < n; i ++)
    {
        for(int j  =0; j < n; j ++)
        {
            b[i][j] = c[i][j];
        }
    }

}

int max(int x, int y)
{
    return x> y? x: y;
}

int main ()
{
    int n;
    while(~scanf("%d", &n) && n)
    {
        for(int i = 0; i < n; i ++)
        {
            for(int j = 0; j < n; j ++)
            scanf("%d",  &a[i][j]);
        }
        for(int i = 0; i < n; i ++)
        {
            for(int j = 0; j < n; j ++)
                scanf("%d" ,&b[i][j]);
        }

        int ans = 0;
        for(int i = 0; i < 4; i ++)
        {
            ans = max(ans, cmp(n));
            overf(n);
//            for(int j = 0; j < n ;j ++)
//            {
//                for(int k = 0;  k < n; k ++)
//                {
//                    printf("%d ", b[j][k]);
//                }
//                printf("\n");
//            }
        }

        printf("%d\n", ans);
    }
}
