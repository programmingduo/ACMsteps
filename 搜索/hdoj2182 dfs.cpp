#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;

int ans[50], vis[50], city[25][3];
int visited, total, n;

void dfs(int begain)
{
    //printf("1\n");
    ans[visited ++] = begain;
    //printf("%d ", visited);
    if(begain == n && visited == 21)
    {
        printf("%d: ", ++ total);
        for(int i = 0; i <= 20; i ++)
            printf(" %d", ans[i]);
        printf("\n");
        visited --;
        return ;
    }
    else if(begain == n && vis[n])
    {
        visited --;
        return ;
    }
    int temp;
    for(int i = 0; i < 3; i ++)
    {
        temp = city[begain][i];
        if(vis[temp])
            continue;
        vis[temp] = 1;
        dfs(temp);
        vis[temp] = 0;
    }
    visited --;
}

int main()
{
    int a, b, c;
    for(int i = 1; i <= 20; i ++)
    {
        scanf("%d%d%d", &a, &b, &c);
        if(a > b) swap (a, b);
        if(b > c) swap (b, c);
        if(a > b) swap (a, b);
        city[i][0] = a;
        city[i][1] = b;
        city[i][2] = c;
    }

    while(~scanf("%d", &n) && n)
    {
        memset(vis, 0, sizeof(vis));
        total = visited = 0;
        dfs(n);
    }
}
