#include <iostream>
using namespace std;
#define maxn 25
struct Name
{
	int hp,str,spd;
};//姓名结构体 
char s1[maxn];
char s2[maxn];
//根据姓名计算姓名属性 
Name turn(char name_str[])
{
	Name tmp;
	int sum1,sum2,sum3,i,j;
	int len = strlen(name_str);
	sum1 = 0; sum2 = 1; sum3 = 0;
	for(i=0;i<len;i++)
	{
		sum1 = (sum1 + ((83-name_str[i])*(83-name_str[i]))%97)%97;
	}
	for(i=0;i<len;i++)
	{
		sum2 = (name_str[i]*sum2)%79;
	}
	for(i=0;i<len;i++)
	{
		for(j=i+1;j<len;j++)
		{
			sum3 = (sum3 + (name_str[i]*name_str[j])%11)%11;
		}
	}
	tmp.hp = 300 - sum1;
	tmp.str = 22 + sum2;
	tmp.spd = sum3;
	return tmp;
}
int main()
{
	int n;
	Name name1,name2;
	int cnt1,cnt2,t1,t2;//攻击次数和时间 
	while(scanf("%d",&n)!=EOF)
	{
		while(n--)
		{
			scanf("%s%s",&s1,&s2);
			name1 = turn(s1);
			name2 = turn(s2);
			//考虑name1击败name2的时间t1
			if(name2.hp%name1.str == 0)
				cnt1 = name2.hp/name1.str;
			else
				cnt1 = name2.hp/name1.str + 1;
			t1 = cnt1 * (20 - name1.spd);
			//考虑name2击败name1的时间t2 
			if(name1.hp%name2.str == 0)
				cnt2 = name1.hp/name2.str;
			else
				cnt2 = name1.hp/name2.str + 1;
			t2 = cnt2 * (20 - name2.spd);
			//根据两个人击败对方时间的先后判断胜负情况 
			if(t1 > t2)
				printf("lose\n");
			else if(t1 < t2)
				printf("win\n"); 
			else
				printf("tie\n");
		}
	}
	return 0;
}
