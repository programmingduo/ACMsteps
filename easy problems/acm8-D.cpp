#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

int num[100], ans[10];

int comput(int a, int b, int c, int d, int e)
{
    return a-b*b+c*c*c-d*d*d*d+e*e*e*e*e;
}

int cmp(int a, int b)
{
    return a > b;
}

int main ()
{
    int target;
    string letters;
    while(~scanf("%d", &target))
    {
        cin>> letters;
        if(target == 0 && letters == "END")
            break;
        int len = letters.length();
        for(int i = 0; i < len; i ++)
        {
            num[i] = letters[i] - 'A' + 1;
        }
        sort(num, num + len, cmp);
//        for(int i =0; i < len; i ++)
//            printf("%d ", num[i]);
        int flag = 1;
        for(int i = 0; i < len && flag; i ++)
        for(int j = 0; j < len && flag; j ++)
        for(int k = 0; k < len && flag; k ++)
        for(int l = 0; l < len && flag; l ++)
        for(int m = 0; m < len && flag; m ++)
            if(comput(num[i], num[j], num[k], num[l], num[m]) == target)
            {
                if(i == j || i == k || i == l || i == m || j == k || j == l || j == m
                    || k == l || k == m || l == m)
                    continue;
                flag = 0;
                ans[0] = num[i];
                ans[1] = num[j];
                ans[2] = num[k];
                ans[3] = num[l];
                ans[4] = num[m];
            }
        if(flag)
            printf("no solution\n");
        else
        {
            for(int i = 0; i < 5; i ++)
                printf("%c", 'A' + ans[i] - 1);
            printf("\n");
        }
    }
}
