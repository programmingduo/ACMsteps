#include<cstdio>

using namespace std;
int ans[10000005];
int main ()
{
    ans[1] = 0;
    for(int i = 1; i <= 5000000; i ++)
    {
        ans[2 * i] = ans[i] * 2;
        ans[2 * i + 1] = ans[i] + ans[i + 1] + 1;
    }
    int cases, total;
    scanf("%d", &cases);
    while(cases --)
    {
        scanf("%d", &total);
        printf("%d\n", ans[total]);
    }
    return 0;
}
