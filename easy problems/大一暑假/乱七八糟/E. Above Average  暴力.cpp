#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

int main ()
{
    int n;
    scanf("%lld", &n);
    for(int i = 0; i < n; i ++)
    {
        int student;
        double total = 0, ans = 0;
        int grades[1001];
        cin>> student;
        //scanf("%lld", &student);
        for(int j = 0; j < student; j ++)
        {
            cin>> grades[j];
            //scanf("%lld", &grades[j]);
            total += grades[j];
        }
        double ave = total / student;
        for(int j = 0; j < student; j ++)
        {
            if(grades[j] > ave)
                ans ++;
        }

        ans /= student;
        printf("%.3lf", ans * 100);
        cout<< "%"<< endl;
    }
    return 0;
}
