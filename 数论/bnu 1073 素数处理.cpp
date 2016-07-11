#include<cstdio>
#include<string.h>

bool a[100010];
int prime[101000], num;

void Prime(int n)
{
    memset(a, 0, n * sizeof(a[0]));
    num = 0;
    a[0] = a[1] = 1;
    for(int i = 2; i <= n; i ++)
    {
        if(!a[i])
            prime[num ++] = i;
        for(int j = 0; j < num && i * prime[j] <= n; j ++)
        {
            a[i * prime[j]] = 1;
            if(!(i % prime[j])) break;
        }
    }
}

int main ()
{
    int n, flag = 0;
    Prime(n);
    int temp, bound = n / 2, d;
    for(int j = 0; j < num; j ++)
    {
        temp = prime[j];
        for(int i = 1; i < bound; i ++)
        {
            d = i * 2;
            if(temp + d * 2 > n)
                break;
            if(!a[temp + d] && !a[temp + d + d])
            {
                printf("%d %d %d\n", temp, temp +d, temp + d + d);
                flag = 1;
            }
        }
    }
    if(!flag)
        printf("No number sequence\n");
    return 0;
}
