#include<stdio.h>
#include<add.h>

void * foo( void * data )
{
	int ret;
	ret = add( 3,4);
	printf("foo(), ret=%d\n", ret );
	return 0;
}


int main()
{
	foo(NULL);
	return 0;
}
