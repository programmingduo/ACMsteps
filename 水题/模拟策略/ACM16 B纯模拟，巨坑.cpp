#include<cstdio>
#include<string.h>

int s[10][10];

int main ()
{
    memset(s, 0, sizeof(s));
    s[3][1] = s[1][3] = 2;
    s[1][7] = s[7][1] = 4;
    s[1][9] = s[9][1] = 5;
    s[2][8] = s[8][2] = 5;
    s[3][9] = s[9][3] = 6;
    s[3][7] = s[7][3] = 5;
    s[4][6] = s[6][4] = 5;
    s[7][9] = s[9][7] = 8;
    int T, temp[10];
    scanf("%d", &T);
    while(T -- )
    {
        int k, n[10], flag = 1;
        scanf("%d", &k);
        for(int i = 0; i < k; i ++)
        {
            scanf("%d", &n[i]);
            if(n[i] == 0 || n[i] > 9)
            {
                flag = 0;
            }
        }
        if(k < 4 || k > 9 || flag == 0)
        {
            printf("invalid\n");
            continue;
        }
        memset(temp, 0, sizeof(temp));
        temp[n[0]] = 1;
        for(int i = 1; i < k && flag; i ++)
        {
            if(temp[n[i]] == 1)
                flag = 0;
            temp[n[i]] = 1;
            int temp0 = s[n[i]][n[i - 1]];
            if(temp0 != 0 && temp[temp0] == 0)
                flag = 0;
        }
        if(flag)
            printf("valid\n");
        else
            printf("invalid\n");
    }
    return 0;
}
