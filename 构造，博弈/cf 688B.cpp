#include<iostream>
#include<string>

using namespace std;
string a;
int main ()
{

    while(cin>> a)
    {
        cout<< a;
        for(int i = a.length() - 1; i >= 0; i --)
            cout<< a[i];
        cout<< endl;
    }
    return 0;
}
