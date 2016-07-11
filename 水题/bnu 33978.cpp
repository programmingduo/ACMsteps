#include<cstdio>

char r[100], l[100];
void oct(int a)
{

    int len = 0;
    while(1)
    {
        r[len ++] = '0' + a % 8;
        a /= 8;
        if(a == 0)
            break;
    }
    r[len] = '\0';
    for(int i = 0; i < len; i ++)
        l[i] = r[len - i - 1];
    l[len] = r[len];
    //printf(" %s ", r);
}

char r1[100], l1[100];
void hex(int a)
{

    int len = 0;
    while(1)
    {
        int temp = a % 16;
        if(temp > 9)
            r1[len ++] = temp - 10 + 'A';
        else
            r1[len ++] = temp + '0';
        a /= 16;
        if(a == 0)
            break;
    }
    r1[len] = '\0';
    for(int i= 0; i < len; i ++)
        l1[i] = r1[len - i - 1];
    l1[len] = r1[len];
    //printf(" %s ", r);
    return ;
}

int main()
{
    int a;
    while(~scanf("%d", &a))
    {
        oct(a);
        hex(a);
        printf("%s\n%s\n", l, l1);
    }
    return 0;
}
