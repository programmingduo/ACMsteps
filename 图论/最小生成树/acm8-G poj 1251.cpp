#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

struct node
{
    int w;
    int x, y;
}edge[100];

int p[150];

int comp(node a, node b)
{
    return a.w < b.w;
}

int find(int x)
{
    return p[x] == x? x : p[x] = find(p[x]);
}

int main ()
{
    int n, t, c;
    int ans;
    char b;
    while(~scanf("%d", &n) && n)
    {
        ans = 0;
        int total = 0;
        for(int i = 0; i < n - 1; i ++)
        {
            scanf("%c%c", &b, &b);
            int a = b - 'A';
            scanf("%d", &t);
            while(t --)
            {
                scanf("%c%c%d",&b, &b, &c);
                edge[total].x = a;
                edge[total].y = b - 'A';
                edge[total].w = c;
                total ++;
            }
        }
        sort(edge, edge + total, comp);
        for(int i = 0; i < n; i ++)
            p[i] = i;
        for(int i = 0; i < total; i ++)
        {
            int a = find(edge[i].x);
            int b = find(edge[i].y);
            if(a != b)
            {
                ans += edge[i].w;
                p[a] = b;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
