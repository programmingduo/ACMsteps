#include <stdio.h>
int main()
{
	char a[200][201];
	int x, y;
	int i, j, k;
	char c;
	int flag;
	char b[50000]; // 开得不够大啊

	scanf("%d%d", &x, &y);
	// x,y反了……
	k = x;
	x = y;
	y = k;
	getchar();
	while (gets(b))
	{
		flag = 0;
		i = 0;
		j = 0;
		k = 0;

		do
		{
			c = b[k];
			if (c >= 'a'&&c <= 'z')
			{
				if (i == x)
				{
					i = 0;
					j += 1;
				}
				a[i][j] = c - 32;
				i++;
			}
			else if (c >= 'A'&&c <= 'Z')
			{
				if (i == x)
				{
					i = 0;
					j += 1;
				}
				a[i][j] = c;
				i++;
			}
			k++;
		} while (b[k] != '\0');

		if (j<(y - 1) || i != x)
		{
			if (i == x)
			{
				i = 0;
				j += 1;
			}
			for (; j < y; j++)
			{
				for (; i < x; i++)
				{
					a[i][j] = 'A' + flag;
					flag++;
					if (flag == 26)
						flag = 0;
				}
				i = 0;
			}
		}

		for (i = 0; i < x; i++)
			a[i][y] = '\0'; // 是a[i][y]！！！！不是a[i][x]
		for (i = 0; i < x; i++)
			printf("%s", a[i]);
		printf("\n");
	}
}
