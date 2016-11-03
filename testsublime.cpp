#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

int a[10];
stack<int> s;

int main ()
{
	int T, n;
	scanf("%d", &T);
	while(T --)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++)
		{
			a[i] = i;
		}
		do
		{
			while(!s.empty())
				s.pop();
			// printf("1");
			int flag = 1;
			for(int i = 1, j = 1; i <= n ||	 j <= n;)
			{
				// printf("%d %d\n", i, j);
				if(i <= a[j])
				{
					s.push(i);
					i ++;
				}
				else if(!s.empty() && s.top() == a[j])
				{
					s.pop();
					j ++;
				}
				else
				{
					flag = 0;
					break;
				}
			}
			if(flag == 1)
			{
				for(int i = 1; i < n; i ++)
				{
					printf("%d", a[i]);
				}
				printf("%d\n", a[n]);
			}
		}while(next_permutation(a + 1, a + 1 + n));
	}
	return 0;
}

