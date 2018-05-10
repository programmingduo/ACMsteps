#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <fstream>
#include <queue>
using namespace std;
typedef long long ll;

const int MAXN = 10010;
const int MAXK = 21;

struct qitem{
	int v, k;
	ll d;
	qitem(){}
	qitem(int _v, int _k, ll _d):v(_v), k(_k), d(_d){}
	bool operator < (const qitem & tq)const {
		return d > tq.d;
	}
};

vector<pair<int,int> >e[MAXN];

inline void add(int u, int v, int c){
	e[u].push_back(make_pair(v, c));
	e[v].push_back(make_pair(u, c));
}

ll dist[MAXN][MAXK];

void dijkstra(int n, int k){
	memset(dist, 0x1f, sizeof(dist));
	priority_queue<qitem> q;
	dist[1][0] = 0;
	q.push(qitem(1, 0, 0));
	while(!q.empty()){
		qitem tq = q.top();
		q.pop();
		if(tq.d != dist[tq.v][tq.k])continue;
		for(int i = 0; i < e[tq.v].size(); ++i){
			if(dist[e[tq.v][i].first][tq.k] > tq.d + e[tq.v][i].second){
				dist[e[tq.v][i].first][tq.k] = tq.d + e[tq.v][i].second;
				q.push(qitem(e[tq.v][i].first, tq.k, dist[e[tq.v][i].first][tq.k]));
			}
			if(tq.k < k && dist[e[tq.v][i].first][tq.k + 1] > tq.d){
				dist[e[tq.v][i].first][tq.k + 1] = tq.d;
				q.push(qitem(e[tq.v][i].first, tq.k + 1, tq.d));
			}
		}
	}
}
int main(){
	int n, m, k, a, b, c;
	while(scanf("%d %d %d", &n, &m, &k) != EOF){
		for(int i = 1; i <= n; ++i){
			e[i].clear();
		}
		for(int i = 0; i < m; ++i){
			scanf("%d %d %d", &a, &b, &c);
			add(a, b, c);
		}
		dijkstra(n, k);
		ll ans = dist[n][0];
		for(int i = 1; i <= k; ++i){
			ans = min(ans, dist[n][i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
