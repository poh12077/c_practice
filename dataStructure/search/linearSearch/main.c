#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define n 1000 * 1000 
#define m 1000 

int arr[n];

int main(){

	srand(time(NULL));
	struct timespec begin, middle,  end;
    clock_gettime(CLOCK_MONOTONIC, &begin);
	double time;

	int i;
	for(i=0;i<n;i++){
		arr[i]=rand();
	}
	
	clock_gettime( CLOCK_MONOTONIC, &middle );
	time = (middle.tv_sec - begin.tv_sec) + (middle.tv_nsec - begin.tv_nsec) / 1000000000.0;
	printf("%lf\n", time  );
	

	for(i=0;i<m ;i++){
		int randomNum = rand(); 
		int j;
		for(j=0;j<n;j++){
			if( arr[j]==randomNum  ){
				break;
			}
		}	
	}
	
	clock_gettime( CLOCK_MONOTONIC, &end );
	time = (end.tv_sec - middle.tv_sec) + (end.tv_nsec - middle.tv_nsec) / 1000000000.0;
	printf("%lf\n", time  );

}


