#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dist[256][256], val[256];
int cost[256][256];
int point[256];
bool cmp(int n1, int n2){
	return val[n1] < val[n2];
}

int max(int a, int b, int c){
	a >?= b;
	return a>c? a:c;
}
int main()
{
	int N, M, K, a, b, c;
	while(scanf("%d %d %d", &N, &M, &K) != EOF){
		memset(cost, 0x3f, sizeof(cost));
		memset(dist, 0x3f, sizeof(dist));
		for(int i = 1; i <= N; ++i){
			scanf("%d", &val[i]);
			point[i] = i;
		}
		sort(point+1, point+N+1, cmp);
		for(int i = 0; i < M; ++i){
			scanf("%d %d %d", &a, &b, &c);
			dist[a][b] = dist[b][a] <?= c;
			cost[a][b] = cost[b][a] = dist[a][b] + max(val[a], val[b]);
		}
		for(int i = 1; i <= N; ++i){
			dist[i][i] = 0;
			cost[i][i] = val[i];
		}
		for(int k = 1; k <= N; ++k){
			int v = point[k];
			for(int i = 1; i <= N; ++i)
				for(int j = 1; j <= N; ++j){
					if(dist[i][j] > dist[i][v] + dist[v][j]){
						dist[i][j] = dist[i][v] + dist[v][j];
						cost[i][j] = min(cost[i][j], dist[i][j]+max(val[i], val[j], val[v]));
					}
				}
		}
		for(int i = 0; i < K; ++i){
			scanf("%d %d", &a, &b);
			printf("%d\n", cost[a][b]);
		}
	}
	return 0;
}

