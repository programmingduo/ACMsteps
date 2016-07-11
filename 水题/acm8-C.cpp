#include<cstdio>
#include<string.h>
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

int myonwname[128];

int main()
{
    int n, total, ans;
    string person;
    while(~scanf("%d", &n) && n)
    {
        total = 0;
        ans = 0;
        cin>> person;
        memset(myonwname, 0, sizeof(myonwname));
        int len = person.length();
        for(int i = 0; i < len; i ++)
        {
            if(total < n && myonwname[person[i]] == 0)
                myonwname[person[i]] ++, total ++;
            else if(myonwname[person[i]] == 0)
            {
                myonwname[person[i]] = 3;
                ans ++;
            }
            else if(myonwname[person[i]] == 1)
            {
                myonwname[person[i]] = 2;
                total --;
            }
        }
        if(ans)
            printf("%d customer(s) walked away.\n", ans);
        else
            printf("All customers tanned successfully.\n");
    }
}
