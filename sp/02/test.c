#include <stdio.h>

int get_width( int num );

int main( int argc, char ** argv )
{
	FILE * fp;
	int width = 0,w, i;
	int ch,flag=0;
	int cnt[3] = {0,} ;

	fp = fopen( argv[1], "r" );

	while( (ch = fgetc( fp )) != EOF )
	{
		if( ch == '\n')
			cnt[0]++;
		cnt[2]++;
		if (( ch != '\n') && (ch != ' ') && ( ch != '\t' ) )
		{
			if ( flag == 0) 
			{
				flag = 1;
				cnt[1]++;
			}
		}
		else
		{
			flag = 0;
		}
	}

	for( i = 0 ; i < 3 ; i++)
	{
		w = get_width( cnt[i] );
		if ( width < w )
			width = w;
	}

	printf("%*d %*d %*d %s\n",width, cnt[0], width,cnt[1], width,cnt[2],  argv[1]);
	fclose(fp);
	return 0;
}

int get_width( int num )
{
	int i;

	for(i = 0 ; num!= 0 ; i++ )
	{
		num /= 10;
	}
	return i;
}
