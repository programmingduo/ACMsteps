#include <iostream>
#include <cmath>
using namespace std;

#define f(x) (x*x+3)

int gcd(int a, int b)
{
    if (b == 0) return a;
        else return gcd(b, a%b);
}

int pollard(int n)
{
    int x, y, k, i, d;
    x = y = 5;
    k = 0, i = d  = 1;
    while(d == 1){
        k ++;
        x = f(x)%n;
        d = gcd(n, abs(x-y));
        if (d > 1 && d < n) return d;
        if (d == n) return -1;
        if (k == i){
            y = x;
            i <<= 1;
        }
    }
}


int main()
{
    int n;
    while(cin >> n){
        cout << pollard(n) << endl;
    }
    return 0;
}
