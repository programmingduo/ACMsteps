#include <stdio.h>
#include <string.h>
#define MAX 202
#define INF 0x1f1f1f1f

int mp[MAX][MAX];
int dist[MAX], flag[MAX];
int ans, k;

void dijkstra(int n, int s)
{
   int i, j, md, tmp;
   memset(dist, 0x1f, sizeof(dist));
   memset(flag, 0, sizeof(flag));
   dist[s] = 0;
   for (i = 0; i < n; ++i)
   {
      md = INF;
      for (j = 0; j < n; ++j)
         if (flag[j] == 0 && dist[j] < md) 
         {
            tmp = j;
            md = dist[j];
         }
      if (i == k)
      {
         ans = tmp;
         return;
      }
      flag[tmp] = 1;
      for (j = 0; j < n; ++j)
         if (flag[j] == 0 && md + mp[tmp][j] < dist[j])   //ËÉ³Ú²Ù×÷ 
            dist[j] = md + mp[tmp][j];
   }
}

int main()
{
   int i, a, b, c, n, m, s;
   while (scanf("%d%d", &n, &m) && n != 0)
   {
      memset(mp, 0x1f, sizeof(mp));
      for (i = 0; i < m; ++i)
      {
         scanf("%d%d%d", &a, &b, &c);
         mp[a][b] = mp[b][a] = c;
      }
      scanf("%d", &k);
      dijkstra(n, 0);
      printf("%d\n", ans);
   }
   return 0;
}
