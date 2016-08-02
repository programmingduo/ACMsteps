#include<cstdio>
#include<string.h>

bool a[10000];
int prime[100000];
int num;

void Prime(int n)
{
    memset(a, 0, sizeof(a));
    num = 0;
    a[0] = a[1] = 1;

    for(int i = 2; i < n; i ++)
    {
        if(!a[i])
            prime[num ++] = i;
        for(int j = 0; j < num && i * prime[j] < n; j ++)
        {
            a[i * prime[j]] = 1;
            if(!(i % prime[j]))
                break;
        }
    }
}

int main()
{
    Prime(10000);
    int n;
    while(~scanf("%d", &n) && n)
    {
        if(a[n])
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
