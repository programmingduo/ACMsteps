#include<cstdio>
#include<algorithm>
#include<string.h>

int r[50002], c[50005], in[5000005];

struct node
{
    int x, y;
}a[500005];

int cmp1(node x, node y)
{
    if(x.x == y.x)
        return x.y < y.y;
    return x.x < y.x;
}
int cmp2(node x, node y)
{
    if(x.x == y.x)
        return x.y > y.y;
    return x.x < y.x;
}

int main ()
{
    int n;
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; i ++)
        {
            scanf("%d %d", &a[i].x, &a[i].y);
            xx[a[i].x] = 1;
            yy[a[i].y] = 1;
        }
        int flag = 1;
        std::sort(xx, sizeof(xx));
        std::sort(yy, sizeof(yy));
        for(int i = 0; i < 50005)

        std::sort(a, a + n, cmp1);
        memset(in, 0, sizeof(in));
        for(int i = 0; i < n && flag; i ++)
        {
            if(in[i])
                continue;
            in[i] = 1;
            memset(r, 0, sizeof(r));
            memset(c, 0, sizeof(c));
            int x = a[i].x, y = a[i].y;
            r[x] = 1;
            c[y] = 1;
            for(int j = i + 1; j < n && flag; j ++)
            {
                if(a[j].x >= x && a[j].y >= y)
                {
                    if(r[a[j].x] || c[a[j].y])
                        r[a[j].x] = 1, c[a[j].y] = 1;
                    else
                        flag = 0;
                }
            }
        }

        std::sort(a, a + n, cmp2);
        memset(in, 0, sizeof(in));
        for(int i = 0; i < n && flag; i ++)
        {
            if(in[i])
                continue;
            in[i] = 1;
            memset(r, 0, sizeof(r));
            memset(c, 0, sizeof(c));
            int x = a[i].x, y = a[i].y;
            r[x] = 1;
            c[y] = 1;
            for(int j = i + 1; j < n && flag; j ++)
            {
                if(a[j].x >= x && a[j].y <= y)
                {
                    if(r[a[j].x] || c[a[j].y])
                        r[a[j].x] = 1, c[a[j].y] = 1;
                    else
                        flag = 0;
                }
            }
        }

        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }

}
