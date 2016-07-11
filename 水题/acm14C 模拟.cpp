#include<cstdio>
#include<string.h>

int main ()
{
    //this is my bug
    char s[50];
    int flag1, flag2[50], flag;
    while(~scanf("%s", s))
    {
        memset(flag2, 0, sizeof(flag2));
        flag1 = 0;
        for(int i = 0; i < 14; i ++)
        {

            int temp = s[i ++] - '0';
            if(s[i] == 'm')
                temp += 10;
            else if(s[i] == 'p')
                temp += 20;
            else if(s[i] == 'z')
                temp += 30;
            flag1 = flag1 ^ temp;
            flag2[temp] ++;
        }

        if(flag1 == 0)
        {
            printf("Seven Pairs\n");
            continue;
        }
        flag1 = 0;
        for(int i = 31; i <= 37; i ++)
        {
            if(flag2[i] == 0)
                flag1 = 0;
            if(flag2[i] == 2)
                flag = 1;
        }
        if(!(flag2[1] && flag2[9] && flag2[11] && flag2[19] && flag2[21] && flag2[29]))
            flag1 = 0;
        if(flag2[1] == 2 || flag2[9] == 2 || flag2[11] == 2 || flag2[19] == 2
           || flag2[21] == 2 || flag2[29] == 2)
            flag = 1;
        if(flag && flag1)
            printf("Thirteen Orphans\n");
        else
            printf("Neither!\n");
    }
    return 0;
}
