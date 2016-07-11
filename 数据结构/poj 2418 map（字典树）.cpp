#include<cstdio>
#include<map>
#include<iostream>
#include<iterator>

using namespace std;

int main ()
{
    map<string, int> m;
    map<string, int> ::iterator it;
    string s;
    char temp[50];
    int total = 0;
    while(gets(temp))
    {
        s = temp;
        total ++;
        m[s] ++;
    }

    for(it = m.begin(); it != m.end(); it ++)
    {
        cout<< it->first;
        printf(" %.4f\n",(float) (it->second) * 100 / (float) total);
    }
    return 0;

}
