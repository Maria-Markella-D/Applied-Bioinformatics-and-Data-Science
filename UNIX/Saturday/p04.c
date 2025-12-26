#include <stdio.h>
#include <string.h>

int main()
{
	char seq[ 1000 ];
	int len;

	scanf("%s", seq);
	len = strlen( seq );
	printf("The length was : %d\n", len);
}

