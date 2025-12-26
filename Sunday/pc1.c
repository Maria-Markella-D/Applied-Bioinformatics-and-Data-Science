#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char seq[ 1000 ];
	int len;
	int i, charge=0;

	scanf("%s", seq);
	len = strlen( seq );
	printf("The length was : %d\n", len);

	for( i=0 ;  i < len ; i++ )
	{
		if(seq[ i ] == 'K' || seq[ i ] == 'R' )
		{
			charge++;
		}
		if(seq[ i ] == 'D' || seq[ i ] == 'E' )
		{
			charge--;
		}
	}

	printf("The total charge is: %d\n", charge);
}

