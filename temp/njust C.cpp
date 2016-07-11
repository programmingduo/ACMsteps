#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <vector>
#include <string>
#include <time.h>
#include <math.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
const int inf = 1e8;
const double eps = 1e-8;
const double pi = acos(-1.0);
template <class T>
inline bool rd(T &ret) {
    char c; int sgn;
    if(c=getchar(),c==EOF) return 0;
    while(c!='-'&&(c<'0'||c>'9')) c=getchar();
    sgn=(c=='-')?-1:1;
    ret=(c=='-')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
    ret*=sgn;
    return 1;
}
template <class T>
inline void pt(T x) {
    if (x <0) { putchar('-');x = -x; }
    if(x>9) pt(x/10);
    putchar(x%10+'0');
}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 1e5;
ll prime[N],primenum;//有primenum个素数 math.h
void PRIME(ll Max_Prime){
    primenum=0;
    prime[primenum++]=2;
    for(ll i=3;i<=Max_Prime;i+=2)
    for(ll j=0;j<primenum;j++)
        if(i%prime[j]==0)break;
        else if(prime[j]>sqrt((double)i) || j==primenum-1)
        {
            prime[primenum++]=i;
            break;
        }
}
ll l, r, n;
vector<ll>fac;
void factor(ll x){
    fac.clear();
    for(int i = 0; i < primenum && prime[i]*prime[i]<= x; i++)
    {
        if(x%prime[i])continue;
        fac.push_back(prime[i]);
        while(x%prime[i]==0)x/=prime[i];
    }
    if(x!=1)fac.push_back(x);
//  cout<<x<<" " ;puts("factor:");  for(int i = 0; i < fac.size(); i++){
//      pt(fac[i]); puts("**");
//  }
}
ll solve(ll x){//计算与x有2个及以上的因子个数
    if(x<=0)return 0;
    if(x == 1)return 1;
    ll sum = 0, siz = (int)fac.size();
    for(int i = 1; i < (1<<siz); i++)
    {
        ll lcm = 1, one = 0;
        for(int j = 0; j < siz; j++)
            if(i & (1<<j))
            {
                lcm *= fac[j];
                one++;
            }
        if(one&1)
            sum += x/lcm;
        else sum -= x/lcm;
    }
    return x-sum;
}
int main(){
    PRIME(1e5+10);
    int T, Cas = 1;
    rd(T);
    while(T-->0){
        rd(l); rd(r); rd(n);
        factor(n);
        pt(solve(r)-solve(l-1)); puts("");
    }
    return 0;
}
