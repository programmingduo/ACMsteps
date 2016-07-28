#include<cstdio>
#include<string.h>
#include<algorithm>

struct node
{
    int l, r, pos, num, ans;
}a[100005];

int cmp1(node x, node y)
{
    return x.num < y.num;
}

int cmp2(node x, node y)
{
    return x.pos < y.pos;
}

int min(int x, int y)
{
    return x<y? x: y;
}

int c[100005];
int n;

int lowbit(int x)
{
    return x&-x;
}

void add(int i, int val)
{
    while(i <= n)
    {
        c[i] += val;
        i += lowbit(i);
    }
}

int sum(int i)
{
    int s = 0;
    while(i > 0)
    {
        s += c[i];
        i -= lowbit(i);
    }
    return s;
}

int main ()
{
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t ++)
    {
        scanf("%d", &n);
        memset(c, 0, sizeof(c[0]) * (n+1));
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d", &a[i].num);
            a[i].pos = i;
        }

        for(int i = n; i > 0; i --)
        {
            a[i].r = sum(a[i].num);
            add(a[i].num + 1, 1);
        }

        std::sort(a+1, a+n+1, cmp1);
        for(int i = 1; i <= n; i ++)
        {
            a[i].l = min(a[i].pos, i);
        }
//        std::sort(a+1, a+n+1, cmp2);
        for(int i = 1; i <= n; i ++)
        {
//            if(a[i].r)
//                a[i].r --;
            a[i].ans=a[i].pos + a[i].r - a[i].l;
        }
//        for(int i = 1; i <= n; i ++)
//        {
//            printf("%d %d %d %d\n", a[i].l, a[i].r, a[i].pos, a[i].ans);
//        }
        printf("Case #%d:", t);
        for(int i = 1; i <= n; i ++)
            printf(" %d", a[i].ans);
        printf("\n");
    }
    return 0;
}
