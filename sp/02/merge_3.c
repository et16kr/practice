#include <stdio.h>
#include <string.h>

typedef struct
{
	char fname[20];
	int  fsize;
} INFO;

int main( int argc, char ** argv )
{
	FILE * src, *dst;
	char buff[1024];
	int ret, i;
    INFO info;

	if ( argc < 4  )
	{
		printf( "usage : cp src1 src2 ... dest\n" );
		return -1;
	}
	dst = fopen( argv[argc-1], "w" );

    for( i = 1 ; i < argc-1 ; i++ )
	{
		src = fopen( argv[i], "r" );
		info.fsize = 6;
		strcpy(info.fname, argv[i]);
		fwrite(&info, sizeof(INFO), 1, dst);
		while( (ret = fread( buff, 1, sizeof buff, src )))
		{
			fwrite( buff, 1, ret, dst );
		}
		fclose(src);
	}
	fclose(dst);
	return 0;
}
