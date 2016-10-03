#include <cstdio>
#include <string.h>

int ans[10005];
char s[204];

int main()
{
	int n, total = 0;
	scanf("%d", &n);
	scanf("%s", s);
	for(int i = 0; i < n; i ++)
	{
		if(s[i] == 'B')
		{
			while(s[i] =='B')
			{
				i ++;
				ans[total] ++;
			}
			total ++;
		}
	}
	printf("%d\n", total);
	for(int i = 0; i < total; i ++)
	{
		if(i)
			printf(" ");
		printf("%d", ans[i]);
	}
	if(total)
		printf("\n");
	return 0;
}