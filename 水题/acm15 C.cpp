#include<string>
#include<iostream>

using namespace std;

string a[105], b[1000];

int main ()
{
    int T;
    cin>> T;
    for(int i = 0; i < T; i ++)
        cin>> a[i];
    int n, m;
    cin>> n;
    for(int i = 0; i < n; i ++)
    {
        int ans = 0;
        string temp;
        cin>> m;
        for(int j = 0; j < m; j ++)
        {
            cin>> temp;
            for(int k = 0; k < T; k ++)
            {
                if(a[k] == temp)
                    ans ++;
            }
        }
        cout<< ans<< endl;
    }
    return 0;
}
