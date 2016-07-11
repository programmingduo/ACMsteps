#include<cstdio>
#include<cstring>

using namespace std;

int main ()
{
    int a[35];
    memset(a, 0, sizeof(a));
    a[0] = 1;
    a[2] = 3;
    for(int i = 4; i <= 34; i += 2)
        a[i] = a[i - 2] * 4 - a[i - 4];

    int n;
    while(~scanf("%d", &n) && n != -1)
    {
        printf("%d\n", a[n]);
    }
    return 0;
}
