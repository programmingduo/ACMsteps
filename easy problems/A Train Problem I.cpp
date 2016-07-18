#include<iostream>
#include<stack>
using namespace std;

int main ()
{
    int cases;
    while(cin>> cases)
    {
        bool ans[20];
        stack<char> train;
        char trainin[10], trainout[10];
        cin>> trainin>> trainout;
        int n = 0, m = 0, out = 0;
        for(int i = 0; i < cases; i ++)
        {
            train.push(trainin[i]);
            ans[m ++] = 1;
            while(train.top() == trainout[n])
            {
                ans[m ++] = 0;
                train.pop();
                out ++;
                n ++;
                if(train.empty())
                    break;
            }
        }
        if(out == cases)
        {
            cout<< "Yes."<< endl;
            for(int i = 0; i < cases * 2; i ++)
            {
                if(ans[i])
                    cout<< "in"<< endl;
                else
                    cout<< "out"<< endl;
            }
        }
        else
            cout<< "No."<< endl;

        cout<< "FINISH"<< endl;
    }
}
