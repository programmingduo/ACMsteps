#include<cstdio>
#include<map>
#include<iostream>
#include<cstring>

using namespace std;

map< string, string > m;
char s[10000];
string a, b;

int main ()
{
    scanf("%s", s);
    //cin会保留\0,以后的输入必须getchar（）
    while(cin >> a>> b)
    {
        if(a == "END")
            break;
        m[b] = a;
    }
    getchar();
    while(gets(s))
    {
        if(s[0] == 'E' && s[1] == 'N' && s[2] == 'D')
            break;
        string t;
        int len = strlen(s);
        for(int i = 0; i < len; i ++)
        {
            if(islower(s[i]))
                t += s[i];
            else
            {
                if(m.find(t) != m.end())
                {
                    cout<< m[t];
                }
                else
                {
                    cout<< t;
                }
                cout<< s[i];
                t = "";
            }
        }
        cout<< endl;
    }
}
