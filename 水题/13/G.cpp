#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

const int mod = 1e9+7;

typedef long long ll;

ll po[11];

ll mul(ll a, ll b){
    ll res = 1;
    while( b > 0 ) {
        if(b & 1) res *=a;
        res %= mod;
        a *= a;
        a %= mod;
        b >>=1;
    }
    return res;
}

int getLen(int v){
    int res = 0;
    while( v  > 0 ){
        res ++;
        v /= 10;
    }
    return res;
}


int main()
{
    ll n, m;
    po[0] = 1;
    for(int i = 1; i <= 10; i ++){
        po[i] = po[i-1] * 10;
    }
    int T;
    scanf("%d", &T);
    while(T --){
        scanf("%I64d%I64d", &m, &n);
        if(m == 1){
            printf("%I64d\n", n % mod);
            continue;
        }
        int len = getLen(n);
        ll q = po[len];
        //cout << q << " " << len;
        ll res = 0;
        res = n * mul(q, m) - n;
        res = (res + mod) % mod;
        res *= mul(q - 1, mod - 2);
        res %= mod;
        printf("%I64d\n", res);
    }
    return 0;
}










