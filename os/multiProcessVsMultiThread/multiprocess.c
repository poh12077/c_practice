
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define n 10000 * 10000 * 20
#include <time.h>


int main(){

	struct timespec begin, end;
    clock_gettime(CLOCK_MONOTONIC, &begin);
	
	pid_t pid = fork();

	unsigned long i;
	for(i=0;i<n;i++){
	}
	
	printf( "%d\n", i );
	
	if(pid !=0){
		wait();
    	clock_gettime( CLOCK_MONOTONIC, &end);
    	double time = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0;

    	printf("%lf\n", time  );
	}
}

