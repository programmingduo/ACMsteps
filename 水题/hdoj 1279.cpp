#include<cstdio>

int ans[10000000];

int main()
{
    int n, num;
    scanf("%d", &n);
    while(n --)
    {
        scanf("%d", &num);
        int k = 0;
        while(num != 1)
        {
            if(num % 2)
            {
                ans[k ++] = num;
                num = num * 3 + 1;
            }
            else
                num /= 2;
        }
        if(k == 0)
            printf("No number can be output !\n");
        else
        {
            for(int i = 0; i < k; i ++)
            {
                if(i)
                    printf(" ");
                printf("%d", ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
