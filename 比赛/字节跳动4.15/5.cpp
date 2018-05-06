#include <cstdio>

int main ()
{
    int N, a, b, c;
    scanf("%d", &N);
    while(N --)
    {
        scanf("%d %d %d", &a, &b, &c);
        if(c > a && c > b)
            printf("0\n");
        else
            printf("7\n");
    }
    return 0;
}
