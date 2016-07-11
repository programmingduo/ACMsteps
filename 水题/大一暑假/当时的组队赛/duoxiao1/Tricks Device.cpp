#include<cstdio>
#include<math.h>

using namespace std;

void dfs(int k)
{
     int i, v;
     dfn[k] = low[k] = ++leve;
     for (i = head[k];i != -1;i = edge[i].next)
     {
         v = edge[i].v;
         if (dfn[v] == -1)//dfn初始化都为-1；
         {
                    dfs(v);
                    low[k] = min(low[k],low[v]);
                    if (k 点不是根 && low[v] >= dfn[k])
                        mark[k] = 1;
                    else if (k 是根 && dfn[v] > 2) mark[1] = 1;//dfn[v]>2说明k至少有两个儿子
                    if (low[v] > dfn[k]) (k,v)为割边
         }
         else low[k] = min(low[k], dfn[v]);
     }
     return;
}


int main ()
{

}
