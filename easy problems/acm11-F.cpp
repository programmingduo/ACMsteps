#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;

int num[10000];

int main ()
{
    int n, maxn, ans,a;
    while(~scanf("%d", &n))
    {
        maxn = ans = 0;
        memset(num, 0, sizeof(num));
        for(int i = 0; i < n; i ++)
        {
            scanf("%d", &a);
            maxn = max(maxn, a);
            num[a] ++;
        }
        for(int i = 0; i <= maxn; i ++)
        {
            ans = max(ans, num[i]);
        }
        if(ans + ans - 1 > n)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
