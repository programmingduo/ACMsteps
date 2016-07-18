#include<iostream>
#include<algorithm>

using namespace std;

int main ()
{
    int cases;
    cin>> cases;
    for(int i = 0; i < cases; i ++)
    {
        int N, number[1003];
        cin>> N;
        for(int j = 0; j < N; j ++)
            cin>> number[j];
        sort(number, number + N);
        cout<< number[0];
        for(int j = 1; j < N; j ++)
            cout<< " "<< number[j];
            cout<< endl;
    }
}
