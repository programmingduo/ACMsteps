#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define MAX 502

int dist[MAX], flag[MAX], cnt[MAX];
int que[MAX], front, rear;     //使用循环队列,可以节省内存

struct Node
{
   int id, d;
   Node(){}
   Node(int _id, int _d):
      id(_id), d(_d){} 
};

vector <Node> mp[MAX];        //vector模拟邻接链表 

int SPFA(int n, int s)              //s为起点 
{
   int i, u, v;
   memset(flag, 0, sizeof(flag));     //flag[]为0说明不在队列中，1则相反 
   memset(dist, 0x1f, sizeof(dist));
   memset(cnt, 0, sizeof(cnt));
   dist[s] = 0;
   flag[s] = 1;
   front = rear = 0;
   que[rear++] = s;
   while (front != rear)             //若队列非空 
   {
      u = que[front++];             //取队首元素 u
      cnt[u]++;
      if (cnt[u] >= n)              //若一个点，入队n次则存在负环 
         return -1;
      flag[u] = 0;
      if (front >= MAX)          
         front = 0;
      for (i = 0; i < mp[u].size(); ++i)
      {
         v = mp[u][i].id;               //对于u相邻的点v，进行松弛操作 
         if (dist[u] + mp[u][i].d < dist[v])  
         {
            dist[v] = dist[u] + mp[u][i].d;
            if (flag[v] == 0)          //若v不在队列中，加入队列 
            {
               que[rear++] = v;
               flag[v] = 1;            //入队标记 
               if (rear >= MAX)
                  rear = 0;
            }
         }
      }
   }
   return 1;
}

int main()
{
   int a, b, c, i, n, m, w, cas;
   scanf("%d", &cas);
   while (cas--)
   {
      scanf("%d%d%d", &n, &m, &w);
      for (i = 1; i <= n; ++i)            
         mp[i].clear();
      for (i = 0; i < m; ++i)
      {
         scanf("%d%d%d", &a, &b, &c);
         mp[a].push_back(Node(b, c));     
         mp[b].push_back(Node(a, c));
      }
      for (i = 0; i < w; ++i)
      {
         scanf("%d%d%d", &a, &b, &c);
         mp[a].push_back(Node(b, -c));
      }
      if (SPFA(n, 1) == -1)
         printf("YES\n");
      else
         printf("NO\n");
   }   
   return 0;
}







