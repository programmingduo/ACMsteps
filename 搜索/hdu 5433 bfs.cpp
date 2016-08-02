#include<cstdio>
#include<string.h>
#include<queue>
#include<cmath>
using namespace std;

int n,m,k;
int a,b,c,d;
double minx;
char ch[55];
int mat[55][55];
double vis[55][55][55];//vis[i][j][k]表示在（i，j）这个坐标的时候所剩k斗志的体力值
int dir[4][2]={{0,-1},{0,1},{-1,0},{1,0}};

struct node
{
    int x,y,t;//t为斗志
    double ans;//体力
}s[100005];

void bfs(node st)
{
    queue<node> q;
    node now, next;
    st.t=k;
    st.ans=0.0;
    vis[st.x][st.y][st.t]=0;
    q.push(st);
    while (!q.empty())
    {
        now = q.front();
        if (now.t<=0) return ;
        for (int i=0; i<4; i++)//平常的bfs
        {
            next.x = now.x+dir[i][0];
            next.y = now.y+dir[i][1];
            if (next.x<0||next.x>=n||next.y<0||next.y>=m) continue;
            if (mat[next.x][next.y]==-1) continue;

            next.ans = now.ans+(double)abs(mat[now.x][now.y]-mat[next.x][next.y])/(double)now.t;
            next.t = now.t-1;

            if (vis[next.x][next.y][next.t]-next.ans>0)//当前的得到的体力值比之前得到的体力值小
            {
                vis[next.x][next.y][next.t]=next.ans;//更新
                q.push(next);//入队
            }
        }
        q.pop();
    }
    return ;
}

int main ()
{
    int T;
    scanf ("%d",&T);
    while (T--)
    {
        scanf ("%d%d%d",&n,&m,&k);
        for (int i=0; i<n; i++)
        {
            scanf ("%s",ch);
            for (int j=0; j<m; j++)
            {
                if (ch[j] == '#')
                    mat[i][j] = -1;
                else
                    mat[i][j] = ch[j]-'0';
            }
        }
        scanf ("%d%d",&a,&b);
        scanf ("%d%d",&c,&d);
        if(k<=0)
        {
            printf("No Answer\n");
            continue;
        }
        a--,b--,c--,d--;
        node st;
        st.x=a;st.y=b;
        //CL(vis);
        for (int i=0; i<=n; i++)//初始化
            for (int j=0; j<=m; j++)
                for (int r=0; r<=k; r++)
                    vis[i][j][r]=10000000000.0;
        bfs(st);
        minx=vis[c][d][1];
        for (int i=1; i<=k; i++)//最后扫一遍，得到最小体力
            minx=min(minx, vis[c][d][i]);
        if (minx-10000000000.0<0)
            printf ("%.2lf\n",minx);
        else
            printf ("No Answer\n");
    }
    return 0;
}
