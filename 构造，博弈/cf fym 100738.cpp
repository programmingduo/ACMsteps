#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;

struct node
{
    int x, ind;
}a[500000];

int cmp(node n, node m)
{
    return n.x>m.x? 1: 0;
}

int b[5000000];

queue<int > q;

int main ()
{
    int n;
    while(~scanf("%d", &n))
    {
        long long total = 2;
        for(int i = 0; i < n; i ++)
        {
            scanf("%d", &a[i].x);
            a[i].ind = i + 1;
            total += a[i].x - 2;
        }
        if(total != 0)
        {
            printf("-1\n");
            continue;
        }
        std::sort(a, a + n, cmp);
//        for(int i =0; i < n; i ++)
//            printf("%d ", a[i].x);
        for(int i = 0; i < n; i ++)
            b[i] = a[n - i].x;
        while(!q.empty())
            q.pop();

        total = 1;
        for(int i = 0; i < n; i ++)
        {
            if(a[i].x == 1)
            break;
            if(i)
            {
                int t = a[i].x - 2;
                while(t --)
                {
                    printf("%d %d\n", a[i].ind, a[n - total].ind);
                    total ++;
                }
                printf("%d %d\n", a[i].ind, a[i + 1].ind);
            }
            else
            {
                int t = a[i].x - 1;
                while(t --)
                {
                    printf("%d %d\n", a[i].ind, a[n - total].ind);
                    total ++;

                }
                printf("%d %d\n", a[i].ind, a[i + 1].ind);
            }
        }
    }
}
