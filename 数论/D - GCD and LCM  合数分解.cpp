#include<cstdio>
#include<math.h>
#include<algorithm>

using namespace std;

int main ()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        int a, b, ans = 1;
        scanf("%d%d", &a, &b);
        int k, len;
        if(b % a != 0)
        {
            printf("0\n");
            continue;
        }
        k = b / a;
        len = sqrt(static_cast<double> (k));
        for(int i = 2; i <= len; i ++)
        {
            if(k % i == 0)
            {
                int sum = 0;
                while(k % i == 0)
                {
                    k /= i;
                    sum ++;
                }
                ans = ans * sum * 6;
            }
            if(k == 1 || i > k)
                break;
        }
        if(k != 1)
            ans *= 6;
        printf("%d\n", ans);
    }
}
#include<cstdio>
#include<math.h>
#include<algorithm>

using namespace std;

int main ()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        int a, b, ans = 1;
        scanf("%d%d", &a, &b);
        int k, len;
        if(b % a != 0)
        {
            printf("0\n");
            continue;
        }
        k = b / a;
        len = sqrt(static_cast<double> (k));
        for(int i = 2; i <= len; i ++)
        {
            if(k % i == 0)
            {
                int sum = 0;
                while(k % i == 0)
                {
                    k /= i;
                    sum ++;
                }
                ans = ans * sum * 6;
            }
            if(k == 1 || i > k)
                break;
        }
        if(k != 1)
            ans *= 6;
        printf("%d\n", ans);
    }
}
