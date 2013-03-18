#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char *argv[] ){
	
	int i = 0;

	while( i < argc ) {
		printf( "arg at %d : %s \n", i, argv[i] );
		i++;
	} 
	return 0;
}
