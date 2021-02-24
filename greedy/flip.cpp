#include <stdio.h>
#include <string.h>

char s[1000006];

int main()
{
	int ret = 1;

	scanf(" %s", s);
	
	for (int i = 0; i < strlen(s) - 1; i++)
		if (s[i] != s[i + 1])
			ret++;

	ret /= 2;
	printf("%d\n", ret);
	return 0;
}
