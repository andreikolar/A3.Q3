#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE
{
	char value[65];
	struct NODE* next;
}aNode;

void printNodes(aNode* my_node){
	printf(" %s ", my_node->value);
	if (my_node->next != NULL){
		printNodes(my_node->next);
	}
}


void printLinkedList(aNode* list){
	if (list != NULL){
		printf("Content of list is :");
		printNodes(list);
	}else{
		printf("List is empty.");
	}
	printf("\n");
}

aNode* addToLinkedList(aNode* list, char value[],int counter){
	aNode* freeSpot;
	aNode* newNode;

	freeSpot=list;
	
	if (counter==0){
		newNode=(aNode *)malloc(sizeof(aNode));
		strcpy(newNode->value,value);
		newNode->next=NULL;
		list=newNode;
		return list;
	}else{

		while(freeSpot->next != NULL){	
			freeSpot=freeSpot->next;
		}
	
		newNode=(aNode *)malloc(sizeof(aNode));
		strcpy(newNode->value,value);
		newNode->next = NULL;
		freeSpot->next = newNode;

		return list;
	}
}

//#define FRENCH
#define ENGLISH	
aNode* head=NULL;

main(){
	int looper=1;
	int count=0;
	char array[65];
	
	#ifdef FRENCH
		printf("Bonjour a le program");
	#else
		printf("Welcome to the infinite string storage program.\n");
	#endif
	
	while (looper==1){
		#ifdef FRENCH
			printf("Entrez-vous un mot s'il vous plait: ");
		#else
			printf("Please input a single word: ");
		#endif
		scanf("%s",array);
		if ( (strcmp(array,"***END***"))==0 ){
			printLinkedList(head);
			exit(0);
		}else{
			head=addToLinkedList(head,array,count);
			memset(array,'\0',65);
		}
		count +=1;
	}
}	
