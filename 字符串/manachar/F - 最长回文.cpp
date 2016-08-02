#include<cstdio>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn = 110005;
char str[maxn], str1[maxn * 2];
int dp[maxn * 2], n, maxx = 0;

void Manacher()
{
    memset(dp, 0, sizeof(dp));
    int mx = 0, id;
    for(int i = 1; i < n; i ++)
    {
        if(mx > i)
            dp[i] = min(dp[2 * id - i], mx - i);
        else
            dp[i] = 1;
        for(; str1[i - dp[i]] == str1[i + dp[i]]; dp[i] ++);
        maxx = max(maxx, dp[i]);
        if(i + dp[i] > mx)
        {
            mx = i + dp[i];
            id = i;
        }
    }
}

void pre()                                           //����str1��
{
    int i = 0, k = 1, t = 0;
    str1[0] = '$';
    while(str[i] != '\0')
    {
        str1[k ++] = t? str[i ++] : '#';
        t ^= 1;
    }
    str1[k ++] = '#';
    str1[k] = '\0';
    n = k;                   //n�Ǽ�¼str1 �ĳ��ȣ�����Ҫ��סstrlen����˼
                             //Ҳ����ÿ����n��ʱ�򶼸�ֵΪ n = 2 * strlen(str);
}

int main ()
{
    while(~scanf("%s", str))
    {
        maxx = 0;
        pre();
        Manacher();
        printf("%d\n", maxx - 1);
    }
}
