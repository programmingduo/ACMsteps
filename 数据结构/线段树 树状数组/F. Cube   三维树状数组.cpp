#include<cstdio>
#include<cstring>

using namespace std;

int N;
int cube[102][102][102];

int lowbit(int x)
{
    return x & (-x);
}

int sum(int x, int y, int z)
{
    int ans = 0;
    for(int i = x; i > 0; i -= lowbit(i))
        for(int j = y; j > 0; j -= lowbit(j))
            for(int k = z; k > 0; k -= lowbit(k))
            ans += cube[i][j][k];

    return ans & 1;
}

void update(int x, int y, int z)
{
    for(int i = x; i <= N; i += lowbit(i))
        for(int j = y; j <= N; j += lowbit(j))
            for(int k = z; k <= N; k += lowbit(k))
            cube[i][j][k] ++;
}

int main ()
{
    int M;
    while(~scanf("%d%d", &N, &M))
    {
        memset(cube, 0, sizeof(cube));
        for(int i = 0; i < M; i ++)
        {
            int temp;
            scanf("%d", &temp);
            if(temp == 1)     //update
            {
                int x1, x2, y1, y2, z1, z2;
                scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
                update(x1, y1, z1);
                update(x1, y1, z2+1);
                update(x1, y2+1, z1);
                update(x1, y2+1, z2+1);

                update(x2+1, y1, z1);
                update(x2+1, y1, z2+1);
                update(x2+1, y2+1, z1);
                update(x2+1, y2+1, z2+1);
            }

            else if(temp == 0)    //sum
            {
                int x, y, z;
                scanf("%d %d %d", &x, &y, &z);
                int ans = sum(x, y, z);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
