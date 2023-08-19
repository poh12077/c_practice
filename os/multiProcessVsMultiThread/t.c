#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define n 10000 * 10000 * 2
#include <time.h>




int main(void)
{
	struct timespec begin, end;  
	//clock_gettime(CLOCK_MONOTONIC, &begin);
	clock_gettime(CLOCK_REALTIME, &begin);

	sleep(2);

	//clock_gettime(CLOCK_MONOTONIC, &end);
	clock_gettime(CLOCK_REALTIME, &end);
	
	//long time = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec);
	//long time = (end.tv_sec - begin.tv_sec) ;
	double time = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;

	printf("%lf\n", time  );
	//printf("%ld\n",  time  );

	return 0;
}
