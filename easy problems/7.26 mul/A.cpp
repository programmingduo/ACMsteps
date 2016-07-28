#include<cstdio>
#include<cmath>
#include<cstring>

char s[1000005];

long long tonum()
{
    int len = strlen(s);
    long long t = 0;
    for(int i = 0; i < len; i ++)
    {
        t = t * 10 + s[i] - '0';
    }
//    printf("t = %lld\n", t);
    return t;

}

long long l[16], r[15];
int main ()
{
    long long a;
    l[0] = r[0] = 1;
    l[1] = 2;
    r[1] = 3;
    for(int i = 1; i < 5; i ++)
    {
        r[i + 1] = (r[i] + 1) * (r[i] + 1) - 1;
    }
//    for(int i = 0; i <= 5; i ++)
//        printf("%lld\n", r[i]);
    while(~scanf("%s", s))
    {
        if(strcmp(s, "0") == 0)
        {
            printf("TAT\n");
            continue;
        }
        if(strlen(s) > 10)
        {
            printf("TAT\n");
            continue;
        }
        long long num = tonum();
        int flag=  1;
        for(int i = 0; i <= 5 && flag; i ++)
        {
            if(num <= r[i])
            {
                printf("%d\n", i);
                flag = 0;
            }
        }
        if(flag)
            printf("TAT\n");
    }
    return 0;
}
