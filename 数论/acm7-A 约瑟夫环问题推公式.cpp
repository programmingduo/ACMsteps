#include<cstdio>
#include<string.h>

int vis[100000];

int main ()
{
    int n, m, k, total;
    while(~scanf("%d%d%d", &n, &k, &m))
    {
        if(n == 0 && m == 0 && k == 0)
            break;
        int s = 0;
        for(int i = 2; i <= n; i ++)
        {
            s = (s + k) % i;
        }
        k = k % n;
        if(!k)  k = n;
        s = s + 1 + m - k;
        if(s > n)
            printf("%d\n", s % n);
        else if(s < 1)
            printf("%d\n", s + n);
        else
            printf("%d\n", s);
    }
    return 0;
}
