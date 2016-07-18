/*
简单计算几何题
要点: 
double型比较 注意eps的使用
计算两点之间距离
分类讨论步骤 
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int caseT;
const double eps = 1e-6;
struct Point
{
	int x,y;
}p1,p2,p3;
int dis(Point p1,Point p2)
{
	return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}
int len[3];
int main()
{
	int i;
	while(scanf("%d",&caseT)!=EOF)
	{
		for(i=1;i<=caseT;i++)
		{
			scanf("%d%d",&p1.x,&p1.y);
			scanf("%d%d",&p2.x,&p2.y);
			scanf("%d%d",&p3.x,&p3.y);
			len[0] = dis(p1,p2);
			len[1] = dis(p2,p3);
			len[2] = dis(p1,p3);
			sort(len,len+3);
			printf("Case #%d: ",i);
			if(sqrt((double)len[0])+sqrt((double)len[1]) < sqrt((double)len[2])+eps)
			{
				printf("not a triangle\n");
			}
			else
			{
				if(len[0]+len[1] == len[2])
				{
					if(len[0] == len[1])
						printf("isosceles ");
					else
						printf("scalene ");
					printf("right triangle\n");
				}
				else if(len[0]+len[1] > len[2])
				{
					if(len[0] == len[1] && len[1]==len[2])
						printf("equilateral ");
					else if(len[0] == len[1] || len[1] == len[2])
						printf("isosceles ");
					else 
						printf("scalene ");
					printf("acute triangle\n");
				}
				else
				{
					if(len[0] == len[1] || len[1] == len[2])
						printf("isosceles ");
					else 
						printf("scalene ");
					printf("obtuse triangle\n");
				}
			}
		}
	}
	return 0;
}
