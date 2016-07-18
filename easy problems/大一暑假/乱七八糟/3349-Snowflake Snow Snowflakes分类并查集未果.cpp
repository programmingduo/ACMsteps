#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

struct snow
{
    int num[2][12];
};

snow hashtable[15000][100];
int sum[15000];

void initialhash()
{
    cout<< "in Initialhash "<< endl;
    memset(sum, 0, sizeof(sum));
}

int gethash(int *num)
{
    cout<< "in gethash "<< endl;
    int total;
    for(int i = 0; i < 6; i ++)
    {
        total = total % 15000 + num[i];
    }
    return total;
}

snow tonode(int *num)
{
    cout<< "in tonode"<< endl;
    snow temp;
    for(int i = 0; i < 6; i ++)
    {
        temp.num[1][i] = temp.num[1][i + 6] = num[i];
    }
    for(int i = 0; i < 6; i ++)
    {
        temp.num[2][5 - i] = temp.num[2][11 - i] = num[i];
    }
    return temp;
}

bool compare(int * num)
{
    cout<< "in compare "<< endl;
    int temp = gethash(num);
    int cur = sum[temp];
    for(int i = 0; i < cur; i ++)
    {
        for(int j = 0; j < 6; j ++)
        {
            if(hashtable[temp][cur].num[0][j] == num[0])
            {
                bool flag = 1;
                for(int k = 0; k < 6; k ++)
                {
                    if(hashtable[temp][cur].num[0][j + k] != num[k])
                        flag = 0;
                }
                if(flag)
                    return 1;
            }
        }
        for(int j = 0; j < 6; j ++)
        {
            if(hashtable[temp][cur].num[1][j] == num[0])
            {
                bool flag = 1;
                for(int k = 0; k < 6; k ++)
                {
                    if(hashtable[temp][cur].num[1][j + k] != num[k])
                        flag = 0;
                }
                if(flag)
                    return 1;
            }
        }
    }
    return 0;
}

int main ()
{
    int n;
    while(cin>> n)
    {
        initialhash();
        bool twin = 0;
        int * num0;
        num0 = new int [6];
        for(int h = 0; h < n; h ++)
        {
            for(int j = 0; j < 6; j ++)
            {
                scanf("%d", &num0[j]);
            }
            if(twin)
                continue;
            twin = compare(num0);

            if(!twin)
            {
                int temp = gethash(num0);
                hashtable[temp][sum[temp]] = tonode(num0);
                sum[temp] ++;
                cout<< h<< endl;
            }
            cout<< "h2 "<< h<< endl;
        }
        if(twin)
            cout<< "twin "<< endl;
        else
            cout<< "no twin "<< endl;
    }
    return 0;
}
