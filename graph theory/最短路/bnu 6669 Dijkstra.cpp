//这个模板bug比较多。不可用
#include<cstdio>

int vertex, edge;
int used[105], d[105];
int w[105][106];

int min(int a, int b)
{
    return a < b? a: b;
}

void init()
{
    for(int i = 1; i <= vertex; i ++)
    for(int j = 1; j <= i; j ++)
    {
        if(i == j)
            w[i][j] = 0;
        else
            w[j][i] = w[i][j] = 0x3fffffff;
            //因为可能涉及到d+w，所以一定不能直接赋值为int的最大值
            //而改为最大值的一半
    }
}

void dijkstra()
{
    for(int i = 1; i <= vertex; i ++)
    {
        used[i] = false;
        d[i] = w[i][1];
    }

    int flag;
    while(1)
    {
        flag = -1;
        for(int i = 1; i <= vertex; i ++)
        {
            if(!used[i] && (flag == -1 || d[i] < d[flag]))
                flag = i;
        }
        if(flag == -1)
            break;
        used[flag] = 1;
        for(int i = 1; i <= vertex; i ++)
            d[i] = min(d[i], d[flag] + w[i][flag]);
        if(flag == vertex)
            break;
    }
}

int main ()
{
    while(~scanf("%d%d", &vertex, &edge))
    {
        if(!vertex && !edge)
            break;
        int a, b, c;
        init();
        for(int i = 0; i < edge; i ++)
        {
            scanf("%d%d%d", &a, &b, &c);
            w[a][b] = c;
            w[b][a] = c;
        }
        dijkstra();
        printf("%d\n", d[vertex]);
    }
    return 0;
}
