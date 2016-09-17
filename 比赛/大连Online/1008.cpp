#include<cstdio>

int a[100005];

int F(int l, int r)
{
    if(l == r)
        return a[l];
    return F(l, r - 1) % a[r];
}

int main ()
{
    int T, n, l, r, m;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n;i  ++)
            scanf("%d", &a[i]);
        scanf("%d", &m);
        while(m --)
        {

            scanf("%d %d", &l, &r);
            printf("%d\n", F(l, r));
        }
    }
    return 0;
}
