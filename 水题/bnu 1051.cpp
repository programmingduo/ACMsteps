#include<iostream>

using namespace std;

int main ()
{
    int T, a, b;
    cin>> T;
    while(T --)
    {
        cin>> a>> b;
        cout<< a - (b - 1) * 2<< endl;
    }
    return 0;
}
