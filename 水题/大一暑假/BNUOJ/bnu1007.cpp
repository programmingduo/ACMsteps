#include<cstdio>

int main ()
{
    int n;
    while(~scanf("%d", &n))
    {
        if(n == 0)
            break;

        for(int i = 2; ; i ++)
        {
            int x = 0;
            for(int j = 1; j < n; j ++)
                x = (x + i) % j;
            if(x == 0)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
