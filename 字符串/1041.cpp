#include<cstdio>
#include<cstring>

using namespace std;

int main ()
{
    int i;
    scanf("%d", &i);
    while(i --)
    {
        char a[205];
        scanf("%s", a);
        int temp = strlen(a);
        for(int j = 0; j < temp; j ++)
        {
            if(a[j] == '\\' || a[j] == '"')
            {
                for(int k = ++temp; k > j; k --)
                {
                    a[k] = a[k - 1];
                }
                a[j ++] = '\\';
            }
            else if(a[j] == '%')
            {
                for(int k = ++temp; k > j; k --)
                {
                    a[k] = a[k - 1];
                }
                a[j ++] = '%';
            }
        }
        printf("%s\n", a);
    }
    return 0;
}
