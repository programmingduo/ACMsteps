#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 500000
int t,n;
long long sum[maxn];
int tmp;
struct SS
{
    long long int val;
    int id;
}a[maxn*2];//单调队列
long long nn[maxn*2];
int main()
{
    int i;
    int cc,ans;
    int front,rear;
    int st,ed;
    long long kk,ss;
    while (scanf("%d",&t)!=EOF)
    {
        cc = 1;
        while (t--)
        {
            ans = 0;
            memset(sum,0,sizeof(sum));
            scanf("%d",&n);
            for (i=1;i<=n;i++)
            {
                scanf("%d",&tmp);
                sum[i] = sum[i-1]+(long long)tmp;
            }
            ss = sum[n];
            front = rear = 1;
            st = 1;
            ed = n;
            for (i=1;i<=n;i++)
            {
                nn[i] = sum[i];
                kk = sum[i];
                while (rear > front)
                {
                    if (a[rear - 1].val>kk)
                        rear--;
                    else
                        break;
                }
                a[rear].val = kk;
                a[rear].id = i;
                rear++;
            }
            if (a[1].val > 0)
                ans++;

            for (i=1;i<n;i++)
            {
                kk = sum[i] + ss;
                while (rear > front)
                {
                    if (a[rear - 1].val > kk)
                        rear--;
                    else
                        break;
                }
                a[rear].val = kk;
                a[rear].id = n+i;
                rear++;
                st++;
                if (a[front].id < st)
                {
                    front++;
                }
                if (a[front].val > sum[i])
                {
                    ans++;
                }
            }
            printf("Case %d: %d\n",cc++,ans);
        }
    }
    return 0;
}
