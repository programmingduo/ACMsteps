/*
��ĿҪ��brent�������еĳ��У������ҵ������������С����
�������г��У����Ľṹ���������еĽ�㣬����û���ظ��ıߣ���������ֻҪ�������ı�
ȨֵԽСԽ�ã����Ծ�����С����������������Ҫ��ﵽ���еĳ��У���������Ҫ��������
����߼��ɣ�Ҳ���ǿ�³˹�����㷨�м�������һ���� 
��С������
�ⷨ:��³˹���� + ���鼯
ע��:��Ŀ��˵��ÿ�������֮�����ֻ��һ����
		���û��˵��Ҫÿ�θ��±ߵĻ������֮����Сֵ
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 202
#define maxm 20005
int caseT,N,m;
struct Edge
{
	int u,v,w;
}edge[maxm];
bool cmp(Edge e1,Edge e2)
{
	return e1.w < e2.w;
}
//********************************
//���鼯���� 
int fa[maxn];
int find(int k)
{
	if(fa[k] == k)
		return k;
	else
		return fa[k] = find(fa[k]);
}
//********************************
int main()
{
	int i,cnt,ans;
	int father1,father2;
	while(scanf("%d",&caseT)!=EOF)
	{
		while(caseT--)
		{
			scanf("%d%d",&N,&m);
			for(i=0;i<m;i++)
			{
				scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
			}
			//���鼯��ʼ������
			for(i=1;i<=N;i++)
				fa[i] = i;
			cnt  = 0;
			sort(edge,edge+m,cmp);
			for(i=0;i<m;i++)
			{
				//���������������ǲ�����һ�������� 
				father1 = find(edge[i].u);
				father2 = find(edge[i].v);
				if(father1!=father2)
				{
					fa[father1] = father2;
					cnt++;
				}
				if(cnt == N - 1)
				{
					ans = edge[i].w;
					break;
				}
			}
			if(cnt!=N-1)
				printf("-1\n");
			else if(ans%10!=0)
				printf("%d\n",ans/10+1);
			else
				printf("%d\n",ans/10);
		}
	}
	return 0;
}
