#include <cstdio>

using namespace std;

int main ()
{
    long double a;
    int R;
    while(scanf("%lf%d", &a, &R))
    {
        long double result = 1;
        for(int i = 0; i < R; i ++)
        {
            result *= a;
        }
        printf("%lf", result);
    }
    return 0;
}
