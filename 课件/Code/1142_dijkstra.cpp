#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 202
#define INF 100000000
#define max(a, b) ((a) > (b) ? (a) : (b))

double x[MAX], y[MAX];
double mp[MAX][MAX], dist[MAX];
int flag[MAX];

double cal_dist(int i, int j)
{
   return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));   
}

void dijkstra(int n, int s)  //n顶点数, 本题从下标从0开始, s为起点 
{
   int i, j, tmp;
   double md;
   for (i = 0; i < n; ++i)
   {
      dist[i] = INF;       //初始距离无穷大
      flag[i] = 0;         //S集为空
   } 
   dist[s] = 0.0;
   for (i = 1; i < n; ++i)   //循环 n - 1次 
   {
      md = INF;
      for (j = 0; j < n; ++j)
         if (flag[j] == 0 && dist[j] < md) 
         {
            tmp = j;
            md = dist[j];
         }
      if (tmp == 1)    //已经访问到目标点， 可以退出了 
         break;
      flag[tmp] = 1;        //将tmp加入S集
      for (j = 0; j < n; ++j)
         if (flag[j] == 0 && mp[tmp][j] < dist[j] && md < dist[j])
            dist[j] = max(mp[tmp][j], md);         //取最大值 
   }
}

int main()
{
   int i, j, cas, n;
   cas = 1;
   while (scanf("%d", &n), n != 0)
   {
      scanf("%lf%lf%lf%lf", &x[0], &y[0], &x[1], &y[1]);
      for (i = 2; i < n; ++i)
         scanf("%lf%lf", &x[i], &y[i]);
      for (i = 0; i < n; ++i)
         for (j = i + 1; j < n; ++j)
            mp[i][j] = mp[j][i] = cal_dist(i, j);
      dijkstra(n, 0);
      printf("Scenario #%d\nFrog Distance = %.3lf\n\n", cas++, dist[1]);
   }
   return 0;
}
