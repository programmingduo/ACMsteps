#include<stdio.h>
#include<iostream>
#include<string.h>
#include<iostream>

using namespace std;

const long long MAXN=100010;
long long first[MAXN], second[MAXN], num[MAXN], l[MAXN], r[MAXN], d[MAXN];

long long  lowbit(long long x)
{
    return x&(-x);
}

void add(long long i,long long val, long long c[], long long n)
{
    while(i <= n)
    {
        c[i] += val;
        i += lowbit(i);
    }
}

long long sum(long long i, long long *c)
{
    long long s = 0;
    while(i > 0)
    {
        s += c[i];
        i -= lowbit(i);
    }
    return s;
}

int main()
{
    long long a, b, n, m, k;
    while(cin>> n>> m>> k)
    {
        for(long long i = 1; i <= n; i ++)
            cin>> num[i];
        for(long long i = 1; i <= m; i ++)
            cin>> l[i]>> r[i]>> d[i];
        memset(first,0,sizeof(first));
        memset(second, 0, sizeof(second));
        for(long long i = 0; i < k; i ++)
        {
            cin>> a>> b;
            add(a, 1, first, m);
            add(b + 1, -1, first, m);
        }
        for(long long i = 1; i <= m; i ++)
        {
            long long temp = sum(i, first);
            temp *= d[i];
            add(l[i], temp, second, n);
            add(r[i] + 1, -temp, second, n);
        }
        cout<< num[1] + sum(1, second);
        for(long long i = 2; i <= n; i ++)
            cout<< " "<< num[i] + sum(i, second);
        cout<< endl;
    }
    return 0;
}
