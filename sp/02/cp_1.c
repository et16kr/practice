#include <stdio.h>

int main( int argc, char ** argv )
{
	FILE * src, *dst;
	char buff[1024];
	int ret;
    
	if ( argc != 3 )
	{
		printf( "usage : cp source dest\n" );
		return -1;
	}
	src = fopen( argv[1], "r" );
	dst = fopen( argv[2], "w" );

	while( (ret = fread( buff, 1, sizeof buff, src )))
	{
		fwrite( buff, 1, ret, dst );
	}
	fclose(src);
	fclose(dst);
	return 0;
}
