/*
�����Ŀ��Ҫ����Ƕ���ÿ����ki���ͳ��䵽���е��е������Li 
���ѡȡ��С��Li�����ki��Li
��Ŀע��������û�а취���ӵ����нڵ㣬��� disjoint
��Ŀ�����д���ͼ��Ϊ�����
������Ŀ����֪������Ҫ֪��ÿ���㵽���е����̾���
����Dijkstra�Ͳ�̫�����ˣ�ѡ��floyd�㷨���ܹ������
ÿ���㵽���е����С���룬������С��100�� 1s���ܼ�����
�������ú�dist[i][j]����ʾ���i��j�ľ��룩
����floyd()��dist[i][j] �ͱ�ʾ���i��j����̾���
int dist[maxn][maxn];
void floyd()
{
	int i,j,k;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(dist[i][j]>dist[i][k]+dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	return;
} 
*/ 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define maxn 102
int n;
//////////////////ģ�岿��///////////////////////////////// 
int dist[maxn][maxn];
void floyd()
{
	int i,j,k;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(dist[i][j]>dist[i][k]+dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	return;
}
//////////////////ģ�岿��/////////////////////////////////
int main()
{
	int m,u,len;
	while(scanf("%d",&n)&&n)
	{
		int i,j;
		memset(dist,0x3f,sizeof(dist));
		//������ĿҪ������ͼ�бߵ���Ϣ 
		for(i=1;i<=n;i++)
		{
			dist[i][i] = 0;
			scanf("%d",&m);
			while(m--)
			{
				scanf("%d%d",&u,&len);
				dist[i][u] = len; 
			}
		}
	    floyd();
	    int ans,sum,tmp,flag;
	    sum = 0x7f7f7f7f;
	    ans = -1;
	    for(i=1;i<=n;i++)
		{
			flag = 0;
			tmp = -1;
			for(j=1;j<=n;j++)
			{
				if(dist[i][j]==0x3f3f3f3f)
				{
					flag = -1;
					break;
				}
				else
					tmp = max(dist[i][j],tmp);
			}
			if(flag==0)
			{
				if(tmp<sum)
				{
				    ans = i;
				    sum = tmp;
				}
			}
		}
		if(ans == -1)
			printf("disjoint\n");
		else
			printf("%d %d\n",ans,sum); 
	}
	return 0;
}
