#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

double sto[100010];
int main()
{
    int T, k, n, c, a, b, q;
    double t;
    scanf("%d", &T);
    while(T --){
        scanf("%d%d", &n, &c);
        for(int i = 0; i < n; i ++){
            scanf("%lf%d%d", &sto[i], &a, &b);
            sto[i] = abs(sto[i]);
        }
        sort(sto, sto+n);
        scanf("%d", &q);
        while(q --){
            scanf("%lf%d", &t, &k);
            printf("%.3f\n", double(sqrt(sto[k-1]*sto[k-1] + 2 * t * c)));
        }
    }

}
