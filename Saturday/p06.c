#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char seq[ 1000 ];
	int len;

	scanf("%s", seq);
	len = strlen( seq );
	printf("The length was : %d\n", len);
	if(len < 5 )
	{
		printf("Eisai boubounas!\n");
		exit(1);
	}
}

