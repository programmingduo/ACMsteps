#include<cstdio>
#include<algorithm>
using namespace std;

struct node
{
    int x, y, id;
} point[200010];
int to[200010], ans[1000000][2], now[200010], last[200010];
int cmp(node a, node b)
{
    if(a.y == b.y)
        return a.x < b.x;
    return a.y > b.y;
}

int main ()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        int n, temp, a, b;
        scanf("%d", &n);
        temp = n * 2;
        for(int i = 1; i <= temp; i ++)
        {
            scanf("%d%d", &(point[i].x), &(point[i].y));
            point[i].id = i;
        }
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d%d", &a, &b);
            to[a] = b;
            to[b] = a;
        }
        sort(point + 1, point + 1 + 2 * n, cmp);
        for(int i = 1; i <= temp; i ++)
        {
            now[i] = point[i].id;
            last[point[i].id] = i;
        }
        int len = 0;
        for(int i = 1; i <= n; i ++)
        {
            int l = 2 * i - 1;
            int r = 2 * i;
            if(to[now[l]] == now[r]) continue;
            else
            {
                ans[len][0] = now[r];
                ans[len][1] = to[now[l]];
                len ++;
                last[now[r]] = last[to[now[l]]];
                now[last[to[now[l]]]] = now[r];
                last[to[now[l]]] = r;
             }
//            a = i * 2 - 1; b = a + 1;
//            if(to[a] == b)
//                continue;
//            ans[len][0] = b;
//            ans[len ++][1] = to[a];
//            to[to[b]] = to[a];
//            to[to[a]] = to[b];
//            to[a] = b;
//            to[b] = a;
        }
        printf("%d\n", len);
        for(int i = 0; i < len; i ++)
        {
            printf("%d %d\n", ans[i][0], ans[i][1]);
        }
    }
    return 0;
}
