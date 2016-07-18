#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char str[100005];
int nextt[100005];

void getnextt(int len)
{
    int i = 0,j = -1;
    nextt[0] = -1;
    while(i<len)
    {
        if(j == -1 || str[i] == str[j])
        {
            i++;
            j++;
            nextt[i] = j;
        }
        else
            j = nextt[j];
    }
}

int main()
{
    int n;
    cin >> n;
    getchar();
    while(n--)
    {
        gets(str);
        memset(nextt,0,sizeof(nextt));
        int len = strlen(str);
        int ans;
        getnextt(len);
        ans = len - nextt[len];
        if(ans!=len && len%ans == 0)
        cout << 0 << endl;
        else
        cout << ans-nextt[len]%ans << endl;

    }

    return 0;
}
