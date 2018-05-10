#include <stdio.h>
#include <string.h>
#define MAX 102
#define INF 1000000000

int mp[MAX][MAX];
int dist[MAX], flag[MAX];

void dijkstra(int n, int s)   //n顶点数, 本题从下标从1开始, s为起点 
{
   int i, j, md, tmp;
   for (i = 1; i <= n; ++i)
   {
      dist[i] = INF;         //初始距离无穷大
      flag[i] = 0;           //S集为空
   }
   dist[s] = 0;
   for (i = 1; i < n; ++i)   //循环 n - 1次 
   {
      md = INF;
      for (j = 1; j <= n; ++j)
         if (flag[j] == 0 && dist[j] < md) 
         {
            tmp = j;
            md = dist[j];
         }
      flag[tmp] = 1;        //将tmp加入S集
      for (j = 1; j <= n; ++j)
         if (flag[j] == 0 && md + mp[tmp][j] < dist[j])   //松弛操作 
            dist[j] = md + mp[tmp][j];
   }
}

int main()
{
   int i, j, a, b, c, n, m, s;
   while (scanf("%d%d", &n, &m) && n != 0)
   {
      for (i = 1; i <= n; ++i)
         for (j = 1; j <= n; ++j)
            mp[i][j] = INF;
      for (i = 0; i < m; ++i)
      {
         scanf("%d%d%d", &a, &b, &c);
         mp[a][b] = mp[b][a] = c;
      }
      dijkstra(n, 1);
      printf("%d\n", dist[n]);
   }
   return 0;
}
