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
         if (dfn[v] == -1)//dfn��ʼ����Ϊ-1��
         {
                    dfs(v);
                    low[k] = min(low[k],low[v]);
                    if (k �㲻�Ǹ� && low[v] >= dfn[k])
                        mark[k] = 1;
                    else if (k �Ǹ� && dfn[v] > 2) mark[1] = 1;//dfn[v]>2˵��k��������������
                    if (low[v] > dfn[k]) (k,v)Ϊ���
         }
         else low[k] = min(low[k], dfn[v]);
     }
     return;
}


int main ()
{

}
