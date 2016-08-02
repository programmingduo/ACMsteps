#include<cstdio>

using namespace std;

int main ()
{
    char a[8][8], b[8][8];
    for(int i = 0; i < 8; i ++)
        scanf("%s", a[i]);

    for(int i = 0; i < 8; i ++)
        scanf("%s", b[i]);

    float ans = 0;
    for(int i = 0; i < 8; i ++)
        for(int j = 0; j < 8; j ++)
    {
        int flag;
        switch(a[i][j])
        {
            case '.':
                flag = 1;
                break;
            case '*':
                flag = 2;
                break;
            case '#':
                flag = 3;
                break;
        }

        int x[] = {i, 7 - j, 7 - i, j}, y[] = {j, i, 7 - j, 7 - i};
        for(int k = 0; k < 4; k ++)
        {
            if(a[i][j] == b[x[k]][y[k]])
                ans += flag;
        }
    }
    printf("%.2lf\n", ans / 4);
    return 0;
}
