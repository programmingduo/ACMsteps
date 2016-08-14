#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;
ll n;

int main()
{
    for (int i = 73; i <= 10000000; i++){
        if(i % 73 == 0 && i % 137 == 0)
            cout << i << " ";
    }
    cout << endl;
    return 0;
}
