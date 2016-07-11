#include<cstdio>

int n, m, fa[50005];

void init()
{
    for(int i = 0; i <= n; i ++)
        fa[i] = i;
}

int findf(int son)
{
    if(fa[son] == son)
        return son;
    else
        return fa[son] = findf(fa[son]);
}

void combine(int a, int b)
{
    int tempa = findf(a);
    int tempb = findf(b);
    if(tempa != tempb)
        fa[tempb] = tempa, n --;
}

int main ()
{
    int a, b, ans, test = 0;
    while(scanf("%d%d", &n, &m) == 2 && n != 0 && m != 0)
    {
        init();
        ans = 0;
        test ++;
        while(m --)
        {
            scanf("%d%d", &a, &b);
            combine(a, b);
        }
        printf("Case %d: %d\n", test, n);
    }
    return 0;
}
