#include<cstdio>
#include<string.h>

bool notPrime[10000007];
int sum[10000006];

void Prime()
{
    memset(notPrime, 0, sizeof(notPrime));
    memset(sum, 0, sizeof(sum));
    sum[1] = 1;
    for(int i = 2; i < 10000003; i ++)
    {
        if(!notPrime[i])
        {
            for(int j = 1; j < 10000000; j ++)
            {
                if(j * i > 10000005)
                    break;
                sum[j * i] ++;
                notPrime[i * j] = 1;
            }
        }
    }
//    for(int i = 0; i < 100; i ++)
//        printf("%d %d\n", i, sum[i]);
}

int main ()
{
    int T, a, b, c;
    scanf("%d", &T);
    Prime();
    for(int t = 1; t <= T; t ++)
    {
        int ans = 0;
        scanf("%d%d%d", &a, &b, &c);
        for(int i = a; i <= b; i ++)
        {
            if(sum[i] == c)
                ans ++;
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
