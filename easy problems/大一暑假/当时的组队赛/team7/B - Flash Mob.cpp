#include<cstdio>
#include<cmath>

using namespace std;

int main ()
{
    int N;
    for(int j = 1; ; j ++)
    {
        scanf("%d", &N);
        if(N == 0)
            break;
        int a, b, x = 0, y = 0;
        for(int i = 0; i < N; i ++)
        {
            scanf("%d%d", &a, &b);
            x += a;
            y += b;
        }
        int anx, any;
        anx = x / N;
        any = y / N;
        if(x - anx * N > (anx + 1) * N - x)
            anx ++;
        if(y - any * N > (any + 1) * N - y)
            any ++;
        printf("Case %d: (%d,%d) %d\n", j, anx, any, abs(x - anx * N) + abs(y - anx * N));
    }
}
