#include<cstdio>

using namespace std;

int exgcd(int a, int b, int& x, int& y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int ret = exgcd(b, a % b, x, y);
    int temp = x;
    x = y;
    y = temp - a / b * y;
    return ret;
}

int main ()
{
    int T;
    scanf("%lld", &T);
    while(T --)
    {
        int n, b;
        scanf("%lld%lld", &n, &b);
        int temp, ans;
        exgcd(b, 9973, ans, temp);
        ans = (ans % 9973 + 9973) % 9973;
        ans = (ans * n) % 9973;
        printf("%lld\n", ans);
    }
}
