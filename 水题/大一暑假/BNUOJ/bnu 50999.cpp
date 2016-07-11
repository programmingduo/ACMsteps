#include<cstdio>
#include<algorithm>
using namespace std;

struct one
{
    int a, b;
}work[1005];

int cmp(one fi, one se)
{
    return fi.a < se.a;
}

int main ()
{
    int T, num;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d", &num);
        for(int i = 0; i < num; i ++)
        {
            scanf("%d%d", &(work[i].a), &(work[i].b));
        }
        sort(work, work + num, cmp);
        int ans = 0;
        for(int i = 0; i < num; i ++)
        {
            if(ans > work[i].a)
                ans += work[i].b;
            else
                ans = work[i].a + work[i].b;
        }
        printf("%d\n", ans);
    }
    return 0;
}
