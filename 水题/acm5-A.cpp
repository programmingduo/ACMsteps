#include<cstdio>
#include<algorithm>

using namespace std;

int main ()
{
    int T,a,b,c, i, temp, flag1, flag2;
    scanf("%d", &T);
    while(T --)
    {
        flag1 = 0;
        flag2 = 0;
        scanf("%d%d%d", &a, &b, &c);
        if(c % 2 == 1)
        {
            printf("Impossible\n");
            continue;
        }
        c /= 2;
        if(a < b)
        {
            swap(a, b);
            flag1 = 1;
        }
        i = c / a;
        for(; i >= 0; i --)
        {
            int temp = c - i * a;
            if(temp % b == 0)
            {
                flag2 = 1;
                break;
            }
        }
        if(flag2)
        {
            if(flag1)
                printf("%d %d\n", (c - a * i) / b * 2, 2 * i);
            else
                printf("%d %d\n", 2 * i, (c - a * i) / b * 2);
        }
        else
        {
            printf("Impossible\n");
        }
    }
}
