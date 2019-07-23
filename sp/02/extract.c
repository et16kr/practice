#include <stdio.h>

typedef struct
{   
    char fname[20];
    int  fsize;
} INFO;

int main( int argc, char ** argv )
{
	FILE * src, *dst;
	char buff[1024];
	int ret,len;
    INFO info;

	if ( argc != 2 )
	{
		printf( "usage : extract source\n" );
		return -1;
	}

	src = fopen( argv[1], "r" );

    while( fread( &info, sizeof(INFO), 1, src ) )
	{
	    dst = fopen( info.fname , "w" );
	
		while( info.fsize > 0 )
		{
			len = (info.fsize > sizeof(buff)) ? sizeof(buff):info.fsize;
			ret = fread( buff, 1, len, src );
			fwrite( buff, 1, ret, dst );
			info.fsize -= ret;
		}
		fclose( dst );
	}
	fclose( src );
	return 0;
}
