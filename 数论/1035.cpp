#include<cstdio>

int main ()
{
    int a, b;
    while(~scanf("%d%d", &a, &b) && (a || b))
        printf("%d\n", b);

    return 0;
}
