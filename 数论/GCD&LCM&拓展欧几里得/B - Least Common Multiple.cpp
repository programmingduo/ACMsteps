#include<cstdio>

using namespace std;

int num[1000000];

int GCD(int a, int b)
{
    return b == 0? a : GCD(b, a % b);
}

int main ()
{
    int T;
    scanf("%lld", &T);
    for(int i = 0; i < T; i ++)
    {
        int number;
        scanf("%lld", &number);
        for(int j = 0; j < number; j ++)
        {
            scanf("%lld", &num[j]);
        }

        int ans = 1;
        for(int j = 0; j < number; j ++)
        {
            ans = ans / GCD(ans, num[j]) * num[j];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
