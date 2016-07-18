#include<cstdio>
#include<string.h>

int n, m;
int vis[105], link[105], graph[106][106], in[105], use[105];

bool dfs(int index)
{
    for(int i = 1; i <= m; i ++)
    {
        if(graph[index][i] && vis[i] == 0)
        {
            vis[i] = 1;
            if(link[i] == 0 || dfs(link[i]))
            {
                link[i] = index;
                use[index] = 1;
                return 1;
            }
        }
    }
    return false;
}

int search()
{
    memset(link, 0, sizeof(link));
    memset(use, 0, sizeof(use));
    int m = 0;
    for(int i = 1; i <= n; i ++)
    {
        memset(vis, 0, sizeof(vis));
        if(dfs(i))
            m ++;
    }
    return m;
}

int main()
{
    int T = 1, k, a, b;
    while(~scanf("%d %d %d", &n, &m, &k))
    {
        memset(graph, 0, sizeof(graph));
        memset(in, 0, sizeof(in));
        while(k --)
        {
            scanf("%d %d", &a, &b);
            graph[a][b] = 1;
        }

        int ans = search();
        int ness = 0;
        for(int i = 1; i <= n; i ++)
        {
            if(!use[i])
                continue;
            for(int j = 1; j <=m; j ++)
            {
                if(!graph[i][j])
                    continue;
                graph[i][j] = 0;
                if(search() < ans)
                    ness++;
                graph[i][j] = 1;
            }
        }

        printf("Board %d have %d important blanks for %d chessmen.\n", T ++, ness, ans);
    }
}

//#include <cstdio>
//#include <cstring>
//#include <vector>
//using std::vector;
//const int maxn = 102;
//
//int k,n,m;
//int match[maxn],Match[maxn];
//bool used[maxn];
//
//int g[maxn][maxn];
//
//bool dfs(int u){
//    for(int v=1;v<=m;v++){
//        if(g[u][v]&&!used[v]){
//            used[v] = true;
//            if(match[v]==-1||dfs(match[v])){
//                match[v] = u;
//                return true;
//            }
//        }
//    }
//    return false;
//}
//
//int hungary(){
//    int ret=0;
//    memset(match,-1,sizeof match);
//    for(int u=1;u<=n;u++){
//        memset(used,0,sizeof used);
//        if(dfs(u)) ret++;
//    }
//    return ret;
//}
//
//int cas = 1;
//
//int main(){
//    while(~scanf("%d%d%d",&n,&m,&k)){
//        memset(g,0,sizeof g);
//        int x,y;
//        while(k--){
//            scanf("%d%d",&x,&y);
//            g[x][y] = 1;
//        }
//        int mx = hungary();
//        for(int i=1;i<=m;i++){
//            Match[i] = match[i];
//        }
//        int ans = 0;
//        for(int i=1;i<=m;i++){
//            if(Match[i]!=-1){
//                g[Match[i]][i] = 0;
//                if(hungary()<mx) ans++;
//                g[Match[i]][i] = 1;
//            }
//        }
//        printf("Board %d have %d important blanks for %d chessmen.\n",cas++,ans,mx);
//    }
//    return 0;
//}
