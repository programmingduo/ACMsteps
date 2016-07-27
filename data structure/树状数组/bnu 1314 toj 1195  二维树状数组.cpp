#include<cstdio>
#include<string.h>

int x[1025][1025], board;

int lowbit(int i)
{
    return i & (-i);
}

void add(int a, int b, int c)
{
    for(int i = a; i <= board; i += lowbit(i))
        for(int j = b; j <= board; j += lowbit(j))
        x[i][j] += c;
}

int sum(int a, int b)
{
    int s = 0;
    for(int i = a; i > 0; i -= lowbit(i))
        for(int j = b; j > 0; j -= lowbit(j))
        s += x[i][j];
    return s;
}

int getsum(int a, int b, int c, int d)
{
    return (sum(c, d) + sum(a - 1, b - 1) - sum(c, b - 1) - sum(a - 1, d));
}

int main ()
{
    int state, a, b, c, d;
    while(~scanf("%d", &state))
    {
        if(state == 0)
        {
            scanf("%d", &board);
            memset(x, 0, sizeof(x));
        }
        else if (state == 1)
        {
            scanf("%d%d%d", &a, &b, &c);
            a ++, b ++;
            add(a, b, c);
        }
        else if(state == 2)
        {
            scanf("%d%d%d%d", &a, &b, &c, &d);
            a ++, b ++, c ++, d ++;
            printf("%d\n", getsum(a, b, c, d));
        }
        else if(state == 3)
        {
            continue;
        }
    }
}
