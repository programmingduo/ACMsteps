#include<cstdio>
#include<algorithm>
#include<iostream>
#include<iomanip>
using namespace std;
int a[305];

int main ()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i ++)
        {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        int total = 0;
        for(int i = 0; i < n; i ++)
        {
            for(int j = i + 1; j  < n; j ++)
            {
                if(a[j] > a[i])
                {
                    total += n - j;
                    break;
                }
            }
        }
        long double ans = (long double)total / (long double)(n * (n - 1));
        double r = ans;
        printf("%.6lf\n", r);
    }
    return 0;
}
