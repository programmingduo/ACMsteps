#include<cstdio>

const int N = 100005;
int n, m, f[N], rank[N];    // n是节点个数

inline void init()
{
    for(int i = 1; i <= n; i ++)
        f[i] = i, rank[i] = 0;     //逗号也是一种运算符
}

int find(int x)
{
    if(x == f[x])
        return f[x];
    int fa = f[x];
    f[x] = find(f[x]);
    rank[x] = (rank[x]+rank[fa]) & 1;  //按位与，还真是对的诶

    return f[x];
}

inline bool Union(int x,int y)
{
    int a = find(x), b = find(y);
    if(a == b) return false;
    f[b] = a;
    rank[b] = (rank[x] - rank[y] + 1) & 1;
}

int main()
{
    int T,a,b,fa,fb;
    char ch;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%*c",&n,&m);
        init();
        for(int i=0; i<m; ++i)
        {
            scanf("%c%d%d%*c",&ch,&a,&b);
            if(ch=='D')
            {
                Union(a,b);
            }
            else
            {
                fa = find(a), fb = find(b);
                if(fa == fb)
                {
                    if(rank[a] == rank[b])
                        puts("In the same gang.");
                    else
                        puts("In different gangs.");
                }
                else
                    puts("Not sure yet.");
            }
        }
    }
    return 0;
}
