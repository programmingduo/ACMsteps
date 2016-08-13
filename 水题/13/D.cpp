#include<iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int sto[6];

int main()
{
    int T;
    scanf("%d", &T);
    while(T --){
        for(int i = 0; i < 5; i ++){
            scanf("%d", &sto[i]);
        }
        sort(sto, sto + 5);
        cout << sto[4] * sto[3] << endl;
    }

    return 0;
}
