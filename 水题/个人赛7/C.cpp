#include<cstdio>
#include<string.h>

int dp[10006];

bool a[10005];
int prime[100005], here[10005];

//void Prime()
//{
//    int n  =10002;
//    memset(a, 0, sizeof(a));
//    int num = 0;
//    a[0] = a[1] = 1;
//    for(int i = 1; i <= n; i ++)
//    {
//        if(!a[i])
//            prime[num ++] = i;
//        for(int j = 0; j < num && i * prime[j]<=n; j ++)
//        {
//            a[i * prime[j]] = 1;
//            if(!(i%prime[j])) break;
//        }
//    }
//}

inline int gcd(int x, int y)
{
    return y==0? x: gcd(y, x%y);
}

int main ()
{
//    Prime();

    dp[1] = 2;
    for(int i = 2; i <= 10001; i ++)
    {
        dp[i] = dp[i - 1]+1;
        memset(a, 0, sizeof(a[0]) * i);
        for(int j = 2; j < i; j ++)
        {
            if(a[j] == 0)
            {
                if(gcd(i, j) == 1)
                {
                    dp[i] ++;
                }
                else
                {
                    for(int k = 2; k < 100000; k ++)
                    {
                        if(j * k > i)
                        break;
                        a[j*k] = 1;
                    }
                }
            }
        }
    }

    int t, n, N;
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d %d", &n, &N);
        printf("%d %d\n", n, dp[N]);
    }
    return 0;
}


//#include<cstdio>
//#include<cmath>
//
//inline int min(int x, int y)
//{
//    return x<y? x: y;
//}
//
//int dp[10006];
//
//inline int gcd(int a, int b)
//{
//    if(a == 0)
//    return b;
//    if(b == 0)
//    return a;
//    if(!(a&1) && !(b&1))
//        return gcd(a>>1, b>>1)<<1;
//    if(!(b&1))
//        return gcd(a, b>>1);
//    if(!(a&1))
//        return gcd(a>>1, b);
//    return gcd(std::abs(a-b), min(a ,b));
//}
//
//int main ()
//{
//    dp[1] = 2;
//    for(int i = 2; i <= 10001; i ++)
//    {
//        dp[i] = dp[i - 1] + 1;
//        for(int j = 2; j < i; j ++)
//        {
//            if(gcd(i, j) == 1)
//                dp[i] ++;
//        }
//    }
//
//    int t, n, N;
//    scanf("%d", &t);
//    while(t --)
//    {
//        scanf("%d %d", &n, &N);
//        printf("%d %d\n", n, dp[N]);
//    }
//    return 0;
//}
