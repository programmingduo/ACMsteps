#include<cstdio>
#include<string.h>

int g[107][107], msp[1007][1007], msw[1007][1007], mpw[1005][1005], used[1005], linker[1004];
int uN, vN;

bool dfs(int u)
{
    for(int v=0; v<vN; v++){
        if(g[u][v]&&!used[v]){
            used[v]=true;
            if(linker[v]==-1||dfs(linker[v])){
                linker[v]=u;
                return true;
            }
        }
    }
    return false;
}

int hungary()
{
    int res=0, u;
    memset(linker, -1, sizeof(linker));
    for(u=0; u<uN; u++){
        memset(used, 0, sizeof(used));
        if(dfs(u))res++;
    }
    return res;
}

int main ()
{
    int T, ns, np, nw;
    scanf("%d", &T);
    while(T --)
    {
        int to;
        scanf("%d %d %d", &ns, &np, &nw);
        memset(msp, 0, sizeof(msp));
        memset(msw, 0, sizeof(msw));
        memset(mpw, 0, sizeof(mpw));
        for(int i = 1; i <= ns; i ++)
        {
            int temp;
            scanf("%d", &temp);
            while(temp --)
            {
                scanf("%d", &to);
                msp[i][to] = 1;
            }
        }
        for(int i = 1; i <= ns; i ++)
        {
            int temp;
            scanf("%d", &temp);
            while(temp --)
            {
                scanf("%d", &to);
                msw[i][to] = 1;
            }
        }

        for(int i = 1; i <= np; i ++)
        {
            int temp;
            scanf("%d", &temp);
            while(temp --)
            {
                scanf("%d", &to);
                mpw[i][to] = 1;
            }
        }


        memset(g, 0, sizeof(g));
        for(int i = 1; i <= np; i ++)
        {
            for(int j = 1; j <= ns; j ++)
            {
                if(msp[j][i])
                {
                    for(int k = 1; k <= nw; k ++)
                    {
                        if(msw[j][k] && mpw[i][k])
                        {
                            g[i - 1][j - 1] = 1;
                        }
                    }
                }
            }
        }
        uN = np, vN = ns;
        printf("%d\n", hungary());
    }
    return 0;

}
