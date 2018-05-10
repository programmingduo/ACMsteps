/*
求无向图的最小环路（环路上的结点个数大于二）
若是有向图我们可以直接用 Floyd 来做，但对于无向图呢.....
依然可以利用的 Floyd 来做的
算法证明：
	一个环中编号最大的结点为k，与它相连的两个结点为i 与j 则这个环路的长度为 mp[i][k] + mp[k][j] + dist[i][j](dist[i][j] 为所有结点编号都小于k的最小路径长度)。
	根据 Floyd 原理，在做完最外层k-1次循环后dist[i][j]为从i到j中所有结点编号都小于k的最短路径
	综上：该算法能找到最短环路。

for(int k = 1; k <= v; ++k){
        //枚举编号小于k的结点对
        for(int i = 1; i < k; ++i)
            for(int j = i+1; j < k; ++j){
                if(mp[i][k] + mp[k][j] + dist[i][j] < ans){
                    //更新ans 并记录路径
                }
            }
        //下面依然是原封不动的 Floyd
        for(int i = 1; i <= v; ++i)
            for(int j = 1; j <= v; ++j)if(dist[i][j] > dist[i][k] + dist[k][j]){
                dist[i][j] = dist[i][k] + dist[k][j];
                path[i][j] = path[i][k];
            }
    }

*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

const int MAXN = 102;
const int INF = (1<<28);
int edge[MAXN][MAXN], path[MAXN][MAXN],mp[MAXN][MAXN];
vector<int> Stack;

int Floyd(int v){
    for(int i = 1; i <= v; ++i)
        for(int j = 1; j <= v; ++j)
            path[i][j] = j;
    int ans = INF;
    for(int k = 1; k <= v; ++k){
        for(int i = 1; i < k; ++i)
            for(int j = i+1; j < k; ++j){
                if(mp[i][k] + mp[k][j] + edge[i][j] < ans){
                    ans = mp[i][k] + mp[k][j] + edge[i][j];
                    Stack.clear();
                    int v = i;
                    Stack.push_back(v);
                    while(path[v][j] != j){
                        v = path[v][j];
                        Stack.push_back(v);
                    }
                    Stack.push_back(j);
                    Stack.push_back(k);
                }
            }
        for(int i = 1; i <= v; ++i)
            for(int j = 1; j <= v; ++j)if(edge[i][j] > edge[i][k] + edge[k][j]){
                edge[i][j] = edge[i][k] + edge[k][j];
                path[i][j] = path[i][k];
            }
    }
    return ans;
}
int main(int argc, char** argv) {
    int i,j,a,b,k,n,m,c;
    while(scanf("%d%d",&n,&m) != EOF){
        for(i = 1; i <= n; ++i)
            for(j = 1; j <= n; ++j)
                mp[i][j] = mp[j][i] = edge[i][j] = edge[j][i] = INF;
        for(i = 1; i <= m; ++i){
            scanf("%d%d%d",&a,&b,&c);
            if(a == b)continue;
            edge[a][b] = edge[b][a] = min(edge[b][a], c);
            mp[a][b] = mp[b][a] = edge[a][b];
        }
        k = Floyd(n);
        if(k == INF){
            printf("No solution.\n");
        }
        else{
            for(i = 0; i < Stack.size() -1; ++i)
                printf("%d ", Stack[i]);
            printf("%d\n",Stack[i]);
        }
    }
    return (EXIT_SUCCESS);
}
