#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int maxn = 110;
const int maxf = 1e4 + 10;
const int inf  = 0x3f3f3f3f;

int d[maxf],d2[maxf],inq[maxf];

struct edge{
    int to,dist;
    edge(){}
    edge(int to,int dist):to(to),dist(dist){}
};

queue<int> q;

int n,w,u,v,dst,s,m,f;

vector<edge> g[maxf];

void bellman(int s,int d[]){
    memset(inq,0,sizeof inq);
    for(int i=0;i<maxf;i++){
        d[i] = inf;
    }
    d[s] = 0;
    inq[s] = 1;
    q.push(s);

    while(!q.empty()){
        int u = q.front();q.pop();
        inq[u] = 0;
       // printf("%d\n",u);
        for(int i=0;i<g[u].size();i++){
            edge& e = g[u][i];
           // printf("e.to: %d %d\n",e.to,inq[e.to]);

            if(d[u]<inf && d[e.to]>d[u]+e.dist){
              //  puts("43");
                d[e.to] = d[u] + e.dist;
                if(!inq[e.to]){
                 //   puts("46");
                    q.push(e.to);
                    inq[e.to] = 1;
                }
            }
        }
    }
}

void init(){
    while(!q.empty()) q.pop();
    for(int i=0;i<maxf;i++) g[i].clear();
}

int t = 1;

int main(){
    scanf("%d",&n);
    while(n--){
        printf("DATA SET #%d\n",t++);
        init();
        scanf("%d",&w);
        for(int i=0;i<w;i++){
            scanf("%d%d",&u,&v);
            if(u>v){
                dst = -((u-v)/4);
                g[u].push_back(edge(v,dst));
            }else if(v>u){
                dst = (v-u)/2;
                g[u].push_back(edge(v,dst));
            }
        }
        for(int i=1;i<9999;i++){
            g[i].push_back(edge(i+1,1));
        }
        scanf("%d%d",&s,&m);
        bellman(s,d);
     /*
        printf("%d\n",d[2010]);
        for(int i=0;i<g[2009].size();i++){
            printf("E: %d %d\n",g[2009][i].to,g[2009][i].dist);
        }
     */
        for(int i=0;i<m;i++){
            scanf("%d",&f);
            bellman(f,d2);
            int tot = 0;
            tot += d[f];
            tot += d2[s];
            if(tot>=inf) printf("IMPOSSIBLE\n");
            else printf("%d\n",tot);
        }
    }
    return 0;
}
