#include<cstdio>

const int maxn = 304;
int N, ans;
int flag[304];
struct node
{
    int val, key;
}a[maxn];

int GCD(int x, int y)
{
    if( y == 0)
        return x;
    return GCD(y, x % y);
}

int max(int x, int y)
{
    return x> y? x: y;
}

void dfs(int id, int tans)
{
    if(id >= N - 1)
    {
        ans = max(ans, tans);
        return ;
    }

    if(flag[id] == 0)
    {
        dfs(id + 1, tans);
    }
    else if(id + 1 < N - 1 && flag[id] == 1 && flag[id + 1] == 0)
    {
        dfs(id + 1, tans + a[id].val + a[id + 1].val);
    }
    else if(id + 3 < N - 1)
    {
        dfs(id + 2, tans + a[id].val + a[id + 1].val);
        dfs(id + 3, tans + a[id + 1].val + a[id + 2].val);
    }
    else if(id + 2 < N - 1)
    {
        dfs(id + 2, tans + a[id].val + a[id + 1].val);
    }
}

int main ()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d", &N);
        ans = -1;

        for(int i = 0; i < N; i ++)
        {
            scanf("%d", &a[i].key);
        }
        for(int i = 0; i < N; i ++)
        {
            scanf("%d", &a[i].val);
        }

        for(int i = 0; i < N - 1; i ++)
        {
            if(GCD(a[i].key, a[i + 1].key) != 1)
                flag[i] = 1;
            else
                flag[i] = 0;
        }
        dfs(0, 0);
        printf("%d\n", ans);
    }
}
