#include<cstdio>

int main ()
{
    long long a = 100, b = 100, x, y, lx, ly;
    int flag = 1;
    while(~scanf("%lld %lld", &x, &y))
    {
        if(flag)
        {
            printf("0, 0\n");
            lx = x, ly = y;
            flag = 0;
            continue;
        }
        if((x - a) * (x - a) + (y - b) * (y - b) < (lx - a) * (lx - a) + (ly - b) * (ly - b))
        {
            printf("1\n");
        }
        else
            printf("0\n");
        lx= x;
        ly = y;
    }
}
