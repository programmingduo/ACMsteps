#include<iostream>
#include<cstdio>
using namespace std;

const long long N = 10000010;                   //N表示要处理的数的个数
long long prime[N] = {0},num_prime = 0;    // 存储素数和素数的个数
int isNotPrime[N] = {1, 1};           //一个辅助数组

//a是底数，b是指数，mod是取模
long long multi(long long a, long long b, long long mod)
{
    long long ret;
    ret = 1;
    while(b > 0)
    {
        if(b & 1)
            ret  = ret * a % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return ret;
}

int main()
{
    for(long i = 2 ; i < N ; i ++)
    {
        if(! isNotPrime[i])
        {
            prime[num_prime ++]=i;
        }

        for(long j = 0 ; j < num_prime && i * prime[j] <  N ; j ++)
        {
            isNotPrime[i * prime[j]] = 1;
            if(!(i % prime[j]))
            {
                break;
            }
        }
    }
    int T;
    long long n;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++)
    {
        long long temp, ans = 1;
        scanf("%lld", &n);
        for(int i = 0; i < num_prime; i ++)
        {
            if(n / prime[i] == 1)
                break;
            temp = n / prime[i];
            while(temp != 1)
            {
                temp /= prime[i];
                ans = ans * prime[i] % 1000000007;
            }
        }
        printf("Case %d: %lld\n", t, ans);
    }
    return 0;
}
