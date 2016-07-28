#include<bits/stdc++.h>
using namespace std;

int a[100006];
int b[100005];
int main() {

    int i,x,y,n,m;
    cin >> n >> m;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    long long row = n;
    long long col = n;
    for(i = 0; i < m; i ++) {
        cin >> x >> y;
        if(a[x - 1] == 0) {
            a[x - 1] = 1;
            row --;
        }
        if(b[y - 1] == 0) {
            b[y - 1] = 1;
            col --;
        }
     //   cout << rowleft << " " << colleft <<"\n";
        if(i ==0)
            cout << row * col ;
        else
            cout <<" " <<  row * col;
    }
    cout << "\n";
}
