#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a > b ? b : a)
#define CL(a) memset(a, 0, sizeof(a))

using namespace std;

typedef long long ll;

const int inf = 1e9+7;
const int mod = 1e9+7;
const int maxn = 1e6+7;
const double eps = 1e-6;

int n;

struct node{
    ll x, y, w, h;
}rec[maxn];


ll getArea(ll mid){
    ll res = 0;
    for(int i = 0; i < n; i ++){
        if(rec[i].x + rec[i].w <= mid)
            res += rec[i].w * rec[i].h;
        else if (rec[i].x >= mid)
            res += 0;
        else 
            res += (mid - rec[i].x) * rec[i].h;
    }
    return res;
}

int main()
{
    int T;
    ll R;
    scanf("%d", &T);
    while(T --){
        scanf("%lld%d", &R, &n);
        ll total = 0;
        for(int i = 0; i < n; i ++){
            scanf("%lld%lld%lld%lld", &rec[i].x, &rec[i].y, &rec[i].w, &rec[i].h);
            total += rec[i].w * rec[i].h;
        }
        ll l = 0, r = R, mid;
        while(l <= r){
            //cout << l << " " << r << endl;
            mid = (l + r) / 2.0;
            ll area = getArea(mid);
            if(area * 2 > total)
                r = mid - 1;
            else{
                l = mid + 1;
            }
        }
        ll ans1 = getArea(l);
        ll ans2 = getArea(r);
        ll ans;
        //cout << l << " " << r;
        if(ans1 == ans2){
            ans = max(l, r);
            ans = min(R, ans);
        }
        else{
            if(abs(total - 2*ans1) < abs(total - 2*ans2))
                ans = l;
            else if (abs(total - 2*ans1) == abs(total - 2*ans2)){
                ans = max(l , r);
                ans = min(R, ans);
            }else
                ans = r;
        }
        printf("%lld\n", ans);
        
    }


	return 0;
}
