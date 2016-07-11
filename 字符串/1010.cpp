#include<cstdio>
#include<cstring>

using namespace std;

int main ()
{
    int l, n;
    scanf("%d%d", &l, &n);
    char special[25][25], specials[25][25];
    for(int i = 0; i < l; i ++)
    {
        scanf("%s%s", special[i], specials[i]);
    }

    char word[25];
    for(int i = 0; i < n; i ++)
    {
        scanf("%s", word);
        int temp = strlen(word), flag = 0, ans = 0;
        temp --;
        for(int j = 0; j < l; j ++)
        {
            if(strcmp(word, special[j]) == 0)
            {
                flag = 1;
                ans = j;
                break;
            }
        }
        if(flag)
        {
            printf("%s\n", specials[ans]);
            continue;
        }

        if(word[temp] == 'y' && (word[temp - 1] != 'a' && word[temp - 1] != 'e' && word[temp - 1] != 'o'
                                 && word[temp - 1] != 'u' && word[temp - 1] != 'i'))
        {
            word[temp ++] = 'i';
            word[temp ++] = 'e';
            word[temp ++] = 's';
            word[temp] = '\0';
        }
        else if(word[temp] == 'o' || word[temp] == 's' || word[temp] == 'x' ||
                (word[temp] == 'h' && (word[temp - 1] == 'c' || word[temp - 1] == 's')))
        {
            word[++temp] = 'e';
            word[++temp] = 's';
            word[++temp] = '\0';
        }
        else
        {
            word[++temp] = 's';
            word[++temp] = '\0';
        }
        printf("%s\n", word);
    }
    return 0;
}
