#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define MAX 502

int dist[MAX], flag[MAX], cnt[MAX];
int que[MAX], front, rear;     //ʹ��ѭ������,���Խ�ʡ�ڴ�

struct Node
{
   int id, d;
   Node(){}
   Node(int _id, int _d):
      id(_id), d(_d){} 
};

vector <Node> mp[MAX];        //vectorģ���ڽ����� 

int SPFA(int n, int s)              //sΪ��� 
{
   int i, u, v;
   memset(flag, 0, sizeof(flag));     //flag[]Ϊ0˵�����ڶ����У�1���෴ 
   memset(dist, 0x1f, sizeof(dist));
   memset(cnt, 0, sizeof(cnt));
   dist[s] = 0;
   flag[s] = 1;
   front = rear = 0;
   que[rear++] = s;
   while (front != rear)             //�����зǿ� 
   {
      u = que[front++];             //ȡ����Ԫ�� u
      cnt[u]++;
      if (cnt[u] >= n)              //��һ���㣬���n������ڸ��� 
         return -1;
      flag[u] = 0;
      if (front >= MAX)          
         front = 0;
      for (i = 0; i < mp[u].size(); ++i)
      {
         v = mp[u][i].id;               //����u���ڵĵ�v�������ɳڲ��� 
         if (dist[u] + mp[u][i].d < dist[v])  
         {
            dist[v] = dist[u] + mp[u][i].d;
            if (flag[v] == 0)          //��v���ڶ����У�������� 
            {
               que[rear++] = v;
               flag[v] = 1;            //��ӱ�� 
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







