#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int flag[200][200];
string ele[] = {
"H","He","Li","Be","B","C","N","O","F","Ne",
"Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca",
"Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn",
"Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr",
"Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn",
"Sb","Te","I","Xe","Cs","Ba","Hf","Ta","W","Re",
"Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At",
"Rn","Fr","Ra","Rf","Db","Sg","Bh","Hs","Mt","Ds",
"Rg","Cn","Fl","Lv","La","Ce","Pr","Nd","Pm","Sm",
"Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Ac",
"Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es",
"Fm","Md","No","Lr"
};

void init()
{
    int temp1, temp2;
    for(int i = 0; i < 114; i ++)
    {
        if(ele[i].length() == 1)
            temp1 = ele[i][0] - 'A' + 1, temp2 = 0;
        else if(ele[i].length() == 2)
            temp1 = ele[i][0] - 'A' + 1, temp2 = ele[i][1]- 'a' + 1;
        flag[temp1][temp2] = 1;

    }
}

int main ()
{

    memset(flag, 0, sizeof(flag));
    init();
    string temp;
    int T, tempn, tempn0, dp[50005];
    scanf("%d", &T);
    while(T --)
    {
        memset(dp, 0, sizeof(dp));
        cin>> temp;
        int len = temp.length();
        tempn = temp[0] - 'a' + 1;
        if(flag[tempn][0])
            dp[0] = 1;
        if(len > 1)
        {
            tempn0 = temp[1] - 'a' + 1;
            if(flag[tempn][tempn0])
                dp[1] = 1;
        }
        for(int i = 0; i < len - 1; i ++)
        {
            if(!dp[i])
                continue;
            tempn = temp[i + 1] - 'a' + 1;
            if(flag[tempn][0])
                dp[i + 1] = 1;
            if(i + 2 < len)
            {
                tempn0 = temp[i + 2] - 'a' + 1;
                if(flag[tempn][tempn0])
                    dp[i + 2] = 1;
            }

        }
        if(!dp[len - 1])
            printf("NO\n");
        else
            printf("YES\n");

    }

    return 0;
}
