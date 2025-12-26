#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char seq[ 1000 ];
	int len;
	int i;

	scanf("%s", seq);
	len = strlen( seq );
	printf("The length was : %d\n", len);
	if(len < 5 )
	{
		printf("Eisai boubounas!\n");
		exit(1);
	}


	for( i=0 ;  i < len ; i++ )
	{
		if(	seq[ i   ] == 'F' &&
			seq[ i+1 ] == 'L' &&
			seq[ i+2 ] == 'A' &&
			seq[ i+3 ] == 'R' &&
			seq[ i+4 ] == 'E')
		{
			printf("Found it at %d\n", i+1);
		}
	}


}

