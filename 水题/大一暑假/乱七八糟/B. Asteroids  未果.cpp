#include<cstdio>

using namespace std;

bool chart[505][505] = {0};
int lines, points;
bool row[505], column[505];

bool solve(int total)
{
    for(int i = 1; i <= total; i ++)
        for(int j = total - i; j <= total; j ++)
        {
            if(change(i, j))
                return 1;
        }

    return 0;
}

void change(int i, int j)
{
    int xresult[505] = {0}, yresult[505] = {0};
    for(int k = 0; k < line - i; k ++)
    {
        xresult[0] = k;

    }
}

/*

int _tmain(int argc, _TCHAR* argv[])
{
  const   int   N=7,M=2;//从N个数中任取M个数的组合（M<N
  int num[M+1],s,i;

  num[1]=0;s=1;
  while(s!=0)
  {
  if(s!=M)//取小于M个数
  {
   num[s]++;

   if(num[s]>N-M+s)
   {
    s--;//回朔
   }
   else
   {
    s++;
    num[s]=num[s-1];
   }
  }
   else//取第M个数
  {
   num[s]++;

   for(i=1;i<M;i++)
    cout<<num[i]<<"-";//输出
   cout<<num[M];
   cout<<endl;

   if(num[s]==N-M+s)
    s--;//回朔
  }
  }
 return 0;
}
*/

int main ()
{
    scnaf("%d%d", &lines, &points);
    int x, y;
    for(int i =0; i< points; i ++)
    {
        scanf("%d%d", &x, &y);
        chart[x][y] = 1;
    }
    int total = 0;
    for(; total < 100000; total ++)
    if(solve(total))
        break;

    printf("%d\n", total);
    return 0;
}
