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
        while(tempstr[j] = str[j])          //Ҫ��סÿ���µ�ѭ��Ҫʹ��ԭʼ�����ݣ���Ϊ���ѭ���а�����
                                            // �����ˣ�����谡Ӵ��һ��
            j ++;
        scanf("%d %d", &l, &r);
        l --;                               //�ڼ������ݺ������±��ת��
        r --;
        int direction = 1, last = l, flag = 0;   //flag=0��ʾ��һ������<>
                                                 //һ���ܼ򵥵ı�ǣ����Ǻ���Ч
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
        {                                       //������
            if(i)
                printf(" %d", number[i]);
            else
                printf("%d", number[i]);
        }
        printf("\n");
    }
    return 0;
}
