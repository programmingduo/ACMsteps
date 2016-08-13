#include<cstdio>
#include<string.h>

char s[50][50];
int n[50][50], m[500][500], link[500], use[500], vis[500], t[50][50];
int total;

void add_edge(int temp1, int temp2)
{
    m[temp1][temp2] = 1;
    m[temp2][temp1] = 1;
}

bool dfs(int index)
{
    for(int i = 1; i < total; i ++)
    {
        if(m[index][i] && vis[i] == 0)
        {
            vis[i] = 1;
            if(link[i] == 0 || dfs(link[i]))
            {
                link[i] = index;
                use[index] = 1;
                return 1;
            }
        }
    }
    return 0;
}

int search()
{
    memset(link, 0, sizeof(link));
    memset(use, 0, sizeof(use));
    int m = 0;
    for(int i = 1; i < total; i ++)
    {
        memset(vis, 0, sizeof(vis));
        if(dfs(i))
            m ++;
    }
    return m;
}

int main ()
{
    int T, r, c;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d %d", &r, &c);
        for(int i = 0; i < r; i ++)
        {
            scanf("%s", s[i]);
        }

        total = 1;
        memset(n, 0, sizeof(n));
        memset(m, 0, sizeof(m));
        for(int i = 0; i < r; i ++)
        {
            for(int j = 0; j < c; j ++)
            {
                if(s[i][j] == '*')
                    n[i][j] = total ++;
            }
        }

        for(int i = 0; i < r; i ++)
        {
            for(int j = 0; j < c; j ++)
            {
                int temp1 = 0, temp2 = n[i][j];
                if(!temp2)
                    continue;
                if(i + 1 < r && n[i + 1][j])
                {
                    temp1 = n[i + 1][j];
                    add_edge(temp1, temp2);
                }
                if(j + 1 < c && n[i][j + 1])
                {
                    temp1 = n[i][j + 1];
                    add_edge(temp1, temp2);
                }
            }
        }
        printf("%d\n", total - search() / 2 - 1);

    }
    return 0;
}
