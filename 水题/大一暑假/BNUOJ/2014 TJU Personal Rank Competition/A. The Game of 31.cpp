#include<iostream>
#include<cstring>
using namespace std;

bool youxi(int digit[], int sum)
{
    if(sum == 31)
        return 0;
    for(int i = 1; i <= 6; i ++)
    {
        if(digit[i] && sum + i <= 31)
        {
            digit[i] --;
            if(youxi(digit, sum + i) == 0)
            {
                digit[i] ++;
                return 1;
            }
            digit[i] ++;
        }
    }
    return 0;
}

int main()
{
    string a;
    while(cin>> a)
    {
        int sum = 0;
        int digit[7];
        for(int i = 1; i <= 6; i++)
            digit[i] = 4;
        for(int i = 0; i < a.length(); i ++)
        {
            int temp = a[i] - '0';
            digit[temp] --;
            sum += temp;
        }
        bool b = youxi(digit, sum);
        if(a.length() % 2 == 1 && !b || a.length() % 2 == 0 && b)
            cout<< a<< " A"<< endl;
        else
            cout<< a<< " B"<< endl;
    }
    return 0;
}
