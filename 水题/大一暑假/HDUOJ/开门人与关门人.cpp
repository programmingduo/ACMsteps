#include<iostream>
using namespace std;

int main ()
{
    int testCase;
    cin>> testCase;
    for(int i = 0; i < testCase; i ++)
    {
        int a;
        int first = 0, last = 0;
        string student[10000], qiandao[10000], qiantui[10000];
        cin>> a;
        for(int j = 0; j < a; j ++)
        {
            cin>> student[j]>> qiandao[j]>> qiantui[j];
        }
        for(int j = 0; j < a; j ++)
        {
            if(qiandao[j] < qiandao[first])
                first = j;
            if(qiantui[j] > qiantui[last])
                last = j;
        }
        cout<< student[first]<< " "<< student[last]<< endl;
    }
    return 0;
}
