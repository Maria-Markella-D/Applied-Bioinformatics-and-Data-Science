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
		printf("AA No.%d is %c\n", i+1, seq[i] );
	}


}

