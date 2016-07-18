/*
3487的另一种解法
因为符合要求的数不能包含3,4,7,所以符合要求的数字只能由7种数字表示，联想到7进制数
对于题目中的n，我们现在关心的是第几个7进制数==n
我们只要讲n化成7进制数就可以了，题目中的7进制数和以往不同，是不能包含3,4,7的7个数字
所以做下列变换 
0->0 1->1 2->2 3->5 4->6（因为倒着看，所以输出9） 5->8 6->9（因为倒着看，所以输出6） 
 
*/
#include <iostream>
using namespace std;
int n;
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		while(n!=0)
		{
			if(n%7==3)
				printf("5");
			else if(n%7==4)
				printf("9");
			else if(n%7==5)
				printf("8");
			else if(n%7==6)
				printf("6");
			else
				printf("%d",n%7);
			n = n/7;
		}
		printf("\n"); 
	}
	return 0;
}
