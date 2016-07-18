#include<cstdio>

using namespace std;

int main ()
{
    int a[100] = {0, 1312, 2372, 539, 932, 829, 1086, 1463, 1313,
                  1681,2080,495,737,577,786,1011,999,1251,1520};
    a[35] = 1139;
    a[36] = 1350;
    a[53] = 1008;
    a[54] = 1170;
    a[85] = 890;
    a[86] = 1037;
    int f, s;
    while(~scanf("%d%d", &f, &s))
    {
        if(a[f] > a[s])
            printf("FIRST BIGGER\n");
        else
            printf("SECOND BIGGER\n");
    }
    return 0;
}
