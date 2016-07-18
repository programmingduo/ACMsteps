#include<cstdio>
#include<map>

using namespace std;

map<int, int> i;

char s[1005];

int standard(char *s)
{
    int t = 0;
    char c;
    for(int i = 0, len = 0; s[i]; i ++)
    {
        if(s[i] == '-' || s[i] == 'Q' || s[i] == 'Z')
            continue;
        if(s[i] >= '0' && s[i] <= '9')
            t = t * 10 + s[i] - '0';
        else
        {
            switch(s[i])
            {
            case 'A': case 'B': case 'C':
                c = '2';
                break;
            case 'D': case 'E': case 'F':
                c = '3';
                break;
            case 'G': case 'H': case 'I':
                c = '4';
                break;
            case 'J': case 'K': case 'L':
                c = '5';
                break;
            case 'M': case 'N': case 'O':
                c = '6';
                break;
            case 'P': case 'R': case 'S':
                c = '7';
                break;
            case 'T': case 'U': case 'V':
                c = '8';
                break;
            case 'W': case 'X': case 'Y':
                c = '9';
                break;
            default:
                continue;
            }
            t = t* 10 + c - '0';
        }
    }
    return t;
}

int main ()
{
    int n;
    scanf("%d", &n );
    while(n --)
    {
        scanf("%s", s);
//        printf("%d\n", standard(s));
        i[standard(s)] ++;
    }
    map<int, int>::iterator it;
    int flag = 0;
    for(it = i.begin(); it != i.end(); it++)
    {
        if(it->second > 1)
        {
            printf("%03d-%04d %d\n", it->first / 10000, it->first % 10000, it->second);
            flag = 1;
        }
    }
    if(!flag)
        puts("No duplicates.");
    return 0;
}
