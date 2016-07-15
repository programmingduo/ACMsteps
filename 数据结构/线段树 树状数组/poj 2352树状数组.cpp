#include<cstdio>
#include<string.h>

int a, b, ans[150005], s[32005];
int n;

int lowbit(int x)
{
    return x &(-x);
}

void add(int x, int val)
{
    for(int i = x; i <= 32003; i += lowbit(i))
    {
        s[i] += val;
//        printf("%d ", i);
    }
}

int sum(int x)
{
    int re = 0;
    for(int i = x; i > 0; i -= lowbit(i))
    {
        re += s[i];
    }
    return re;
}

int main ()
{
    int t;
    while(~scanf("%d", &n))
    {
        memset(s, 0, sizeof(s));
        memset(ans, 0, sizeof(ans));
        for(int i = 0; i < n; i ++)
        {
            scanf("%d %d", &a, &b);
            a ++;
            ans[sum(a)] ++;;
//            printf("%d %d\n", a[i], sum(a[i]));
            add(a, 1);
        }
        for(int i = 0; i < n; i  ++)
            printf("%d\n", ans[i]);
    }
    return 0;
}
