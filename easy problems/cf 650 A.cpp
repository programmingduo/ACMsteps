#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

struct node
{
    int x, y;
}a[1000006];

int cmp1(node a, node b)
{
    return a.x > b.x;
}

int cmp2(node a, node b)
{
    if(a.y == b.y)
        return a.x > b.x;
    return a.y > b.y;
}


int main ()
{
    int n;
    while(~scanf("%d", &n))
    {
        for(int i = 0; i < n; i ++)
            scanf("%d%d", &a[i].x, &a[i].y);

        sort(a, a + n, cmp1);
        long long last, last1, last2, cnt, total = 0;;

        last = a[0].x;
        cnt = 1;
        for(int i = 1; i < n; i ++)
        {
            if(a[i].x == last)
            {
                cnt ++;
                continue;
            }
            if(cnt != 1)
            {
                total += cnt * (cnt - 1) / 2;
                cnt = 1;
            }
            last = a[i].x;
        }
        total += cnt * (cnt - 1) / 2;
        //printf("%d\n", total);

        sort(a, a + n, cmp2);
        last = a[0].y;
        cnt = 1;
        for(int i = 1; i < n; i ++)
        {
            if(a[i].y == last)
            {
                cnt ++;
                continue;
            }
            if(cnt != 1)
            {
                total += cnt * (cnt - 1) / 2;
                cnt = 1;
            }
            last = a[i].y;
        }
        total += cnt * (cnt - 1) / 2;
        //printf("%d\n", total);

        last1 = a[0].x;
        last2 = a[0].y;
        cnt = 1;
        for(int i = 1; i < n; i ++)
        {
            if(a[i].y == last2 && a[i].x == last1)
            {
                cnt ++;
                continue;
            }
            if(cnt != 1)
            {
                total -= cnt * (cnt - 1) / 2;
                cnt = 1;
            }
            last1 = a[i].x;
            last2 = a[i].y;
        }
        total -= cnt * (cnt - 1) / 2;
        printf("%lld\n", total);
    }
    return 0;
}
