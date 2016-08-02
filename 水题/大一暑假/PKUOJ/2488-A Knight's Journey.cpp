#include<iostream>
using namespace std;

lie[] = {1, 2, 2, 1, -1, -2, -2, -1};
hang[] = {-2, -1, 1, 2, 2, 1, -1, -2};

bool boundary(int j, int k, int row, int column)
{
    if(j < 0 || k < 0)
        return 0;
    if(j >= row || k >= column)
        return 0;

    return 1;
}

bool finished(int chart[][], int row, int column)
{
    for(int i = 0; i < row; i ++)
        for(int j = 0; j < column; j ++)
        {
            if(chart[i][j] == 0)
                return 0;
        }

    return 1;
}

bool journey(int j, int k, int row, int column, int chart[][])
{
    if(chart[j][k])
        return false;

    chart[j][k] = 1;
}

bool journey(int j, int k, int row, int column)
{
    int chart[27][27] = {0};
    chart[j][k] = 1;
    for(int i = 0; i < 8; i ++)
    {
        if(boundary(j + hang[i], k + lie[i], row, column))
        {
            if(journey(j = hang[i], k + lie[i], row, column, chart))
                return 1;
        }
    }
    return 0;
}

int main ()
{
    int cases;
    int column, row;
    cin>> cases;
    for(int i = 0; i < cases; i ++)
    {
        if(i)
            cout<< endl;
        cin>> column>> row;
        bool falg = 1;
        for(int j = 0; j < row; j ++)
            for(int k = 0; k < column; k ++)
            {
                if(journey(j, k, row, column))
                {
                    if(flag)
                    {
                        cout<< "Scenario #"<< i<< ":"<< endl;
                        flag = 0;
                    }

                    cout<< static_cast<char> (A + row)<< column;
                }
            }
        if(flag)
        {
            cout<< "Scenario #"<< i<< ":"<< endl;
            cout<< "impossible"<< endl;
        }
    }
}
