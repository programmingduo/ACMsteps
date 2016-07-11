#include<cstdio>

int main ()
{
    int n, k, odd, even, temp;
    while(~scanf("%d%d", &n, &k))
    {
        odd = even = 0;
        for(int i = 0; i < n; i ++)
        {
            scanf("%d", &temp);
            if(temp % 2 == 1)
                odd ++;
            else
                even ++;
        }
        if(odd == 0)
        {
            printf("Daenerys\n");
            continue;
        }
        if(even == 0)
        {
            if(k % 2 == 0)
                printf("Daenerys\n");
            else
                printf("Stannis\n");
            continue;
        }
        if(n == k)
        {
            if(odd % 2 == 0)
                printf("Daenerys\n");
            else
                printf("Stannis\n");
            continue;
        }
        if((n - k) % 2 == 1)
        {
            if(k % 2 == 0)
            {
                if((n - k) / 2 >= even || (n - k) / 2 >= odd)
                    printf("Daenerys\n");
                else
                    printf("Stannis\n");
            }
            else
            {
                if((n - k) / 2 >= odd)
                    printf("Daenerys\n");
                else
                    printf("Stannis\n");
            }
        }
        else
        {
            if(k % 2 == 1 && (n - k) / 2 >= even)
                printf("Stannis\n");
            else
                printf("Daenerys\n");
        }
    }
    return 0;
}
