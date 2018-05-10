#include <iostream>
#include <vector>
using namespace std;

#define maxn 100001
#define ll long long

vector <ll> prim;
ll np;
bool fg[maxn] = {0};
int phi[maxn];

ll expmod(ll a,ll b,ll n)//a^b %m 注意可能要用long long时用long long 
{
    ll re = 1, y = a%n;
    for(; b; b>>=1, y = (y*y)%n)
        if (b&1)re = (re*y)%n;
    return re;
}

void geteuler(ll mx)
{
    for(ll i = 2; i < mx; i ++){
        if (!fg[i]){
            np ++;
            prim.push_back(i);
            phi[i] = i-1;
        }
        for(ll j = 0; j < np && i*prim[j] < mx; j ++){
            fg[i*prim[j]] =  1;
            if (i % prim[j] == 0){
                phi[i*prim[j]] = phi[i]*prim[j];
                break;
            }else phi[i*prim[j]] = phi[i]*phi[prim[j]];
        }
    }
}

int main()
{
    geteuler(maxn);
    ll p;
    while(scanf("%I64d", &p) != EOF){
        cout << phi[p-1] << endl;
    }
    return 0;
}
