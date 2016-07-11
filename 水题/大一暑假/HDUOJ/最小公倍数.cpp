#include<iostream>

using namespace std;

int GCD(int a, int b)
{
    if(a == 0 || b == 0)
        return 0;
    if(b > a)
        return GCD(b, a);

    return a % b == 0 ? b : GCD(a % b, b);

}

int GCM(int a, int b)
{
    if(a == 0 || b == 0)
        return 0;
    return a * b / GCD(a, b);
}
int main ()
{
    int a, b;
    while(cin>> a>> b){
        cout<<GCM(a, b)<< endl;
    }
    return 0;
}
