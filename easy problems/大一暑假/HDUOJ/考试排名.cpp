#include<iostream>
#include<algorithm>

using namespace std;

struct xuesheng
{
    string name;
    int AC;
    int time;
}s[10000];

int comp(xuesheng a, xuesheng b)
{
    if(a.AC != b.AC)
        return a.AC > b.AC;
    else if(a.time != b.time)
        return a.time > b.time;
    else
        return a.name > b.name;
}

int main ()
{
    int questions, time0;
    cin>> questions>> time0;
    int i = 0;
    while(cin>> s[i].name)
    {
       for(int k = 0; k < questions; k ++)
       {
            string temp;
            cin>> temp;
            if(temp[0] != '0' && temp[0] != '-')
            {
                s[i].AC ++;
                int time = 0, j = 0;
                while(temp[j] != '(' && temp[j] != '\0')
                {
                    time = time * 10 + temp[j] - '0';
                    j ++;
                }
                s[i].time += time;
                time = 0;
                if(temp[j] == '(')
                {
                    j += 2;
                    while(temp[j] != ')')
                    {
                        time = time * 10 + temp[j] - '0';
                        j ++;
                    }
                }
                s[i].time += time * time0;
            }
       }
       i ++;
    }

    sort(s, s + i, comp);

    for(int j = 0; j < i; j ++)
    {
        cout<< s[j].name<< s[j].AC<< " "<< s[j].time<< " "<<endl;
    }
    return 0;
}
