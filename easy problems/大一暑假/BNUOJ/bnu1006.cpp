#include<cstdio>

using namespace std;

int main ()
{
    int a, b;
    while(scanf("%d%d", &a, &b) && (a || b))
    {
        int ans = 0, flag = 0, tempa = 0, tempb = 0;
        while(a || b)
        {
            tempa = a % 10;
            a /= 10;
            tempb = b % 10;
            b /= 10;
            if(flag)
            {
                tempa ++;
                flag = 0;
            }
            if(tempa + tempb > 9)
            {
                flag = 1;
                ans ++;
            }
        }
        if(ans == 0)
            printf("No carry operation.\n");
        else if(ans != 1)
            printf("%d carry operations.\n", ans);
        else
            printf("1 carry operation.\n");
    }
    return 0;
}
