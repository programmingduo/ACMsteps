#include<cstdio>
#include<cmath>

int a[100005], b[100005];
int st_max[100005][20];
int max(int l, int r)
{
    return l>r? l: r;
}
void st_init(int n)
{
    for(int i = 0; i < n; i ++)
        st_max[i][0] = b[i];

    for(int j = 1; 1<<j < n; j ++)
        for(int i = 0; i + (1<<j) <= n; i ++)
            st_max[i][j] = max(st_max[i][j-1], st_max[i+(1<<(j-1))][j-1]);
}

int query_st(int l, int r)
{
    if(l > r)
        return 0;
    int k = (int)(log(r-l+1.0)/log(2.0));
    return max(st_max[l][k], st_max[r-(1<<k)+1][k]);
}

int main ()
{
    int n, m, l, r, total;
    while(~scanf("%d", &n) && n)
    {
        scanf("%d", &m);
        b[0] = 1;
        for(int i = 0; i < n; i ++)
        {
            scanf("%d", &a[i]);
            if(i)
            {
                if(a[i] == a[i - 1])
                    b[i] = b[i-1] + 1;
                else
                    b[i] = 1;
            }
        }
        st_init(n);
        while(m --)
        {
            scanf("%d %d", &l, &r);
            l --, r --;
            total = 1;
            for(int i = l+1; i <=r; i ++)
            {
                if(a[i] == a[i-1])
                    total ++;
                else
                    break;
            }
            printf("%d\n", max(total, query_st(l+total, r)));
        }
    }
    return 0;
}
