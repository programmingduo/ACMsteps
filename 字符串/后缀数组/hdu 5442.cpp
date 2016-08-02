#include<cstdio>



int main ()
{
    int t, n;
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d", &n);
        scanf("%s", word);
        for(int i = 0; i < n; i ++)
        {
            r[i] = r[i + n] = word[i];
        }

        int len = n* 4 + 1;
        r[n * 2] = '#';
        for(int i = 0; i < n; i ++)
        {
            r[i + n * 2 + 1] = r[i + n * 3 + 1] = word[n - i - 1];
        }
        r[len] = 0;


    }
}
