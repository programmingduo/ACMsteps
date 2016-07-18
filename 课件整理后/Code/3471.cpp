/*
找规律，其实是博弈的思想 
*/
#include <iostream>
using namespace std;
int main()
{
	int n;
	while(scanf("%d",&n)&&n)
	{
		if(n%3==0)
			printf("Unhappy\n");
		else
			printf("Happy\n");
	}
	return 0;
}
