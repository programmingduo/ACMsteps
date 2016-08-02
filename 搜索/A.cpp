#include<cstdio>
#include<algorithm>
using namespace std;

int n, ans, a[10];

void dfs(int x, int now)
{
    if(x > n)
    {
        ans = ans > now? ans: now;
        return ;
    }
    char l[10];
    l[0] = '0';
    int f = 0, t = a[x];
    now += a[x];
    while(now != 0)
    {
        l[f ++] = now % 10 + '0';
        now /= 10;
    }

    if(f == 0)
        f ++;
    int t2 = 0;
    sort(l, l + f);
    do{
        t2 = 0;
        for(int i = 0; i < f; i ++)
            t2 = t2 * 10 + l[i] - '0';
//        printf("%d %d\n", x, t2);
            dfs(x + 1, t2);
    }while(next_permutation(l, l + f));
}

int main()
{
    while(~scanf("%d", &n))
    {
        ans = -1;
        for(int i = 0; i < n; i ++)
        {
            scanf("%d", &a[i]);
        }
        a[n] = 0;
        dfs(0, 0);
        printf("%d\n", ans);
    }
    return 0;
}
