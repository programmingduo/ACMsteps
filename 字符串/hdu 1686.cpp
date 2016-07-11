#include<cstdio>
#include<cstring>

using namespace std;

char word[10005], text[1000010];
int next[10005];

void get_next()
{
    int len = strlen(word);
    next[0] = -1;
    for(int i = 1;  i< len; i ++)
    {
        int j = next[i - 1];
        while(j >= 0 && word[j + 1] != word[i])
        {
            j = next[j];
        }
        if(word[j + 1] == word[i])
            next[i] = j + 1;
        else
            next[i] = -1;
    }
}

int solvee()
{
    int cnt = 0;    //´¢´æ´ð°¸¸öÊý
    int i = 0, j = 0;
    int lenp = strlen(word);
    int lens = strlen(text);

    while(i <= lens)
    {
        if(i == lens)
        {
            if(j == lenp)
                cnt ++;
            break;
        }
        if(text[i] == word[j])
            i ++, j ++;
        else
        {
            if(j == 0)
                i ++;
            else
                j = next[j- 1] + 1;
        }
        if(j >= lenp)
        {
            cnt ++;
            j = next[lenp - 1] + 1;
        }
    }
    return cnt;
}

int main ()
{
    int k;
    scanf("%d", &k);
    while(k --)
    {
        scanf("%s%s", word, text);
        get_next();
        int ans = solvee();
        printf("%d\n", ans);
    }
    return 0;
}
