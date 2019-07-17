#include <stdio.h>

int main( int argc, char ** argv )
{
	FILE * fp;
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

	printf(" %d %d %d %s\n", cnt[0], cnt[1], cnt[2],  argv[1]);
	fclose(fp);
	return 0;
}
