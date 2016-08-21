#include<cstdio>
#include<algorithm>
using namespace std;

int h[100005], left[100005], right[100005];

int main ()
{
    int n;
    while(~scanf("%d", &n))
    {
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d", &h[i]);
        }
        left[1] = 1;
        for(int i = 2; i <= n; i ++)
        {
            if(h[i] > left[i - 1])
                left[i] = left[i - 1] + 1;
            else
                left[i] = h[i];
        }
        right[n] = 1;
        for(int j = n - 1; j > 0; j --)
        {
            if(h[j] > right[j + 1])
                right[j] = right[j + 1] + 1;
            else
                right[j] = h[j];
        }
        int ma = 0, mb = 0, ans = 0;
        for(int i = 1; i <= n; i ++)
        {
            ma = min(left[i], right[i]);
            ans = max(ma, ans);
//            ma = max(ma, left[i]);
//            mb = max(mb, right[i]);
        }
//        for(int i = 1; i <= n; i ++)
//            printf("%d ", left[i]);
//            printf("\n");
//            for(int i = 1; i <= n; i ++)
//                printf("%d ", right[i]);
//            printf("\n");
        printf("%d\n", ans);
    }
    return 0;
}
