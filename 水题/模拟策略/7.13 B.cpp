#include<cstdio>

int a[200005];

int main ()
{
    int n, k;
    while(~scanf("%d%d", &n, &k))
    {
        int odd = 0, even = 0;
        for(int i = 0; i < n; i ++)
        {
            scanf("%d", &a[i]);
            if(a[i] % 2)
                odd ++;
            else
                even ++;
        }

        int s = (n - k + 1) / 2;
        int d = n - k - s;

        if(k == 0)
            printf("Daenerys\n");
        else if(k % 2)
        {
            if((n - k) % 2)
            {
                if(d < odd)
                    printf("Stannis\n");
                else
                    printf("Daenerys\n");
            }
            else
            {
//                printf("%d %d", s, even);
                if(s < even)
                    printf("Daenerys\n");
                else
                    printf("Stannis\n");
            }
        }
        else
        {
            if((n - k) % 2)
            {
                if(d < even && d < odd)
                    printf("Stannis\n");
                else
                    printf("Daenerys\n");
            }
            else
                printf("Daenerys\n");
        }
    }
    return 0;
}


//
//#include <iostream>
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <string>
//#include <cmath>
//#include <cstdlib>
//#include <vector>
//#include <queue>
//#include <set>
//#include <map>
//
//using namespace std;
//
//int n,k;
//int even,odd;
//
//string EVEN="Daenerys";
//string ODD="Stannis";
//
//int main()
//{
//    //freopen("in.txt","r",stdin);
//    //freopen("out.txt","w",stdout);
//
//    scanf("%d%d",&n,&k);
//    for(int i=0,x;i<n;i++)
//    {
//        scanf("%d",&x);
//        if(x%2==0) even++;
//        else odd++;
//    }
//
//    if(n==k)
//    {
//        if(odd%2==1) puts(ODD.c_str());
//        else puts(EVEN.c_str());
//        return 0;
//    }
//
//    int m=n-k;
//    int soo=m-m/2;
//    int doo=m/2;
//
//    if(k%2==1)
//    {
//        /// S make last move
//        if(m%2==1)
//        {
//            int other = max(0,soo-(even-1)-1);
//            if(doo+other>=odd)
//            {
//                puts(EVEN.c_str()); return 0;
//            }
//            else
//            {
//                puts(ODD.c_str()); return 0;
//            }
//        }
//        else // D make last move
//        {
//            int other = max(0,doo-(odd-1)-1);
//            if(soo+other>=even)
//            {
//                puts(ODD.c_str()); return 0;
//            }
//            else
//            {
//                puts(EVEN.c_str()); return 0;
//            }
//
//        }
//    }
//    else if(k%2==0)
//    {
//        /// S make last move
//        if(m%2==1)
//        {
//            bool flag=false;
//            int other = max(0,soo-(even-1)-1);
//            if(doo+other>=odd) flag=true;
//            other = max(0,soo-(odd-1)-1);
//            if(doo+other>=even) flag=true;
//            if(flag)
//            {
//                puts(EVEN.c_str()); return 0;
//            }
//            else
//            {
//                puts(ODD.c_str()); return 0;
//            }
//
//        }
//        else // D make last move
//        {
//            puts(EVEN.c_str()); return 0;
//        }
//    }
//
//
//    return 0;
//}
