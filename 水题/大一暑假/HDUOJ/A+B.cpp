#include<iostream>
#include<string>
using namespace std;

inline int convert(string m)
{
    int number = 0;
    for(int i = 0; i < m.length(); i ++)
    {
        if(m[i] >= '0' && m[i] <= '9')
            number = number * 16 + m[i] - '0';
        else if(m[i] >= 'a' && m[i] <= 'z')
            number = number * 16 + m[i] - 'a' + 10;
        else
            number = number * 16 + m[i] - 'A' + 10;
    }
    return number;
}

int main ()
{
    string a, b;
    while(cin>> a>> b)
    {
        int c, d;
        c = convert(a);
        d = convert(b);
        cout<< c + d<< endl;
    }
    return 0;
}
