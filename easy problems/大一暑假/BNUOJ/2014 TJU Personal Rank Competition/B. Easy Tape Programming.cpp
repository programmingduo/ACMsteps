#include<stdio.h>

int main()
{
    int strlen, sequences;
    scanf("%d %d", &strlen, &sequences);
    char str[1000000], tempstr[1000000];
    scanf("%s", &str);
    while(sequences --)
    {
        int l, r, j = 0, number[10] = {0};
        while(tempstr[j] = str[j])          //要记住每次新的循环要使用原始的数据，因为你的循环中吧数据
                                            // 更改了，因此需啊哟这一步
            j ++;
        scanf("%d %d", &l, &r);
        l --;                               //第几个数据和数组下标的转换
        r --;
        int direction = 1, last = l, flag = 0;   //flag=0表示上一个不是<>
                                                 //一个很简单的标记，但是很有效
        for(int i = l; i <= r && i >= l; i += direction)
        {
            if(tempstr[i] <= '9' && tempstr[i] >= '0')
            {
                number[tempstr[i] - '0'] ++;
                flag = 0;
                last = i;
                if(tempstr[i] == '0')
                    tempstr[i] = ' ';
                tempstr[i] --;
            }
            else if(tempstr[i] == '<')
            {
                direction = -1;
                if(flag)
                    tempstr[last] = ' ';
                flag = 1;
                last = i;
            }
            else if(tempstr[i] == '>')
            {
                direction = 1;
                if(flag)
                    tempstr[last] = ' ';
                flag = 1;
                last = i;
            }
        }
        for(int i = 0; i <= 9; i ++)
        {                                       //这个输出
            if(i)
                printf(" %d", number[i]);
            else
                printf("%d", number[i]);
        }
        printf("\n");
    }
    return 0;
}
