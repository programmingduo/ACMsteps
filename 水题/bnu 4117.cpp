#include<cstdio>

void meiju(int a, int b, int num)
{
    if(b == 0)
    {
        printf("%d\n", num);
        return ;
    }
    int t = num;
    for(int i = 1; i <= a; i ++)
    {
        t = num * 10 + i;
        meiju(a, b - 1, t);
    }
}

int main ()
{
    int a,b;
    scanf("%d%d", &a, &b);
    meiju(a, b, 0);
    return 0;
}
