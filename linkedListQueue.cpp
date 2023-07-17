#include <stdio.h>
#include <stdlib.h>

typedef struct n{
	int data;
	n *next;
}node;

void addDataQueue(node **,int);
void printData(node *);


int main(){
	node *root=NULL;
	addDataQueue(&root,45);
	addDataQueue(&root,30);
	addDataQueue(&root,67);
	addDataQueue(&root,84);
	addDataQueue(&root,56);
	addDataQueue(&root,73);
	addDataQueue(&root,21);
	addDataQueue(&root,19);
	addDataQueue(&root,13);
	addDataQueue(&root,15);
	addDataQueue(&root,20);
	addDataQueue(&root,12);
	addDataQueue(&root,19);
	printData(root);
	return 0;
}

void addDataQueue(node ** root,int data){
	if(*root==NULL){ 
		*root=(node*)malloc(sizeof(node));
		(*root)->next=NULL;
		(*root)->data=data;				
	}
	
	else if((*root)->next==NULL){
		if((*root)->data>data){
			node *temp= *root;
			*root=(node*)malloc(sizeof(node));
			(*root)->data=data;
			(*root)->next=temp;
		}
		else{
			(*root)->next=(node*)malloc(sizeof(node));
		(*root)->next->data=data;
		(*root)->next->next=NULL;
		}
		
	}
	
	else if((*root)->data>data){
		node *temp= *root;
		*root=(node*)malloc(sizeof(node));
		(*root)->data=data;
		(*root)->next=temp;
	}
	
	else{
		node* current = *root;
		while (current->next != NULL && current->next->data < data) {
			current = current->next;
		}
		node* newNode = (node*)malloc(sizeof(node));
		newNode->data = data;
		newNode->next = current->next;
		current->next = newNode;
	}
}


void printData(node * root){
	int i=1;
	while(root!=NULL){
		printf("%d-%d\n",i,root->data);
		root=root->next;
		i++;
	}
}
