#include<cstdio>
#include<string.h>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;

int head[200005], to[200005], next_[200005], dis[200005];
int total;
queue<int> que;
set<int> se;
set<int>::iterator it;

void add_edge(int l, int r)
{
    next_[total] = head[r];
    to[total] = l;
    head[r] = total ++;

    next_[total] = head[l];
    to[total] = r;
    head[l] = total ++;
}

void BFS(int s)
{
    while(!que.empty())
    {
        int u = que.front();
        que.pop();
        set<int> temps;
        temps.clear();
        for(int i = head[u]; i != -1; i = next_[i])
        {
            int v = to[i];
            temps.insert(v);
        }

        it = se.begin();
        for(; it != se.end(); it ++)
        {
            int v = *it;
            if(temps.find(v) == temps.end())
            {
                se.erase(v);
                dis[v] = dis[u] + 1;
                que.push(v);
            }
        }
    }
}

int main ()
{
    int N, M, T, S;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d %d", &N, &M);
        memset(head, -1, sizeof(head));
        total = 0;
        int l, r;
        for(int i = 0; i < M; i ++)
        {
            scanf("%d %d", &l, &r);
            add_edge(l, r);
        }

        scanf("%d", &S);
        memset(dis, 0, sizeof(dis));
        for(int i = head[S]; i != -1; i = next_[i])
        {
            int v = to[i];
            dis[v] = -1;
        }


        se.clear();
        while(!que.empty())
            que.pop();
        for(int i = 1; i <= N; i ++)
        {
            if(dis[i] == 0 && i != S)
            {
                dis[i] ++;
                que.push(i);
            }
            if(dis[i] == -1)
            {
                se.insert(i);
            }
        }

        BFS(S);
        int flag = 0;
        for(int i = 1; i <= N; i ++)
        {
            if(i == S)
                continue;
            if(flag)
                printf(" ");
            printf("%d", dis[i]);
            flag = 1;
        }
        printf("\n");
    }
    return 0;
}
