#include<cstdio>

//´ó¸Å¾ÍÊÇ(x + k) % n;

int main ()
{
    int T, n;
    scanf("%d", &T);
    while(T --)
    {
        int s = 0;
        scanf("%d", &n);
        for(int i = 2; i <= n; i ++)
            s = (s + n - i + 1) % i;
        printf("%d\n", s + 1);
    }
    return 0;
}
