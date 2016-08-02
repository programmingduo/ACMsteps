#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

int t, n;
int num[100010];
ll sum, sqsum;

ll gcd(ll a, ll b){
    if(a < 0) a *= -1;
    if(b < 0) b *= -1;
    while(b != 0){
        ll temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

struct node{
    ll a;
    ll b;
};

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        sum = 0;
        sqsum = 0;
        for (int i = 0; i < n; i++){
            scanf("%d", &num[i]);
            if(num[i] < 0)
                sum -= num[i];
            else
                sum += num[i];
            sqsum += (num[i]*num[i]);
        }

        if(sum == 0){
            printf("0/1\n");
            continue;
        }

        node arf;
        ll _gcd = gcd(sum, n);
        arf.a = sum / _gcd;
        arf.b = n / _gcd;


        node res;
        ll hou = (n*arf.a - 2*sum*arf.b);
        ll _resgcd = gcd(hou, arf.b);
        hou /= _resgcd;
        ll houxia = arf.b / _resgcd;
        res.a = arf.a * hou;
        res.b = arf.b * houxia;
        _resgcd = gcd(res.a, res.b);
        res.a /= _resgcd;
        res.b /= _resgcd;

        //cout << "res=" << res.a << "/" << res.b << endl;

        res.a += (res.b * sqsum);
        _resgcd = gcd(res.a, res.b);
        res.a /= _resgcd;
        res.b /= _resgcd;

        printf("%lld/%lld\n", res.a, res.b);
//        cout << res.a << "/" << res.b << endl;

    }
    return 0;
}
