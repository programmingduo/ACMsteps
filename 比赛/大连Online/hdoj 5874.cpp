#include <cstdio>


int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        long long a = n / 2, b = n - n / 2;
        if(a*b>m) printf("F\n");
        else printf("T\n");
    }
    return 0;
}
