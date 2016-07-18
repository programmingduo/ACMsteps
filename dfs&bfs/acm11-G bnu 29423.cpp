#include<cstdio>
#include<string>
#include<iostream>
#define mod (long long) 1e9+7
#defind mod 1000000007
using namespace std;

long long multi(long long a, long long b, long long mod0)
{
    long long ret;
    ret = 1;
    while(b > 0)
    {
        if(b & 1)
            ret  = ret * a % mod0;
        a = (a * a) % mod0;
        b = b >> 1;
    }
    return ret;
}

int main ()
{
    int n;
    string a, b;
    while(~scanf("%d", &n))
    {
        int flag1 = 0, flag2 = 0;
        cin>> a>> b;
        for(int i = 0; i < n; i ++)
        {
            if(a[i] != '?' && b[i] != '?')
            {
                if(a[i] > b[i])
                    flag1 = 1;
                if(a[i] < b[i])
                    flag2 = 1;
            }
        }

        if(flag1 && flag2)
        {
            long long total = 0;
            for(int i = 0; i < n; i ++)
            {
                if(a[i] == '?')
                    total ++;
                if(b[i] == '?')
                    total ++;
            }
            long long ans = multi(10, total, mod);
            printf("%I64d\n", ans % mod);
        }
        else if(flag1)
        {
            long long total = 0;
            long long can = 1;
            for(int i = 0; i < n; i ++)
            {
                if(a[i] == '?' && b[i] == '?')
                {
                    total += 2;
                    can = (can * 55) % (mod);
                }
                else if(b[i] == '?')
                {
                    total ++;
                    can *= (a[i] - '0' + 1);
                    can %= mod;
                }
                else if(a[i] == '?')
                {
                    total ++;
                    can *= 10 - (b[i] - '0');
                    can %= mod;
                }
            }
            long long ans = multi(10, total, mod);
            printf("%I64d\n", (ans + mod - can)%mod);
        }
        else if(flag2)
        {
            long long total = 0;
            long long can = 1;
            for(int i = 0; i < n; i ++)
            {
                if(a[i] == '?' && b[i] == '?')
                {
                    total += 2;
                    can = (can * 55) % (mod);
                }
                else if(a[i] == '?')
                {
                    total ++;
                    can *= (b[i] - '0' + 1);
                    can %= mod;
                }
                else if(b[i] == '?')
                {
                    total ++;
                    can *= 10 - (a[i] - '0');
                    can %= mod;
                }
            }
            long long ans = multi(10, total, mod);
            printf("%I64d\n", (ans + mod - can) % mod);
        }
        else
        {
            int temp = 0;
            long long can1 = 1, can2 = 1;
            long long can, wei = 0, total = 0;
            for(int i = 0; i < n; i ++)
            {
                if(a[i] == '?' && b[i] == '?')
                {
                    can1 = can1 * 55 % mod;
                    can2 = can2 * 55 % mod;
                    wei += 2;
                    total ++;
                }
                else if(a[i] == '?')
                {
                    wei ++;
                    can1 *= b[i] - '0' + 1;
                    can1 %= mod;
                    can2 *= 10 - (b[i] - '0');
                    can2 %= mod;
                }
                else if(b[i] == '?')
                {
                    wei ++;
                    can2 *= a[i] - '0' + 1;
                    can2 %= mod;
                    can1 *= 10 - (a[i] - '0');
                    can1 %= mod;
                }
            }
            can = can1 + can2 - multi(10, total, mod) + mod;
            can %= mod;
            long long ans = multi(10, wei, mod);
            printf("%I64d\n", (ans + mod- can) % mod);
        }
    }
    return 0;
}
