#include<cstdio>
#include<algorithm>

struct node
{
    int x, y;
}b[105];

int cmp(node a, node c)
{
    return a.x < c.x;
}

int main ()
{
    int n;
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; i ++)
        {
            scanf("%d%d", &b[i].x, &b[i].y);
        }
        std::sort(b, b + n, cmp);
        int ans = 0, l, r;
        for(int i = 0; i < n; i ++)
        {
            ans ++;
            l = b[i].x, r = b[i].y;
            for(int j = i + 1; j < n; j ++)
            {
                if(b[j].x > r)
                    break;
                i ++;
                if(b[j].y < r)
                    r = b[j].y;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
