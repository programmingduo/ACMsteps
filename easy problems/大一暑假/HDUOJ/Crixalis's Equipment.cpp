#include<iostream>

using namespace std;

int main()
{
    int N;
    cin>> N;
    while(N --)
    {
        int space, equi;
        cin>> space>> equi;
        int store[10005], carry[10003], bianli[10003];
        for(int i = 0; i < equi; i ++)
        {
            cin>> store[i]>> carry[i];
            bianli[i] = carry[i] - store[i];
        }
        int used = 0;
        bool YES = 1;
        for(int i = 0; i < equi; i ++)
        {
            int k, j = 0, max = -1;
            for(; j < equi; j ++)
            {
                if(bianli[j] > max)
                {
                    max = bianli[j];
                    k = j;
                }
            }
            bianli[k] = -1;
            if(used + carry[k] > space)
            {
                YES = 0;
                break;
            }
            used += store[k];
        }
        if(YES)
            cout<< "Yes"<< endl;
        else
            cout<< "No"<< endl;
    }
    return 0;
}
