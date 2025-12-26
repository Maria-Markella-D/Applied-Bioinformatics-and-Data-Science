#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char seq[ 1000 ];
	char penta[ 100 ];
	int len1, len2;
	int i;


	printf("Enter the target sequence: ");
	scanf("%s", seq);
	len1 = strlen( seq );
	printf("Enter the pentapeptide: ");
	scanf("%s", penta );
	len2= strlen( penta );
	printf("The length of the target sequence was : %d\n", len1);

	if( len1 < 5 )
	{
		printf("Eisai boubounas!\n");
		exit(1);
	}

	if( len2 != 5 )
	{
		printf("Eisai bobounas!\n");
		exit(1);
	}

	for( i=0 ;  i < len1-4 ; i++ )
	{
		if(	seq[ i   ] == penta[ 0 ] &&
			seq[ i+1 ] == penta[ 1 ] &&
			seq[ i+2 ] == penta[ 2 ] &&
			seq[ i+3 ] == penta[ 3 ] &&
			seq[ i+4 ] == penta[ 4 ] )
		{
			printf("Found it at %d\n", i+1);
		}
	}


}

