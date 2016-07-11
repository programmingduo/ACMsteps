#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

int N, M, ans, n3[25], sc[25];

void solve(int floor, int v, int s, int r, int h)    //floor ´ÓM¿ªÊ¼
{
    //printf("floor = %d v = %d\n", floor, v);
    v -= r * r * h;
    s += 2 * r * h;
    if(v < n3[floor - 1] || s + sc[floor] >= ans || s + v * 2 / r >= ans)
        return ;
    if(floor == 1)
    {
        if(v == 0)
            ans = min(s, ans);
        return ;
    }

    for(int i = r - 1; i >= floor - 1; i --)
    {
        for(int j = h - 1; j >= floor - 1; j --)
        {
            solve(floor - 1, v, s, i, j);
        }
    }
}

int main ()
{
    n3[0] = 0;
    sc[0] = 0;
    for(int i = 1; i < 23; i ++)
    {
        n3[i] = n3[i - 1] + i * i * i;
        sc[i] = sc[i - 1] + 2 * i * i;
    }
    while(~scanf("%d%d", &N, &M))
    {
        ans = 1 << 30;
        for(int i = sqrt(1.0 * N); i >= M - 1; i --)
        {
            for(int j = N; j >= M - 1; j --)
                solve(M, N, i * i, i, j);
        }
    if(ans == 1 << 30)
        printf("0\n");
    else
        printf("%d\n", ans);
    }
    return 0;
}
