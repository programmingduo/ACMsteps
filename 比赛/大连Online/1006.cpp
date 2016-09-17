#include<cstdio>

int main ()
{
    int M, n, x;
    while(~scanf("%d", &M))
    {
        while(M --)
        {
            scanf("%d", &n);
            int all = 0;
            int flag = 0;
            for(int i = 0; i < n; i ++)
            {
                scanf("%d", &x);
                all += x;
                if(x > 2 * n - 2)
                    flag = 1;
            }

            if(all != n * (n - 1) || flag)
                printf("F\n");
            else
                printf("T\n");
        }
    }
}
