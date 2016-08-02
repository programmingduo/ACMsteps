#include<cstdio>
#include<string.h>

const int N = 30006;
int num = 0;
int prime[N];
bool a[N];

void Prime(int n)
{
    memset(a, 0, sizeof(a[0]) * n);
    num = 0;
    a[0] = a[1] = 1;
    for(int i = 0; i < n; i ++)
    {
        if(!a[i])
            prime[num ++ ] = i;
        for(int j = 0; j < num && i * prime[j] < n; j ++)
        {
            a[i * prime[j]] = 1;
            if(i % prime[j] == 0)
                break;
        }
    }
}

int main ()
{
    int n;
    while(~scanf("%d", &n))
    {
        n ++;
        Prime(n);
        for(int i = 0; i < num && prime[i] < n; i ++)
        {
            printf("%d\n", prime[i]);
        }
    }
    return 0;
}
