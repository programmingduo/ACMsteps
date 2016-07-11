#include<cstdio>
#include<string.h>

char letter[300005];
int left[300005], right[300005];

int main ()
{
    int len, T;
    while(~scanf("%d%d", &len, &T))
    {
        memset(left, 0, sizeof(left));
        memset(right, 0, sizeof(right));
        scanf("%s", letter);
        for(int i = 1; i < len; i ++)
        {
            if(letter[i - 1] == '.')
                left[i] = left[i - 1] + 1;
        }
        for(int i = len - 2; i >= 0; i --)
        {
            if(letter[i + 1] == '.')
                right[i] = right[i + 1] + 1;
        }
        int total = 0;
        for(int i = 1; i < len; i ++)
        {
            if(letter[i] == '.' && letter[i - 1] == '.')
                total ++;
        }
        int pos, remain, now, ans;
        char c;
        while(T --)
        {
            scanf("%d%c%c", &pos, &c, &c);
            pos --;
            if(c == '.' && letter[pos] == '.')
                printf("%d\n", total);
            else if(c == '.')
            {
                if(pos >= 1 && letter[pos - 1] == '.')
                    total ++;
                if(pos < len - 1 && letter[pos + 1] == '.')
                    total ++;
                letter[pos] = '.';
                printf("%d\n", total);
            }
            else if(letter[pos] == '.')
            {
                if(pos >= 1 && letter[pos - 1] == '.')
                    total --;
                if(pos < len - 1 && letter[pos + 1] == '.')
                    total --;
                letter[pos] = 'a';
                printf("%d\n", total);
            }
            else
                printf("%d\n", total);
//            pos --;
//            if(letter[pos] == '.')
//                remain = left[pos] + right[pos];
//            else
//            {
//                if(left[pos])
//                    remain = left[pos] - 1;
//                else
//                    remain = 0;
//                if(right[pos])
//                    remain += right[pos] - 1;
//            }
//
//            if(c == '.')
//                now = left[pos] + right[pos];
//            else
//            {
//                if(left[pos])
//                    now = left[pos] - 1;
//                else
//                    now = 0;
//                if(right[pos])
//                    now += right[pos] - 1;
//            }
//            ans = total - remain + now;
//        printf("%d\n", ans);
        }
    }
    return 0;
}
