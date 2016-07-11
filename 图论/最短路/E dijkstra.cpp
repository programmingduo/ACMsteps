#include<cstdio>
#include<string.h>

using namespace std;

const int maxn = 1000;
int map[maxn][maxn], distance[maxn];
int N;
bool in[maxn];

void dijkstra(int v)
{
    for(int i = 1; i <= N; i ++)
    {
        distance[i] = map[v][i];
        in[i] = 0;
    }
    in[v] = 1;
    int k = 0;
    for(int i = 1; i <= N; i ++)
    {
        int mindistance = 1 << 30;
        for(int j = 1; j <= N; j ++)
            if(distance[j] < mindistance && in[j] == 0)
            {
                mindistance = distance[j];
                k = j;
            }
        in[k] = 1;
        for(int j = 1; j <= N; j ++)
        {
            if(in[j] == 0 && distance[j] > distance[k] + map[j][k])
                distance[j] = distance[k] + map[j][k];
        }
    }

    printf("%d\n", distance[1]);
}

int main ()
{
    while(scanf("%d", &N) && N != 0)
    {
        memset(map, 0x3f, sizeof(map));
        int a, b, c, temp = N * (N - 1) / 2;
        printf("temp = %d\n", temp);
        for(int i = 0; i < temp; i ++)
        {
            scanf("%d%d%d", &a, &b, &c);
            if(c < map[a][b])
                map[a][b] = map[b][a] = c;
        }
        dijkstra(N);
    }

}
