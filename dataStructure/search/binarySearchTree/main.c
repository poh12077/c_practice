#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define n 1000 * 1000
#define m 1000 * 1000

typedef struct Node{
	int data;
 	struct Node* lNode;
 	struct Node* rNode;
}Node;

void insert(Node* root, int data);
void compare(Node* node, Node* newNode);
void checkRight(Node* node, Node* newNode );
void checkLeft(Node* node, Node* newNode );
void search(Node* node, int data);

int main(){

	srand(time(NULL));

	Node root;
	root.data=rand();
	root.lNode=NULL;
	root.rNode=NULL;


	struct timespec begin, middle,  end;
    clock_gettime(CLOCK_MONOTONIC, &begin);
	double time;

	int randomNum;
	int i;
	for(i=0;i<n ;i++){
		randomNum = rand(); 
		insert( &root, randomNum );
	}
	
	clock_gettime( CLOCK_MONOTONIC, &middle );
	time = (middle.tv_sec - begin.tv_sec) + (middle.tv_nsec - begin.tv_nsec) / 1000000000.0;
	printf("%lf\n", time  );

	for(i=0;i< m ;i++){
		randomNum = rand(); 
		search( &root, randomNum );
	}
	
	clock_gettime( CLOCK_MONOTONIC, &end );
	time = (end.tv_sec - middle.tv_sec) + (end.tv_nsec - middle.tv_nsec) / 1000000000.0;
	printf("%lf\n", time  );

}

void search(Node* node, int data){
	static int layer;
	if(node->data == data){
		//printf("%d is founded in %d layer\n", node->data, layer);
		layer=0;
	}else if(node->data < data){
		if( node->rNode != NULL){
			layer++;
			search(node->rNode, data);
		}else{
		//	printf("no %d in this tree\n", data);
		}	
	}else{
		if( node->lNode != NULL){
			layer++;
			search(node->lNode, data);
		}else{
		//	printf("no %d in this tree\n", data);
		}	
	}
}

void insert(Node* root, int data){
	Node* node = (Node*)malloc( sizeof(Node) );
	node->data = data;
	node->lNode = NULL;
	node->rNode = NULL;

	compare( root, node );
}


void compare(Node* node, Node* newNode){
	if( node->data < newNode->data ){
		checkRight( node, newNode);
	}else if( node->data > newNode->data  ){
		checkLeft( node, newNode);
	}else{
	//	printf("same data(%d) is not allowed\n", node->data);
	}
}

void checkRight(Node* node, Node* newNode ){
	if(node->rNode == NULL ){
		node->rNode = newNode;
	}else{
		compare( node->rNode, newNode );
	}
}

void checkLeft(Node* node, Node* newNode ){
	if(node->lNode == NULL ){
		node->lNode = newNode;
	}else{
		compare( node->lNode, newNode );
	}
}
