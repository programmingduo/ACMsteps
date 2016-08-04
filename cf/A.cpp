#include<cstdio>

int main ()
{
    int n,a,b, x, y;
    x = y = 0;
    scanf("%d", &n);
    while(n --)
    {
        scanf("%d %d", &a, &b);
        if(a > b)
            x ++;
        if(a < b)
            y ++;
    }
    if(x > y)
    {
        printf("Mishka\n");
    }
    if(x < y)
    {
        printf("Chris\n");
    }
    if(x == y)
    {
        printf("Friendship is magic!^^\n");
    }
    return 0;
}
