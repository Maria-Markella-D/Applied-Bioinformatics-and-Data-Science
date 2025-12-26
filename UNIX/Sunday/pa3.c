#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char seq[ 1000 ];
	char penta[ 100 ];
	int len1, len2;
	int i, k, found_it;


	printf("Enter the target sequence: ");
	scanf("%s", seq);
	len1 = strlen( seq );
	printf("Enter the search sequence: ");
	scanf("%s", penta );
	len2= strlen( penta );
	printf("The length of the target sequence was : %d\n", len1);

	if( len1 < len2 )
	{
		printf("Eisai boubounas!\n");
		exit(1);
	}


	for( i=0 ;  i < len1-(len2-1) ; i++ )
	{
		found_it = 1;
		for( k=0 ; k < len2 ; k++ )
		{
			if(seq[ i+k ] != penta[ k ])
			{
				found_it = 0;
			}
		}

		if( found_it ==1 )
		{
			printf("Found it at %d\n", i+1 );
		}

	}


}

