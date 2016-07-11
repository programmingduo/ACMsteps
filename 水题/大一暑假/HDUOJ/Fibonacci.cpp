#include<iostream>

using namespace std;

long long Fibonacci(long long n)
{


    if(n == 1)
        return 1;
    if(n == 0)
        return 0;
    long long a = Fibonacci(n - 1);
    long long b = Fibonacci(n - 2);
//    if(a > 100000 && b > 100000)
  //  {
    //    a /= 10;
      //  b /= 10;
    //}
    return (a + b);
}

int main()
{
    long long n;
    while(cin>> n)
    {
        cout<< Fibonacci(n)<< endl;
    }
    return 0;
}
