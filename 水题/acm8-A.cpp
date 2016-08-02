#include<cstdio>

int main ()
{
    int n, total, num[35];
    while(~scanf("%d", &n) && n)
    {
        total = 0;
        for(int i = 0; i < n; i ++)
        {
            scanf("%d", &num[i]);
            total += num[i];
        }
        if(total % 2 == 1)
        {
            printf("No equal partitioning.\n");
            continue;
        }
        total /= 2;
        int i = 0;
        for(; i < n && total > 0; i ++)
        {
            total -= num[i];
        }
        if(total == 0)
            printf("Sam stops at position %d and Ella stops at position %d.\n", i, i+1);
        else
            printf("No equal partitioning.\n");
    }
    return 0;
}
