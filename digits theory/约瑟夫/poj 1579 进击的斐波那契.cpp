#include<cstdio>
#include<string.h>
int w[25][25][25];
int vis[26][26][26];

int compute(int a, int b, int c)
{
    if(a <= 0 || b <= 0 || c <= 0)
        return 1;
    if(a > 20 || b > 20 || c > 20)
        return compute(20, 20, 20);
    if(vis[a][b][c])
        return w[a][b][c];
    vis[a][b][c] = 1;
    if(a < b && b < c)
        return w[a][b][c] = compute(a, b, c - 1) + compute(a, b - 1, c - 1) - compute(a, b - 1, c);
    else
        return w[a][b][c] = compute(a - 1, b, c) + compute(a - 1, b - 1, c) + compute(a - 1, b, c - 1) - compute(a - 1, b - 1, c - 1);
}

int main ()
{
    int a, b, c;
    memset(w, 0, sizeof(0));
    memset(vis, 0, sizeof(0));
    compute(20, 20, 20);
    while(~scanf("%d%d%d", &a, &b, &c))
    {
        if(a == -1 && b == -1 && c == -1)
            break;
        printf("w(%d, %d, %d) = %d\n", a, b, c, compute(a, b, c));
    }
    return 0;
}
