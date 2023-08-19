#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"


void clearReadBuffer(void){
    while(getchar() != '\n'){
		printf("%c\n", getchar() );
	}
}

void ask(NODE* entry){
	int answer;
	while(1){
		printf("\n1. add at the end\n");
		printf("2. insert\n");
		printf("3. delete\n");
		printf("4. travesal\n");
		printf("select :");
		scanf("%d", &answer);
		clearReadBuffer();	
		
		switch(answer){
			case 1:
				addAtTheEnd(entry);
				break;
			case 2:
				insertNode(entry);
				break;
			case 3:
				deleteNode(&entry);
				break;
			case 4:
				traversal(entry);
				break;
			default:
				printf("wrong number\n");
		}
	}	
}


void insertNode(NODE* entry){
	NODE* ptr =(NODE*)malloc( sizeof(NODE) );
	ptr->header = NULL;

	int nodeNum=0;	
	printf("which node do you wanna insert? (enter node number)");
	scanf("%d",&nodeNum);  
	clearReadBuffer();
	printf("enter data: ");
	scanf("%s", &ptr->payload );  
	clearReadBuffer();
				
	int i;
	for(i=0;i<nodeNum-1;i++){
		entry = entry->header;
	}
	
	ptr->header = entry->header;
	entry->header = ptr;
}

void deleteNode(NODE** entry){
	int nodeNum=0;	
	printf("which node do you wanna delete? (enter node number)");
	scanf("%d",&nodeNum);  
//	clearReadBuffer();
	
	if(nodeNum==1){
		NODE* nodeP = *entry;
		if(nodeP->header==NULL){
			free(nodeP);
			*entry=NULL;
		}else{
			*entry = (*entry)->header;
			free(nodeP);
		}
	}else if(nodeNum>1){
		NODE* entryCopy=*entry;
		int i;
		for(i=0;i<nodeNum-2;i++){
			entryCopy = entryCopy->header;
		}
		
		NODE* nodeP = entryCopy->header;
		if(nodeP->header==NULL){
			free(nodeP);
			entryCopy->header = NULL;
		}else{
			entryCopy->header = nodeP->header;
			free(nodeP);
		}
	}else{
		printf("node number should be greater than 1");
	}		
				
}

void makeFirstNode(NODE** entry){
	NODE * ptr = (NODE*)malloc( sizeof(NODE) );
	ptr->header = NULL;
	printf("enter data: ");
	scanf("%s", &ptr->payload );
	getchar();
	*entry = ptr; 
}

void addAtTheEnd(NODE* entry){
	while(1){
		if( entry -> header == NULL ){
			NODE * ptr = (NODE*)malloc( sizeof(NODE) );
			ptr->header = NULL;
			printf("enter data: ");
			scanf("%s", &ptr->payload );
			getchar();

			entry->header = ptr;
			break; 	
		}else{
			entry = entry->header;
		}
	}
}

void traversal(NODE* entry){
	NODE* ptr = entry;
	if(ptr==NULL){
		return;
	}
	while(1){
		if( ptr->header == NULL ){
			printf("%s\n", ptr->payload);
			break;
		}else{
			printf("%s\n", ptr->payload);
		}
		ptr = (NODE*)ptr->header;
	}
}

