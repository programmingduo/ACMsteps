#include<cstdio>
#include<cmath>

int main ()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        int n;
        scanf("%d", &n);
        for(int i = sqrt(1.0 * n); i > 0; i --)
        {
            if(n % i == 0)
            {
                printf("%d\n", n / i * 2 + i * 2);
                break;
            }
        }
    }
}
