#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char seq[ 1000 ];
	int len;
	int i;
	float GC = 0;

	scanf("%s", seq);
	len = strlen( seq );
	printf("The length was : %d\n", len);

	for( i=0 ;  i < len ; i++ )
	{
		if(seq[ i ]== 'G' || seq[ i ] == 'C' )
		{
			GC++;
		}

	}

	printf("The GC content is: %f\n", 100.0* GC/len);
}

