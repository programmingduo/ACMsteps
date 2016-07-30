//Calculate how many 0s at the end of the value below:
//1n + 2n + 3n + ... + mn
//(1 <= m <= 100 , 1 <= n <= 1000000)
//结果不会太多。

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

long long m,n;
long long multi(long long a, long long b)
{
    long long ret;
    ret = 1;
    while(b > 0)
    {
        if(b & 1)
            ret  = ret * a %  (int)1e9;
        a = (a * a) %  (int)1e9;
        b = b >> 1;
    }
    return ret;
}
int main()
{
   for(int m = 1; m <= 100; m ++)
    for(int n = 1; n <= 1000000; n ++)
   {
       long long sum=0;
       for(int i=1; i<=m; ++i)
       {
           sum+=multi(i, n)% (int)1e9;
       }
       int jj=0;
       while(sum>0)
       {
          if(sum%10==0) jj++;
          else break;
          sum/=10;
       }
   if(jj > 10)
       cout<<jj<<endl;
   }
    return 0;
}
