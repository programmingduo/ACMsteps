#include<cstdio>

int main ()
{
    long long ans = 1;
    for(int i = 0; i < 10; i ++)
    {
        ans = (ans * 26) % 20090717;
    }
    printf("%lld", ans);
}
