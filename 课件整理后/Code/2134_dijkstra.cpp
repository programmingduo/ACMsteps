#include<stdio.h>
#include<string.h>
#define MAX 102

int n, m, flag[MAX];
double map[MAX][MAX], dist[MAX];

void dijkstra() {
    int i, j, tem;
    double max;
    memset(flag, 0, sizeof(flag));
    memset(dist, 0, sizeof(dist));
    dist[1] = 1;
    for (i = 1; i <= n; ++i){
        max = 0;
        for (j = 1; j <= n; ++j)
            if(flag[j] == 0 && max < dist[j]) {
                tem = j; max = dist[j];
            }
        flag[tem] = 1;
        for (j = 1; j <= n; ++j)
            if (flag[j] == 0 && dist[j] < map[tem][j] * max) {
                dist[j] = map[tem][j] * max;
            }
    }
    printf("%.6lf percent\n", dist[n] * 100);
}

int main() {
    int i, j, x, y;
    double p;
    while (scanf("%d", &n), n) {
        scanf("%d", &m);
        memset(map, 0, sizeof(map));
        for(i = 0; i < m; ++i) {
            scanf("%d%d%lf", &x, &y, &p);
            map[x][y] = map[y][x] = p / 100;
        }
        dijkstra();
    }
    return 0;
}
