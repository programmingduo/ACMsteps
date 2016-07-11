#include<cstdio>
#include<cstring>
#include<stack>

using namespace std;

char in[300000], map[100][100], total[100], ans[100];
stack<int> s;

bool isdigit(char a)
{
    if(a < '0' || a > '9')
        return false;
    return true;
}

int main ()
{
    int len, flag = 0, num, max;
    while(gets(in) != NULL)
    {
        while(!s.empty())
            s.pop();
        memset(map, 0, sizeof(map));
        memset(total, 0, sizeof(total));
        len = strlen(in);
        //printf("%s ", in);
        max = 0;
        flag = 0;

        for(int i = 1; i < len; i ++)
        {
            if(isdigit(in[i]))
            {
                num = in[i] - '0';
                if(isdigit(in[i + 1]))
                {
                    num = num * 10 + in[i + 1] - '0';
                    i ++;
                }
                if(num > max)
                    max = num;
                if(flag)
                {
                    int temp = s.top();
                    map[temp][num] = map[num][temp] = 1;
                    total[temp] ++;
                    total[num] ++;
                }
                s.push(num);
                flag = 1;
            }
            if(in[i] == ')')
            {
                s.pop();
            }
        }

        int all = 0;
        for(int i = 1; i <= max; i ++)
        {
            for(int j = 1; j <= max; j ++)
            {
                if(total[j] == 1)
                {
                    for(int k = 1; k <= max; k ++)
                    {
                        if(map[j][k] == 1)
                        {
                            map[j][k] = map[k][j] = 0;
                            ans[all ++] = k;
                            total[k] --;
                            total[j] --;
                        }
                    }
                    break;
                }
            }
        }

        //printf("answer\n");
        for(int i = 0; i < all; i ++)
        {
            if(i)
                printf(" %d", ans[i]);
            else
                printf("%d", ans[i]);
        }
        printf("\n");
    }
}
