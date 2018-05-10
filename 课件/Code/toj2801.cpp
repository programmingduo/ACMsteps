#include <iostream>
using namespace std;
string s;
void solve(int head,int end)
{
    if(head==end)
    {
        cout<<s[head];
        return;
    }
    else
    {
        int t;
        int count=0;
        for(int i=end-1; i>=head; i--)
        {
            if(s[i]>='A'&&s[i]<='Z')
                count--;
            else
                count++;
            if(count==1)
            {
                t=i;
                break;
            }
        }
        solve(head,t-1);
        cout<<s[end];
        solve(t,end-1);
    }
}
int main()
{
    int num;
    cin>>num;
    while(num--)
    {
        cin>>s;
        solve(0,s.length()-1);
        cout<<endl;
    }
    return 0;
}
