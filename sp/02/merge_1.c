#include <stdio.h>

int main( int argc, char ** argv )
{
	FILE * src, *dst;
	char buff[1024];
	int ret, i;
    
	if ( argc < 4  )
	{
		printf( "usage : cp src1 src2 ... dest\n" );
		return -1;
	}
	src = fopen( argv[1], "r" );
	dst = fopen( argv[argc-1], "w" );

    for( i = 1 ; i < argc-1 ; i++ )
	{
	     src = fopen( argv[i], "r" );
		while( (ret = fread( buff, 1, sizeof buff, src )))
		{
			fwrite( buff, 1, ret, dst );
		}
		fclose(src);
	}
	fclose(dst);
	return 0;
}
