/*
    解同余方程模板 
*/ 
#include <iostream>
#include <cstdlib>
using namespace std;

#define ll int
#define mod(x, n) (((x)%(n)+(n))%(n))

ll expmod(ll a,ll b,ll n)
{
    ll re=1,y=a%n;
    while(b){
        if (b%2) re = (re*y)%n;
        b>>=1,y=(y*y)%n;
    }
    return re;
}

ll gcd(ll a,ll b,ll &x,ll &y) //ax+by=gcd
{
    if (!b){
       x=1, y=0;
       return a;
     }else{
            ll tp, bx, by;
            tp = gcd(b, a%b, x, y);
            bx = x, by = y;
            y=bx-(a/b)*by,  x=by;
            return tp;
          }
}

ll equation(ll a,ll b,ll n)//ax=b(mod n) return min x>=0;
{
    ll d,x,y;
    d = gcd(a,n,x,y);
    if (b%d) return -1;
    x = x*(b/d);
    x = mod(x, n/d);
    return x;
}

//------------------中国剩余定理---------------------------- 
ll chineseremain(ll *b,ll *m,ll n)//x=bi mod(ni) 解n组方程组 mi 两两互素 否则需要自己先处理 
{
    ll a, sm, x, y, t;
    a = 0, sm = 1;
    for(int i=0; i<n; i++) sm *= m[i];
    
    for(int i=0; i<n; i++){
        t = sm/m[i];
        gcd(m[i],t,x,y);
        a = (a+t*y*b[i])%sm;
    }
    return (a+sm)%sm; 
}

//-----------------步进法，不要求mi互素---------------------返回-1表示无解 
ll solvetwo(ll a1, ll m1, ll a2, ll m2, ll &lcm)
{
    ll x, y, tp;
    tp = gcd(m1, m2, x, y);
    if ((a1-a2)%tp) return -1;
        else lcm = m1/tp*m2;
    tp = (a1-a2)/tp*y*m2+a2;
    return mod(tp, lcm);
}

ll solveall(ll *b, ll *m, ll n) //解n组方程组，  不要求mi两两互素 
{
    int tb = b[0], tm = m[0], tp;
    for(int i = 1; i < n; i ++){
        tb = solvetwo(tb, tm, b[i], m[i], tm);
        if (tb == -1) return -1;
    }
    return mod(tb, tm); 
}


//---------------ai*x=bi mod mi 求解------------------------返回-1表示无解 
ll gcd(ll a, ll b)
{
    if (b == 0) return a;
        else return gcd(b, a%b);
}

ll inv(ll a, ll n)
{
    ll x, y, tp;
    tp = gcd(a, n, x, y); //ax+ny=tp
    if (tp == 1) return mod(x,n);
        else return -1;
}

ll solveall(ll *a, ll *b, ll *m, ll n)
{
    for(int i = 0; i < n; i ++){
        ll tp = gcd(a[i], m[i]);
        if (b[i] % tp) return -1;
            else a[i] /= tp, b[i] /= tp, m[i] /= tp;
        b[i] = ((inv(a[i], m[i])%m[i])*b[i])%m[i];
    }
    return solveall(b, m, n);
}

int main()
{
    int m[100], n, z, b[100], a[100], cn = 1, d;
    m[0] = 23, m[1] = 28, m[2] = 33;
    while(cin >> b[0] >> b[1] >> b[2] >> d, d != -1){
        a[0] = a[1] = a[2] = 1;
        n = 3;
        int x = solveall(a,b,m,n);
        x -= d;
        if (x <= 0) x +=  21252;
        printf("Case %d: the next triple peak occurs in %d days.\n", cn++, x);
    }
    return 0;
}
