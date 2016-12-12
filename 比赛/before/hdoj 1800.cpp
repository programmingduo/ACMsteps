#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct node 
{
	char num[34];
}inp[3004];

int cmp(node a, node b)
{
	if(strcmp(a.num, b.num) < 0)
		return 0;
	return 1;
}

int main ()
{
	int  N;
	char temp[34];
	while(~scanf("%d", &N))
	{
		int ans = 1;
		for(int i = 0; i < N; i ++)
		{
			scanf("%s", temp);
			int len = strlen(temp);
			for(int j = 0; j <= 30 - len; j ++)
			{
				inp[i].num[j] = '0';
			}
			for(int j = 32 - len + 1, k = 0; j <= 32; j ++, k ++)
				inp[i].num[j] = temp[k];
		}
		sort(inp, inp + N, cmp);

		int now = 1;
		for(int i = 1; i < N; i ++)
		{
			if(strcmp(inp[i].num, inp[i - 1].num) == 0)
				now ++;
			else
			{
				ans = max(ans, now);
				now = 1;
			}
		}
		ans = max(ans, now);
		printf("%d\n", ans);
	}
}