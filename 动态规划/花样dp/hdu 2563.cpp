#include<cstdio>
#include<queue>
#include<string.h>

using namespace std;

int ans[30],a[30],b[30];

void dp()
{
    memset(ans, 0, sizeof(ans));
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    a[1] = 1;
    b[1] = 2;
    ans[1] = 3;
    for(int i = 2; i < 22; i ++)
    {
        b[i] = 2 * a[i - 1] + b[i - 1];
        a[i] = a[i - 1] + b[i - 1];
        ans[i] = a[i] + b[i];
    }
}

int main()
{
    int T, N;
    scanf("%d", &T);
    dp();
    while(T --)
    {
        scanf("%d", &N);
        printf("%d\n", ans[N]);
    }
}
