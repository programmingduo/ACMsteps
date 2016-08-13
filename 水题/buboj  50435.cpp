#include<cstdio>
#include<algorithm>

struct node
{
    int x, y, ans;
}a[10005];

int cmp1(node x, node y)
{
    if(x.x == y.x)
        return x.y < y.y;
    return x.x < y.x;
}

int main()
{
    int n;
    while(~scanf("%d", &n) && n)
    {
        for(int i = 0; i < n; i ++)
        {
            scanf("%d %d", &a[i].x, &a[i].y);
            a[i].ans = 0;
        }
        std::sort(a, a + n, cmp1);
        int my = 0x3fffffff, ans = 0;
        for(int i = 0; i < n; i ++)
        {
            if(a[i].y < my)
            {
                ans ++;
                my = a[i].y;
            }
        }

        printf("%d\n",ans);
    }
    return 0;

}
