#include<iostream>
#include<map>
#include<string>
#include<set>
#include<cstdio>
using namespace std;
const int inf=1e9;
struct node
{
	int dis,val,val2;
	friend bool operator <(node a,node b)
	{
		if (a.dis==b.dis)
			return a.val<b.val;
		return a.dis>b.dis;
	}
}e;
node ne (int a,int b,int c)
{
	node e;
	e.dis=a,e.val=b,e.val2=c;
	return e;
}
map<int,string>mm;
map<string,int>num;
set<node>dis;
map<int,string>::iterator ite,ite1,ite2;
int main ()
{
	int n,a;
	string str;
	char ch[30];
	while (scanf("%d",&n),n)
	{
		dis.clear(),mm.clear(),num.clear();//Çå¿Õ
		while (n--)
		{
			scanf("%s",ch);
			if (ch[0]=='J')
			{
				scanf("%s%d",ch,&a),mm[a]=ch,num[ch]=a;
				ite=mm.find(a);
				ite1=ite2=ite;
				--ite1,++ite2;
				if (mm.size()>1)
				{
					if (ite2==mm.end())
						dis.insert(ne(ite->first-ite1->first,ite1->first,ite->first));
					else if (ite==mm.begin())
						dis.insert(ne(ite2->first-ite->first,ite->first,ite2->first));
					else
					{
						dis.insert(ne(ite2->first-ite->first,ite->first,ite2->first));
						dis.erase(ne(ite2->first-ite1->first,ite1->first,ite2->first));
						dis.insert(ne(ite->first-ite1->first,ite1->first,ite->first));
					}
				}
			}
			else if (ch[0]=='L')
			{
				scanf("%s",ch);
				ite=mm.find(num[ch]);
				ite1=ite2=ite;
				--ite1,++ite2;
				if (mm.size()>1)
				{
					if (ite2==mm.end())
						dis.erase(ne(ite->first-ite1->first,ite1->first,ite->first));
					else if (ite==mm.begin())
						dis.erase(ne(ite2->first-ite->first,ite->first,ite2->first));
					else
					{
						dis.erase(ne(ite2->first-ite->first,ite->first,ite2->first));
						dis.erase(ne(ite->first-ite1->first,ite1->first,ite->first));
						dis.insert(ne(ite2->first-ite1->first,ite1->first,ite2->first));
					}
				}
				mm.erase(num[ch]);
			}
			else
			{
				if (mm.size()<2)
					printf("Poor Mr.Yu\n");
				else
					printf("%s %s\n",mm[(--dis.end())->val2].c_str(),mm[(--dis.end())->val].c_str());
			}
		}
		printf("\n");
	}
	return 0;
}  