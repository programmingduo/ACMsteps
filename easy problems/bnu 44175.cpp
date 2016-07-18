#include<cstdio>

int main ()
{
    int N, a;
    scanf("%d", &N);
    while(N --)
    {
        scanf("%d", &a);
        if(a > 0)
            printf("1\n");
        else if(a == 0)
            printf("0\n");
        else
            printf("-1\n");
    }
    return 0;
}
