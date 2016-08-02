#include<stdio.h>

int main()
{
    int y, k, n;
    while(scanf("%d %d %d", &y, &k, &n) != EOF)
    {
        n -= y;
        int i =y / k * k - y;
        for(; i <= 0; i += k);
        if(i <= n)
        {
            printf("%d", i);
            i += k;
        }
        else
        {
            printf("-1\n");
            continue;
        }
        while(i <= n)
        {
            printf(" %d", i);
            i += k;
        }
        printf("\n");
    }
    return 0;
}
