#include<iostream>

using namespace std;

int father[100000];
bool flag = 1;

void init()
{
    for(int i = 0; i < 100000; i ++)
    {
        father[i] = i;
    }
}

int find(int a)
{
    if(father[a] == a)
        return a;

    father[a] = find(father[a]);
    return father[a];
}

void merge(int a, int b)
{
    if(a != father[b] && b != father[b])
        flag = 0;
    int tempa = find(a);
    int tempb = find(b);
    if(tempa == tempb)
        flag = 0;
    father[father[b]] = tempa;
}

int main()
{
    int a, b, n = 1;
    init();
    while(cin>>a >> b && a >= 0 && b >= 0)
    {
        if(a == 0 && b == 0)
        {
            int m = 0;
            for(int i = 0; i < 10; i ++)
            {
                if(father[i] != i)
                {
                    int temp = find(i);
                    if(m == 0)
                        m = temp;
                    else
                    {
                        if(m != temp)
                            flag = 0;
                    }
                }
            }
            if(flag)
                cout<< "Case "<< n<< " is a tree." << endl;
            else
                cout<< "Case "<< n<< " is not a tree." << endl;
            flag = 1;
            init();
            n ++;
            continue;
        }
        if(!flag)
            continue ;
        merge(a, b);
    }
    return 0;
}
