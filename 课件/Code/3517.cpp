/*
这道题求的是树的最长距离
结论:从树的任意一个结点作为原点进行广度优先搜索，在结果中找到这次遍历中距离原点最远的点v，
再以v为原点进行广度优先搜索，此时从原点到其最远点的距离就是树的直径（即树的最长距离）
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define maxn 2002
int caseT;
int N;
vector<int>mp[maxn];//存储结点之间的连接状况 
int gp[maxn][maxn];//存储两点之间的距离 
int dist[maxn];
int a,b,c;
int que[maxn];//用于存储bfs信息的队列
int flag[maxn];//标记数组

void bfs(int k)
{
	int i,tmp;
	dist[k] = 0;
	int front,rear;
	front = 0;
	rear = 1;
	//将bfs其实的点加入到队列中 
	que[front] = k;
	memset(flag,0,sizeof(flag));
	flag[k] = 1;
	while(front < rear)
	{
		//取出队列中的点进行广度优先搜索
		tmp = que[front];
		//枚举与当前取出点所有临近的点 
		for( i = 0; i<mp[tmp].size();i++)
		{ 
			//如果当前点没有被标记 
			if(flag[mp[tmp][i]] == 0)
			{
				que[rear++] = mp[tmp][i];//将邻近点加入到队列中 
				dist[mp[tmp][i]] = dist[tmp] + gp[mp[tmp][i]][tmp];
				//更新临近点信息 
				flag[mp[tmp][i]] = 1;//标记新扩展出来的临近点 
			}
		}
		//队列头指针前移 
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
			//构建图
			for(i = 1;i < N;i++)
			{
				scanf("%d%d%d",&a,&b,&c);
				mp[a].push_back(b);
				mp[b].push_back(a);
				gp[a][b] = gp[b][a] = c;
			}
			//第一次进行bfs，从结点1开始 
			bfs(1);
			//找距离原点1最远点的点
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
			//第二次bfs
			bfs(k);
			//找距离原点k最远的点
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
