#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;

struct node
{
    int x, y, z;

}block[100];
int dp[100];

bool cmp(node a, node b)
{
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

int main ()
{
    int n, T = 1;
    while(~scanf("%d", &n) && n)
    {
        int a, b, c, temp = 0;
        for(int i = 0; i < n; i ++)
        {
            scanf("%d%d%d", &a, &b, &c);
            block[temp].z = c;
            block[temp].x = max(a, b);
            block[temp ++].y = min(a, b);
            block[temp].z = b;
            block[temp].x = max(a, c);
            block[temp ++].y = min(a, c);
            block[temp].z = a;
            block[temp].x = max(b, c);
            block[temp ++].y = min(b, c);
        }
        sort(block, block + temp, cmp);
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        dp[0] = block[0].z;
        for(int i = 1; i < temp; i ++)
        {
            dp[i] = block[i].z;
            for(int j = i - 1; j >= 0; j --)
            if(block[i].x <= block[j].x || block[i].y <= block[j].y)
                continue;
            else
            dp[i] = max(dp[i], dp[j] + block[i].z);
        }
        for(int i = 0; i < temp; i ++)
            ans = max(ans, dp[i]);
        printf("Case %d: maximum height = %d\n", T ++, ans);
    }
}
