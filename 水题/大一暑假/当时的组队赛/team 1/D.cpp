#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int n, m;
#define maxn 1005
#define maxm 10010
const int INF = 1000000;

int xuemei[maxn];
int sumxuemei[maxn];

int d[maxn];
int w[maxn][maxn];
bool v[maxn];
void dijkstra(int s)
{
    memset(v, 0, sizeof(v));
    memset(sumxuemei, 0, sizeof(sumxuemei));
    for (int i = 1; i <= n; i++) d[i] = (i == s ? 0:INF);
    for (int i = 1; i <= n; i++){
        int x,m = INF;
        for (int y = 1; y <= n; y++) if(!v[y] && d[y] <= m) m = d[x = y];
        v[x] = 1;
        for (int y = 1; y <= n; y++){
            if(d[y] > d[x] + w[x][y]){
                d[y] = d[x] + w[x][y];
                sumxuemei[y] = sumxuemei[x] + xuemei[y];
            }
            if(d[y] == d[x] + w[x][y]){
                if(sumxuemei[y] < sumxuemei[x] + xuemei[y]){
                    sumxuemei[y] = sumxuemei[x] + xuemei[y];
                }
            }
        }
    }
}

int main()
{
    while(~scanf("%d%d", &n,&m)){
        for (int b = 1; b <= n; b++){
            scanf("%d", xuemei + b);
        }
        int beginn, endd, val;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                w[i][j] = INF;
            }
        }
        for (int i = 0; i < m; i++){
            scanf("%d%d%d", &beginn, &endd, &val);
            if(w[beginn][endd] > val){
                w[beginn][endd] = val;
                w[endd][beginn] = val;
            }
        }
        dijkstra(1);
        if(d[n] == INF) printf("-1\n");
        else
            printf("%d\n", sumxuemei[n] + xuemei[1]);
    }
    return 0;
}

//struct Edge{
//    int from, to, dist;
//    Edge(int u, int v, int d): from(u), to(v), dist(d){}
//};
//
//struct HeapNode{
//    int d, u;
//    bool operator < (const HeapNode& rhs) const {
//        return d > rhs.d;
//    }
//};
//
//struct Dijkstra{
//    int n, m;
//    vector<Edge> edges;
//    vector<int> G[maxn];
//    bool done[maxn];
//    int d[maxn];
//    int p[maxn];
//
//    void init(int  n){
//        this->n = n;
//        for (int i = 0; i < n; i++) G[i].clear();
//        edges.clear();
//        for (int i = 0; i <= n; i++) sumxuemei[i] = 0;
//    }
//
//    void AddEdge(int from, int to, int dist){
//        edges.push_back(Edge(from, to, dist));
//        m = edges.size();
//        G[from].push_back(m - 1);
//    }
//
//    void dijkstra(int s){
//        priority_queue <HeapNode> Q;
//        for (int i = 1; i <= n; i++) d[i] = INF;
//        d[s] = 0;
//        memset(done, 0, sizeof(done));
//        Q.push(HeapNode{0, s});
//        while(!Q.empty()){
//            HeapNode x = Q.top();
//            Q.pop();
//            int u = x.u;
//            if(done[u]) continue;
//            done[u] = true;
//            for (int i = 0; i < G[u].size(); i++){
//                Edge& e = edges[G[u][i]];
//                if(d[e.to] > d[u] + e.dist){
//                    d[e.to] = d[u] + e.dist;
//                    p[e.to] = G[u][i];
//                    sumxuemei[e.to] = sumxuemei[u] + xuemei[e.to];
//                    Q.push((HeapNode){d[e.to], e.to});
//                }
//                if(d[e.to] == d[u] + e.dist){
//                    if(sumxuemei[e.to] < sumxuemei[u] + xuemei[e.to]){
//                        sumxuemei[e.to] = sumxuemei[u] + xuemei[e.to];
//                    }
//                }
//            }
//        }
//    }
//};
//
//Dijkstra lu1;

//int main()
//{
//    while(cin >>n >> m){
//        lu1.init(n);
//        for (int b = 1; b <= n; b++){
//            scanf("%d", xuemei + b);
//        }
//        int beginn, endd, val;
//        for (int i = 0; i < m; i++){
//            scanf("%d%d%d", &beginn, &endd, &val);
//            for (int i = 0; i < lu1.m; i++){
//                Edge& ss = lu1.edges[i];
//                if(ss.from == beginn && ss.to == endd){
//                    if(ss.dist > val)
//                        ss.dist = val;
//                }
//                if(ss.from == endd && ss.to == beginn){
//                    if(ss.dist > val)
//                        ss.dist = val;
//                }
//            }
//            lu1.AddEdge(beginn, endd, val);
//        }
//        lu1.dijkstra(1);
//        cout << sumxuemei[n] + xuemei[1] <<endl;
//    }
//    return 0;
//}
