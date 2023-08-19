#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define n 1000 * 100 

int main()
{
	pid_t pid = fork();

	FILE *fptr;
	fptr = fopen("/root/src/multiprocessTest/text.log","a");

	if(fptr == NULL)
	{
	  printf("Error!");   
	  exit(1);             
	}
	
	if(pid!=0){
		fprintf(fptr,"parent start\n");
		int i;
		for(i=0;i<n;i++){
			fprintf(fptr,"a");
		}
		fprintf(fptr,"parent done\n");

	}else{
		fprintf(fptr,"child start\n");
		int i;
		for(i=0;i<n;i++){
			fprintf(fptr,"b");
		}
		fprintf(fptr,"child done\n");
	}
	fclose(fptr);

	return 0;
}
