#include<cstdio>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
const int MAXN = 1000000;
double ans[MAXN];

int main ()
{
    ans[0] = 0;
    double tt = 1.0;
    for(int i = 1; i < MAXN; i ++)
    {
        ans[i] = ans[i - 1] + 1 / tt / tt;
        tt += 1;
//        printf("%.5lf\n", ans[i]);
    }

    string n;
    while(cin>> n)
    {
        if(n.length() >= 7)
        {
            printf("%.5lf\n", ans[MAXN - 1]);
            continue;
        }
        int x = 0;
        for(int i = 0; i < n.length(); i ++)
        {
            x = x * 10 + n[i] - '0';
        }
        printf("%.5lf\n", ans[x]);
    }
    return 0;
}
