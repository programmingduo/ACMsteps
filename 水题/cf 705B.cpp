#include<cstdio>

int main ()
{
    int n, total, t;
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d", &n);
        total += n - 1;
        total %= 2;
        if(total)
            printf("1\n");
        else
            printf("2\n");
    }
}
