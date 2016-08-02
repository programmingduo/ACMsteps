#include<iostream>
#include<string.h>

using namespace std;

short temp[1000005], flag[1000005];

int main ()
{
    memset(flag, 0, sizeof(flag));
    for(int i = 2; i < 40000; i ++)
    {
        cout<< "i = "<<i<< endl;
        if(!flag[i])
            for(int j = i; j * i <= 40000 ; j ++)
            {
                flag[i * j] = 1;
            }
    }

    for(int i = 0; i < 40001; i ++)
        if(!flag[i])
        cout<< i<< endl;
}
