#include <cstdio>
#include <cmath>
#define eps 1e-5
using namespace std;

double x,y;
int ans,n;

int main()
{
    while (scanf("%lf%lf",&x,&y)!=EOF)
    {
        ans=(int)(x-1);
        y-=x-1+eps;
        if (y<0)
        {
            printf("-1\n");
            continue;
        }
        for (int i=1; i<=x; i++)
        {
            n=(int)(i*y/x);
            ans+=n;
            y-=n*x/i;
            if (y<1) break;
        }
        printf("%d\n",ans);
    }
    return 0;
}
