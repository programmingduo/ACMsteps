#include <iostream>
#include <cstring>
using namespace std;
#define maxn 102
int mp[maxn][maxn];
int flag[maxn][maxn];
int caseT;
int r,c;
int rr,cc;
/* 
bfs搜索过程中方向偏移数组，
for(i=0;i<4;i++)
{
	u = que[front].x + dir[i][0];
	v = que[front].y + dir[i][1];
	if(check(u,v)&&flag[u][v]==0&&mp[u][v]==0)
	{
		fa[rear] = front;
		que[rear].x = u;
		que[rear].y = v;
		rear++;
		flag[u][v] = 1;
		if(u ==  1 || u == r || v == 1 || v == c)
			return;
	}
}
在这一步比较方便的枚举出了四个方向，这个技巧比较好 
*/
int dir[4][2] = {{1,0},{0,1},{0,-1},{-1,0}};
struct Point
{
	int x,y;
}que[maxn*maxn],ans[maxn*maxn];
int fa[maxn*maxn];//用于标记当前结点之前的结点，这样我们就可以输出bfs的整个路径了 
int ans_tp;
//判断当前点是否在界内 
bool check(int xx,int yy)
{
	if(xx>=1&&xx<=r&&yy>=1&&yy<=c)
		return true;
	else
		return false;
}
int front,rear;
void bfs(int xx,int yy)
{
	memset(fa,-1,sizeof(fa));
	memset(flag,0,sizeof(flag));
	int i,u,v;
	front = 0; rear = 1;
	que[front].x = xx;
	que[front].y = yy;
	flag[xx][yy] = 1;
	//如果起始点本来就在边界上，那么退出 
	if(xx ==  1 || xx == r || yy == 1 || yy == c)
		return;
	while(front < rear)
	{
		for(i=0;i<4;i++)
		{
			u = que[front].x + dir[i][0];
			v = que[front].y + dir[i][1];
			if(check(u,v)&&flag[u][v]==0&&mp[u][v]==0)
			{//界内尚未标记的不是围墙的点 
				fa[rear] = front;
				que[rear].x = u;
				que[rear].y = v;
				rear++;
				flag[u][v] = 1;
				if(u ==  1 || u == r || v == 1 || v == c)
					return;
			}
		}
		front++;
	}
	return;
}
int main()
{
	int i,j,tmp,tt;
	while(scanf("%d",&caseT)!=EOF)
	{
		while(caseT--)
		{
			scanf("%d%d",&r,&c);
			for(i=1;i<=r;i++)
			{
				for(j=1;j<=c;j++)
				{
					scanf("%d",&mp[i][j]);
				}
			}
			scanf("%d%d",&rr,&cc);
			bfs(rr,cc);
			ans_tp = 0;
			tmp = rear - 1;
			//查询bfs路径 
			while(tmp != -1)
			{
				ans[ans_tp].x = que[tmp].x;
				ans[ans_tp].y = que[tmp].y;
				ans_tp++;
				tmp = fa[tmp];	
			}
			for(i=ans_tp-1;i>0;i--)
			{
				if(ans[i].x == ans[i-1].x)
				{
					if(ans[i].y > ans[i-1].y)
					{
						printf("L ");
					}
					else
					{
						printf("R ");
					}
				}
				else
				{
					if(ans[i].x > ans[i-1].x)
					{
						printf("U ");
					}
					else
					{
						printf("D ");
					}
				}
			}
			//对于最后一个点的处理，看其所处的边界信息 
			if(ans[0].x == r)
			{
				printf("D\n");
			}
			else if(ans[0].x == 0)
			{
				printf("U\n");
			}
			else if(ans[0].y == 0)
			{
				printf("L\n");
			}
			else
			{
				printf("R\n");
			}
		}
	}
	return 0;
}
