#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1e5+7;
const int mod = 998244353;

typedef long long ll;

ll sto[maxn];

ll mul(ll a, ll b){
    ll res = 1;
    while( b > 0 ){
        if(b & 1) res *= a;
        res %= mod;
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return res;
}

ll zuhe(ll a, ll b){
    a = a > b - a ? b - a : a;
    ll res = 1;
    for(int i = 0; i < a; i ++){
        res *= (b - i);
        res /= (i+1);
        res %= mod;
    }
    return res;
}

ll ans[maxn], dp[2][maxn];

int main()
{
    int T, n;
    scanf("%d", &T);
    while(T --){
        scanf("%d", &n);
        for(int i = 0; i < n; i ++){
            scanf("%lld", &sto[i]);
        }
        sort(sto, sto+n);
        //memset(dp, 0 ,sizeof(dp));
        for(int i = 1; i <= n; i ++){
            dp[0][i] = 1;
            k[i]`
        }




    }

    return 0;
}




