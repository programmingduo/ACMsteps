#include<cstdio>
#include<string.h>

const int maxv = 100008;
int du[maxv], x[maxv], fa[maxv];
int getfa(int a)
{
    if(fa[a] == a)
        return a;
    return fa[a] = getfa(fa[a]);
}

void mergef(int a, int b)
{
    if(getfa(a) == getfa(b))
        return ;
    fa[fa[a]] = fa[b];
}

int max(int a, int b)
{
    return a > b? a:b;
}

int main ()
{
    int T, v, e, l, r, total, ans;
    scanf("%d", &T);
    while(T --)
    {
        memset(du, 0, sizeof(du));
        total = 0;
        ans = 0;
        scanf("%d %d", &v, &e);
        for(int i = 1; i <= v; i ++)
        {
            fa[i] = i;
        }
        for(int i = 1; i <= v; i ++)
        {
            scanf("%d", &x[i]);
        }

        for(int i = 0; i < e; i ++)
        {
            scanf("%d %d", &l, &r);
            mergef(l, r);
            du[l] ++;
            du[r] ++;
        }

        for(int i = 1; i <= v; i ++)
        {
            if(du[i] % 2)
                total ++;
            du[i] = du[i] + 1;
            du[i] /= 2;
            while(du[i] --)
                ans ^= x[i];
        }

        for(int i = 2; i <= v; i ++)
        {
            if(getfa(i) != getfa(i - 1))
            {
                total = 6;
                break;
            }
        }

        if(total >= 3 || total == 1)
            printf("Impossible\n");
        else if(total == 0)
        {
            int temp = -1;
            for(int i = 1; i <= v; i ++)
            {
                temp = max(temp, ans ^ x[i]);
            }
            printf("%d\n", temp);
        }
        else
        {
            printf("%d\n", ans);
        }
    }
    return 0;
}
