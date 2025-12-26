#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char seq[ 1000 ];
	int len;

	printf("Dose mou mia noukleotidiki allhlouxia: ");
	scanf("%s", seq);
	len = strlen( seq );

	if(len<3)
	{
		printf("Go away!\n");
		exit(1);
	}

	if(seq[ 0 ] == 'A' && seq[ 1 ] == 'T' && seq[ 2 ] == 'C' )
	{
		printf("ATC present !\n");
	}
	else
	{
		printf("ATC_not_present.\n");
	}
}

