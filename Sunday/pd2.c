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

	if(seq[ len-1 ] == 'T' && seq[ len-2 ] == 'A' && seq[ len-3 ] == 'A' )
	{
		printf("Last triplet is TAA!\n");
	}
	else
	{
		printf("Last triplet is not TAA\n");
	}
}

