#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
    int n,num[10001],l,r,mid;
    while(cin>>n)
    {
        mid=n>>1;
        for(int i=0;i<n;i++)
            cin>>num[i];
        sort(num,num+n);
        for(l=0,r=n-1;l<mid&&r>mid;l++,r--)
        {
            cout<<num[r]<<" "<<num[l]<<" ";
        }
        if(r==l)cout<<num[l]<<endl;
        else cout<<num[r]<<" "<<num[l]<<endl;
    }
    return 0;
}
