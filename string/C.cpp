#include<cstdio>
#include<vector>
#include<string.h>
using namespace std;

char s[100005];
vector<int> v[100];
int total[100];

int getindex(char c)
{
    if(c >= 'a')
        return c - 'a' + 26;
    return c - 'A';
}

int main()
{
    int n;
    scanf("%d", &n);
    scanf("%s", s);

    for(int i = 0; i< 52; i ++)
        v[i].clear();

    for(int i = 0; i < n; i ++)
    {
        v[getindex(s[i])].push_back(i+1);
    }


    memset(total, 0, sizeof(total));
    int r = 0, l = 1;
    for(int i = 0; i < 52; i ++)
    {
        if(v[i].size())
        {
            r = max(r, v[i][0]);
            total[i] ++;
        }
    }

    int ans = r - l + 1;
    for(int i = l - 1; i < n; i ++)
    {
        int id = getindex(s[i]);
        int temp = total[id] ++;
        if(temp >= v[id].size())
            break;
        l ++;
        if(v[id][temp] > r)
            r = v[id][temp];
        ans = min(ans, r - l + 1);
    }
    printf("%d\n", ans);
    return 0;
}
