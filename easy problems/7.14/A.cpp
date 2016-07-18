#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int Base = 1000000000;
const int Capacity = 100;

char ans[107];

string add(string a, string b)
{
    int i = a.length() - 1, j = b.length() - 1;
    char c[105];
    string ans;
    int flag = 0;
    int t = 0;
    while(i >= 0 && j >= 0)
    {
        int l = a[i] - '0' + flag + b[j] - '0';
        c[t ++] = '0' + l % 10;
        flag = 0;
        if(l >= 10)
            flag = 1;
        i --, j --;
    }
    while(i >= 0)
    {
        int l = flag + a[i] - '0';
        c[t ++] = '0' + l % 10;
        flag = 0;
        if(l >= 10)
            flag = 1;
        i --;
    }
    while(j >= 0)
    {
        int l = flag + b[j] - '0';
        c[t ++] = '0' + l % 10;
        flag = 0;
        if(l >= 10)
            flag = 1;
            j --;
    }
    if(flag)
        c[t++] = '1';
        c[t] = '\0';
//        printf("%s sdf %d ", c, t);
        t --;
    for(int i = 0; i <= t; i ++)
        ans += c[t - i];

    return ans;
}

int main ()
{
    string a[3];
    while(cin>> a[0])
    {
        cin>> a[1]>> a[2];
        int flag = 1;
        for(int i = 0; flag && i < 3; i ++)
            for(int j = 0; j < 3 && flag; j ++)
        {
            string temp = add (a[i], a[j]);
//            cout<< temp<< endl;
            for(int k = 0; k < 3 && flag; k ++)
            {
//                cout<< temp<< "=="<< a[k]<< endl;
                if(temp == a[k])
                flag = 0;
            }
        }
        if(flag)
            printf("NO\n");
        else
            printf("YES\n");

    }
}
