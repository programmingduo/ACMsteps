#include<cstdio>

int vertex, edge, aim, start;
int w[1004][1003], d[1004], used[1003];

int min(int a, int b)
{
    return a < b? a: b;
}

void init()
{
    for(int i = 0; i <= vertex; i ++)
    {
        for(int j = 0; j <= i; j ++)
        {
            if(i == j)
                w[i][j] = 0;
            else
                w[j][i] = w[i][j] = 0x3fffffff;
        }
    }
}

void dijkstra()
{
    for(int i = 1; i <= vertex; i ++)
    {
        used[i] = 0;
        d[i] = w[start][i];
    }
    used[start] = 1;
    int v;
    while(1)
    {
        v = -1;
        for(int i = 1; i <= vertex; i ++)
        {
            if(!used[i] && (v == -1 || d[i] < d[v]))
                v = i;
        }
        if(v == -1)
            break;
        used[v] = 1;
        for(int i = 1; i <= vertex; i ++)
        {
            d[i] = min(d[i], d[v] + w[v][i]);
        }
    }
}

int main ()
{
    while(~scanf("%d%d%d", &vertex, &edge, &start))
    {
        init();
        int a, b, c;
        for(int i = 0; i < edge; i ++)
        {
            //输入是应注意到，这个是单向图，而且同一条路可能花费时间不同
            scanf("%d%d%d", &a, &b, &c);
            if(w[b][a] > c)
                w[b][a] = c;
        }
        dijkstra();
        int t;
        scanf("%d", &t);
        int ans = 0x3fffffff;
        while(t --)
        {
            scanf("%d", &aim);
            ans = min(d[aim], ans);
        }
        if(ans == 0x3fffffff)
            printf("-1\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
