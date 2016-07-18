#include<cstdio>

char m[1005][1005];
int girl, cat, r, c;
int dirx[] = {1, -1, 0, 0};
int diry[] = {0, 0, 1, -1};

bool in(int a, int b)
{
    if(a < 0 || a >= r || b < 0 || b >= c)
        return false;
    return true;
}

void dfs(int a, int b, char t)
{
    if(!in(a, b) || m[a][b] != t)
        return ;
    if(t == 'g')
    {
        for(int i = 0; i < 4; i ++)
        {
            dfs(a + dirx[i], b + diry[i], 'i');
        }
    }
    if(t == 'i')
    {
        for(int i = 0; i < 4; i ++)
        {
            dfs(a + dirx[i], b + diry[i], 'r');
        }
    }
    if(t == 'r')
    {
        for(int i = 0; i < 4; i ++)
        {
            dfs(a + dirx[i], b + diry[i], 'l');
        }
    }
    if(t == 'l')
    {
        girl ++;
    }

    if(t == 'c')
    {
        for(int i = 0; i < 4; i ++)
        {
            dfs(a + dirx[i], b + diry[i], 'a');
        }
    }
    if(t == 'a')
    {
        for(int i = 0; i < 4; i ++)
        {
            dfs(a + dirx[i], b + diry[i], 't');
        }
    }
    if(t == 't')
    {
        cat ++;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        girl = cat = 0;
        scanf("%d%d", &r, &c);
        for(int i = 0; i < r; i ++)
            scanf("%s", m[i]);
        for(int i = 0; i < r; i ++)
            for(int j = 0; j < c; j ++)
            {
                dfs(i, j, 'g');
                dfs(i, j, 'c');
            }
        printf("%d %d\n", girl, cat);
    }
    return 0;
}
