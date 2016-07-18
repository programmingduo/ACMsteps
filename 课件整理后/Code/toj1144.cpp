#include <iostream>
#include <cstring>
using namespace std;
string s1,s2;
void solve(int head1,int end1,int head2,int end2)
{
    if(head1>end1||head2>end2)
        return;
    else
    {
        int t;
        for(int i=head2; i<=end2; i++)
        {
            if(s1[head1]==s2[i])
            {
                t=i;
                break;
            }
        }
        solve(head1+1,head1+t-head2,head2,t-1);
        solve(head1+t-head2+1,end1,t+1,end2);
        cout<<s2[t];
    }
}
int main()
{
    while(cin>>s1>>s2)
    {
        solve(0,s1.length()-1,0,s2.length()-1);
        cout<<endl;
    }
    return 0;
}
