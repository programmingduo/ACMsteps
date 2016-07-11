#include<cstdio>

using namespace std;

int x[1000000], y[1000000];


int main ()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i ++)
    {
        int ans = 0;
        int E, W, roads;
        scanf("%d%d%d", &E, &W, &roads);
        for(int j = 0; j < roads; j ++)
        {
            scanf("%d%d", &x[j], &y[j]);
            for(int k = 0; k < j; k ++)
                if((x[k] - x[j]) * (y[k] - y[j]) < 0)
                ans ++;
        }
        printf("Test case %d: %d", i + 1, ans);
    }
}
