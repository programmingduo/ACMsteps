#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

int N,total;
int fa[105];

struct node
{
    int u,v,w;
}edge[10005];

struct node2
{
    int a,b;
}ans[105];

int find(int x)
{
    if(fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
     fa[x] = y;
}

bool cmp1(node a, node b)
{
    if(a.w != b.w)
        return a.w < b.w;
    return a.u < b.u;
}

bool cmp2(node2 a, node2 b)
{
    if(a.a != b.a)
        return a.a < b.a;
    return a.b < b.b;
}

int kruskal()
{
    int ansn = 0;
    sort(edge, edge + total,cmp1);
    for(int i = 0; i < total; i ++){
        int x = find(edge[i].u);
        int y = find(edge[i].v);
        if(x != y){
            merge(x,y);
            ans[ansn].a = edge[i].u;
            ans[ansn].b = edge[i].v;
            ansn ++;
        }
    }
    return ansn;
}

int main(int argc, char *argv[])
{
    int T, v;
    scanf("%d", &T);
    while(T --)
    {
        total = 0;
        scanf("%d", &N);
        for(int i = 1; i <= N; i ++)
        {
            fa[i] = i;
        }
        for(int i = 1; i <= N; i ++)
        {
            for(int j = 1; j <= N; j ++)
            {
                scanf("%d", &v);
                if(i < j && v > 0)
                {
                    edge[total].u = i;
                    edge[total].v = j;
                    edge[total].w = v;
                    total ++;
                }
            }
        }
        int all = kruskal();
        if(all != N - 1)
        {
            printf("-1\n");
        }
        else
        {
            sort(ans, ans + all, cmp2);
            for(int i = 0; i < all; i ++)
            {
                if(i)
                    printf(" ");
                printf("%d %d", ans[i].a, ans[i].b);
            }
            printf("\n");
        }
    }
    return 0;
}
