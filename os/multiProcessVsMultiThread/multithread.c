#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define n 10000 * 10000 * 20
#include <time.h>

void *p_function(void * data)
{
	unsigned long i;
	for(i=0; i< n; i++){
		
	}  
	printf("%d\n",i);
}


int main(void)
{
	struct timespec begin, end;  
	clock_gettime(CLOCK_MONOTONIC, &begin);

	pthread_t pthread;
	pthread_create(&pthread, NULL, p_function, NULL ); 
	p_function(NULL);
	pthread_join(pthread, NULL ); //6

	clock_gettime(CLOCK_MONOTONIC, &end);
	
	double time = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec)/ 1000000000.0  ;

	printf("%lf\n",  time  );

	return 0;
}
