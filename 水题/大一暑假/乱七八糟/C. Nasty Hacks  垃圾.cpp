#include<cstdio>

using namespace std;

int main ()
{
    int n;
    scanf("%d", &n);
    for(int i =0; i < n; i ++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int temp = b - c;
        if(a > temp)
            printf("do not advertise\n");
        else if(a == temp)
            printf("does not matter\n");
        else
            printf("advertise\n");
    }
    return 0;
}
