#include<cstdio>
#include<cstring>

int main ()
{
    int T;
    char a[100005], b[100006];
    scanf("%d", &T);
    while(T --)
    {
        scanf("%s %s", a, b);
        int i = 0, j = 0;
        if(a[0] == b[0])
        {
            while(a[i ++] == a[0]);
            while(b[j ++] == b[0]);
            if(i < j)
            {
                printf("No\n");
                continue;
            }
            i --, j --;
            int al = strlen(a), bl = strlen(b);
            for(; i < al; i ++)
            {
                for(; j < bl; j ++)
                {
                    if(a[i] == b[j])
                        break;
                }
                if(j == bl)
                    break;
            }
            if(i == al)
                printf("Yes\n");
            else
                printf("No\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
