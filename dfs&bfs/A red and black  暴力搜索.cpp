#include<iostream>

using namespace std;

int total = 0;
char chart [25][25];
int w, h;

void bianli(int x, int y)
{
    chart[x][y] = '#';
    if(x > 0 && chart[x - 1][y] == '.')
    {
        total ++;
        bianli(x - 1, y);
    }
    if(y > 0 && chart[x][y - 1] == '.')
    {
        total ++;
        bianli(x, y - 1);
    }
    if(x < h - 1 && chart[x + 1][y] == '.')
    {
        total ++;
        bianli(x + 1, y);
    }
    if(y < w - 1 && chart[x][y + 1] == '.')
    {
        total ++;
        bianli(x, y + 1);
    }
    return ;
}

int main ()
{
    while(cin>> w>> h)
    {
        if(w == 0 && h == 0)
            break;
        int x, y;
        for(int i = 0; i < h; i ++)
        {
            for(int j = 0; j < w; j ++)
            {
                cin>> chart[i][j];
                if(chart[i][j] == '@')
                {
                    x = i;
                    y = j;
                }
            }
        }
        total = 0;
        bianli(x, y);
        cout<< total + 1<< endl;
    }
    return 0;
}
