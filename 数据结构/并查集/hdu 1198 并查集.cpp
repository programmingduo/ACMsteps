#include<cstdio>

int fa[100][100];
char map[100][100];
int a, b;

int x(int n)
{
    return n / 100;
}
int y(int n)
{
    return n % 100;
}
int n(int x, int y)
{
    return x * 100 + y;
}

int find(int x1, int y1)
{
    if(fa[x1][y1] == n(x1, y1))
        return n(x1, y1);
    return fa[x1][y1] = find(x(fa[x1][y1]), y(fa[x1][y1]));
}

int in(int x1, int y1)
{
    if(x1 >= 0 && x1 < a && y1 >= 0 && y1 < b)
        return 1;
    return 0;
}

void merge(int x1, int y1, int x2, int y2)
{
    int fa1 = find(x1, y1);
    int fa2 = find(x2, y2);
    if(fa1 == fa2)
        return ;
    fa[x(fa1)][y(fa1)] = fa2;
}

int main ()
{
    while(~scanf("%d%d", &a, &b))
    {
        if(a == -1 && b == -1)
            break;
        for(int i = 0; i < a; i ++)
            scanf("%s", map[i]);
        for(int i = 0; i < a; i ++)
            for(int j = 0; j < b; j ++)
            fa[i][j] = n(i, j);
        for(int i = 0; i < a; i ++)
        {
            for(int j = 0; j < b; j ++)
            {
                if(in(i, j - 1) && (map[i][j] == 'A' || map[i][j] == 'C' || map[i][j] == 'F' || map[i][j] == 'G'
                   || map[i][j] == 'H' || map[i][j] == 'I' || map[i][j] == 'K') &&
                   (map[i][j - 1] == 'B' || map[i][j - 1] == 'D' || map[i][j - 1] == 'F' || map[i][j - 1] == 'G'
                   || map[i][j - 1] == 'I' || map[i][j - 1] == 'J' || map[i][j - 1] == 'K'))
                    merge(i, j, i, j - 1);
                if(in(i - 1, j) && (map[i][j] == 'A' || map[i][j] == 'B' || map[i][j] == 'E' || map[i][j] == 'G'
                   || map[i][j] == 'H' || map[i][j] == 'J' || map[i][j] == 'K') &&
                   (map[i - 1][j] == 'C' || map[i - 1][j] == 'D' || map[i - 1][j] == 'E' || map[i - 1][j] == 'H'
                   || map[i - 1][j] == 'I' || map[i - 1][j] == 'J' || map[i - 1][j] == 'K'))
                    merge(i, j, i - 1, j);
            }
        }
        int ans = 0;
        for(int i = 0; i < a; i ++)
            for(int j = 0; j < b; j ++)
        {
            if(fa[i][j] == n(i, j))
                ans ++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
