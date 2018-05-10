#include <iostream>
using namespace std;

#define ll long long 

ll expmod(ll a,ll b,ll n)
{
    ll re=1,y=a%n;
    while(b){
        if (b%2) re = (re*y)%n;
        b>>=1,y=(y*y)%n;
    }
    return re;
}


int main()
{
    ll ca, m, h;
    scanf("%I64d", &ca);
    while(ca --){
        scanf("%I64d %I64d", &m, &h);
        ll re = 0;
        for(int i = 0; i < h; i ++){
            ll a, b;
            scanf("%I64d %I64d", &a, &b);
            re = (re+expmod(a, b, m))%m;
        }
        printf("%I64d\n", re);
    }
    return 0;
}
