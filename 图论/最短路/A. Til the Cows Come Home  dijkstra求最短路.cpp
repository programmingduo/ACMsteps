#include<cstdio>
#include<string.h>

using namespace std;

const int maxn = 2005;

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
            if(in[j] == 0 && distance[j] > distance[k] + map[j][k]
               && map[k][j != 1 << 30])
                distance[j] = distance[k] + map[j][k];
        }
    }

    printf("%d\n", distance[1]);
}

int main ()
{
    int T, a, b, c;
    scanf("%d%d", &T, &N);
    int temp = 1 << 30;
    for(int i = 1; i <= N; i ++)
        for(int j = 1; j <= N; j ++)
        map[i][j] = temp;

    for(int i = 0; i < T; i ++)
    {
        scanf("%d%d%d", &a, &b, &c);
        if(map[a][b] > c)
            map[a][b] = map[b][a] = c;
    }
    dijkstra(N);

}
