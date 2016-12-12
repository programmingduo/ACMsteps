#include <cstdio>
#include <cstring>
char s[34];

int main ()
{
	while(~scanf("%s", s))
	{
		if(s[0] == '#')
			break;
		int total = 0;
		int len = strlen(s);
		for(int i = 0; i < len  - 1; i ++)
			if(s[i] == '1')
				total ++;
		if(total % 2 && s[len - 1] == 'e' || total % 2 == 0 && s[len - 1] == 'o')
			s[len - 1] = '1';
		else 
			s[len - 1] = '0';
		printf("%s\n", s);
	}
	return 0;
}