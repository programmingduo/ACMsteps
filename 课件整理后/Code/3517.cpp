/*
�������������������
����:����������һ�������Ϊԭ����й�������������ڽ�����ҵ���α����о���ԭ����Զ�ĵ�v��
����vΪԭ����й��������������ʱ��ԭ�㵽����Զ��ľ����������ֱ��������������룩
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define maxn 2002
int caseT;
int N;
vector<int>mp[maxn];//�洢���֮�������״�� 
int gp[maxn][maxn];//�洢����֮��ľ��� 
int dist[maxn];
int a,b,c;
int que[maxn];//���ڴ洢bfs��Ϣ�Ķ���
int flag[maxn];//�������

void bfs(int k)
{
	int i,tmp;
	dist[k] = 0;
	int front,rear;
	front = 0;
	rear = 1;
	//��bfs��ʵ�ĵ���뵽������ 
	que[front] = k;
	memset(flag,0,sizeof(flag));
	flag[k] = 1;
	while(front < rear)
	{
		//ȡ�������еĵ���й����������
		tmp = que[front];
		//ö���뵱ǰȡ���������ٽ��ĵ� 
		for( i = 0; i<mp[tmp].size();i++)
		{ 
			//�����ǰ��û�б���� 
			if(flag[mp[tmp][i]] == 0)
			{
				que[rear++] = mp[tmp][i];//���ڽ�����뵽������ 
				dist[mp[tmp][i]] = dist[tmp] + gp[mp[tmp][i]][tmp];
				//�����ٽ�����Ϣ 
				flag[mp[tmp][i]] = 1;//�������չ�������ٽ��� 
			}
		}
		//����ͷָ��ǰ�� 
		front++;
	}
	return;
}
int main()
{
	int i,k,tmp_Max;
	while(scanf("%d",&caseT)!=EOF)
	{
		while(caseT--)
		{
			scanf("%d",&N);
			for(i = 1;i<=N;i++)
			{
				mp[i].clear();
			}
			//����ͼ
			for(i = 1;i < N;i++)
			{
				scanf("%d%d%d",&a,&b,&c);
				mp[a].push_back(b);
				mp[b].push_back(a);
				gp[a][b] = gp[b][a] = c;
			}
			//��һ�ν���bfs���ӽ��1��ʼ 
			bfs(1);
			//�Ҿ���ԭ��1��Զ��ĵ�
			tmp_Max = dist[1];
			for(i = 2;i <= N;i++)
			{
				if(tmp_Max < dist[i])
				{
					k = i;
					tmp_Max = dist[i];
				}
			}
			//printf("%d\n",tmp_Max);
			//�ڶ���bfs
			bfs(k);
			//�Ҿ���ԭ��k��Զ�ĵ�
			tmp_Max = dist[1];
			for(i=2;i<=N;i++)
			{
				if(tmp_Max < dist[i])
				{
					k = i;
					tmp_Max = dist[i];
				}
			}
			printf("%d\n",tmp_Max);
		}
	}
	return 0;
}
