	// Server side C/C++ program to demonstrate Socket
	#include <netinet/in.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <sys/socket.h>
	#include <unistd.h>
	#define PORT 8080
	#include <pthread.h>
	#define maximumSocketNum 100

	void* readLoop(void *arg);
	void* sendLoop(void *arg);
	int n=0;	

	int main(int argc, char const* argv[])
	{
	    int server_fd, valread, clientSocket;
		int new_socket[maximumSocketNum];
		int k;	
		for(k=0; k< sizeof(new_socket)/4; k++){
			new_socket[k]=-1;
		}
	    struct sockaddr_in address;
	    int opt = 1;
	    int addrlen = sizeof(address);
	  
	  // Creating socket file descriptor
	    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket failed");
		exit(EXIT_FAILURE);
	    }
	  
	    // Forcefully attaching socket to the port 8080
	    if (setsockopt(server_fd, SOL_SOCKET,
			   SO_REUSEADDR | SO_REUSEPORT, &opt,
			   sizeof(opt))) {
		perror("setsockopt");
		exit(EXIT_FAILURE);
	    }
	    address.sin_family = AF_INET;
	    address.sin_addr.s_addr = INADDR_ANY;
	    address.sin_port = htons(PORT);
	  
	    // Forcefully attaching socket to the port 8080
	    if (bind(server_fd, (struct sockaddr*)&address,
		     sizeof(address))
		< 0) {
		perror("bind failed");
		exit(EXIT_FAILURE);
	    }
	    if (listen(server_fd, 3) < 0) {
		perror("listen");
		exit(EXIT_FAILURE);
	    }
		
		while(1){
			if ((clientSocket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
				perror("accept");
				exit(EXIT_FAILURE);
		   }else{
				// connection success
				while(1){
					if(new_socket[n]<0){
						if(n>maximumSocketNum){
							printf("too many socket open\n");
							exit(1);
						}
						new_socket[n]=clientSocket;
						printf("connection accepted\n");
						pthread_t thread[2];

						pthread_create(&thread[0],NULL, readLoop, (void*)&new_socket[n] );
						pthread_create(&thread[1],NULL, sendLoop , (void*)&new_socket[n]);
						n++;
						break;
					}else{
						n++;
					}
				}
			}	
		}
	  
	    // closing the listening socket
	    shutdown(server_fd, SHUT_RDWR);
	    return 0;
	}

//overflow should be fixing 
void* readLoop(void *new_socket){
	char inputStream[10]="";
	int valread;
        while(1){
			valread = read( *(int*)new_socket, inputStream, sizeof(inputStream) );
	    	if( valread >0 ){
				printf("\nfrom client: %s\n", inputStream );
			//	send(*(int*)new_socket, inputStream, strlen(inputStream), 0);
				memset(inputStream, '\0', sizeof(inputStream) );
			}else{
				printf("client has closed the connection\n");
				close(*(int*)new_socket);
				*(int*)new_socket=-1;
				n=0;
				break;
			}	
		}
}

void* sendLoop(void *new_socket){
		char outputStream[10]="";
        while(1){
        	printf("enter: ");
			scanf("%s", outputStream);	
			send(*(int*)new_socket, outputStream, strlen(outputStream), 0);
		}
}


