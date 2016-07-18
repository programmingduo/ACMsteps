#include<iostream>
#include<cstdio>
#include<cmath>
#include<map>
using namespace std;

int paw(int a)
{
    return a * a * a;
}

int main ()
{
    int a1, a2, a3, a4, a5;
    map<int, int> hash;
    scanf("%d%d%d%d%d", &a1, &a2, &a3, &a4, &a5);
    for(int i = -50; i <= 50; i ++)
    {
        for(int j = -50; j <= 50; j ++)
        {
            if(i == 0 || j == 0)
                continue;
            int temp;
            temp = paw(i) * a1 + paw(j) * a2;
            if(hash.find(temp) == hash.end())
                hash[temp] = 1;
            else
                hash[temp] ++;
        }
    }

    int ans = 0;
    for(int i = -50; i <= 50; i ++)
    for(int j = -50; j <= 50; j ++)
    for(int k = -50; k <= 50; k ++)
    {
        if(i == 0 || j == 0 || k == 0)
            continue ;
        int temp = paw(i) * a3 + paw(j) * a4 + paw(k) * a5;
        temp = -temp;
        if(hash.find(temp) != hash.end())
            ans += hash[temp];
    }

    cout<< ans<< endl;
    return 0;
}
