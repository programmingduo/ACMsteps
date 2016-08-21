#include<cstdio>
#include<queue>
#include<iostream>
#include<string.h>
#include<string>
#include<map>
using namespace std;

const int maxn = 20005;
int fa[maxn], head[maxn], to[maxn], mynext[maxn], dis[maxn];
int total;

void add(int a, int y)
{
    to[total] = y;
    mynext[total] = head[a];
    head[a] = total ++;

    to[total] = a;
    mynext[total] =head[y];
    head[y]  = total ++;
}

int findf(int x)
{
    if(fa[x] == x)
        return x;
    return fa[x] = findf(fa[x]);
}
void merge(int x, int y)
{
    int t1 = findf(x);
    int t2 = findf(y);
    if(t1 == t2)
        return;
    fa[fa[x]] = t2;
}

int liantong(int n)
{
    for(int i = 0; i < n; i ++)
    {
        for(int j = head[i]; j != -1; j = mynext[j])
        {
            if(findf[i] == findf[to[j]])
                continue;
            merge(i, to[j]);
        }
    }

    findf(0);
    for(int i = 1; i < n; i ++)
    {
        if(findf(i) != fa[i - 1])
            return 0;
    }
    return 1;
}

queue<int> q;

int bfs(int id, int n)
{
    memset(dis, 0, sizeof(dis));
    while(!q.empty())
        q.pop();
    q.push(id);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = head[u]; i != -1; i = mynext[i])
        {
            int v = to[i];
            if(dis[v] || v == id)
                continue;
            dis[v] = dis[u] + 1;
            q.push(v);
        }
    }
    int last = -1;
    for(int i = 0; i < n; i ++)
    {
        if(dis[i] > last)
        {
            last = dis[i];
        }
    }
    return last;
}

//int bfs(int n)
//{
//    memset(dis, 0, sizeof(dis));
//    while(!q.empty())
//        q.pop();
//    q.push(0);
//    dis[0] = 0;
//    while(!q.empty())
//    {
//        int u = q.front();
//        q.pop();
//        for(int i = head[u]; i != -1; i = mynext[i])
//        {
//            int v = to[i];
//            if(dis[v] || v == 0)
//                continue;
//            dis[v] = dis[u] + 1;
//            q.push(v);
//        }
//    }
//    int last = -1, id;
//    for(int i = 0; i < n; i ++)
//    {
//        if(dis[i] > last)
//        {
//            id = i;
//            last = dis[i];
//        }
//    }
//
//    return bfs2(id, n);
//}



map<string, int > m;

int main ()
{
    int n, m1;
    string s, s1, s2;
    while(~scanf("%d", &n) && n)
    {
        m.clear();
        total = 0;
        memset(head, -1, sizeof(head));
        for(int i  = 0; i < n; i++)
        {
            fa[i] = i;
        }
        for(int i = 0; i < n; i ++)
        {
            cin>> s;
            m[s] = i;
        }
        scanf("%d", &m1);
        while(m1 --)
        {
            cin>> s1>> s2;
            add(m[s1], m[s2]);
        }

        if(!liantong(n))
        {
            printf("-1\n");
            continue;
        }
        int ans = -1;
        for(int i = 0; i < n; i ++)
        {
            ans = max(ans, bfs(i, n));
        }
        printf("%d\n", ans);
    }
}
