#include<cstdio>

int even(long long a)
{
    if(a % 2)
        return 0;
    if(even(a / 2))
        return 0;
    return 1;
}

int main ()
{
    int T;
    long long a;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%I64d", &a);
        if(even(a))
            printf("Second Box\n");
        else
            printf("First Box\n");
    }
}
