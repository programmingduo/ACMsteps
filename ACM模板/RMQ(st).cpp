#include<cstdio>
#include<cmath>

int max(int x, int y)
{
    return x>y? x: y;
}
int min(int x, int y)
{
    return x<y? x: y;
}

int a[50005];
int st_min[50005][20], st_max[50006][20];

void initst(int n)
{
    for(int i = 0; i < n; i ++)
    {
        st_min[i][0] = st_max[i][0] = a[i];
    }

    for(int j = 1; (1<<j) < n; j ++)
    {
        for(int i = 0; i + (1<<j) <= n; i ++)
        {
            st_min[i][j] = min(st_min[i][j - 1], st_min[i + (1<<(j-1))][j-1]);
            st_max[i][j] = max(st_max[i][j - 1], st_max[i+(1<<(j-1))][j-1]);
        }
    }
}

int queryst_max(int l, int r)
{
    int k = (int)(log(r-l+1.0)/log(2.0));
    return max(st_max[l][k], st_max[r-(1<<k)+1][k]);
}

int queryst_min(int l, int r)
{
    int k = (int)(log(r-l+1.0)/log(2.0));
    return min(st_min[l][k], st_min[r-(1<<k)+1][k]);
}

int main ()
{
    int n, m, l, r;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i ++)
    {
        scanf("%d", a+i);
    }
    initst(n);
    while(m --)
    {
        scanf("%d %d", &l, &r);
        l --;
        r --;
        int x=queryst_max(l, r);
        int y=queryst_min(l, r);
        printf("%d\n", x-y);
    }
    return 0;
}
