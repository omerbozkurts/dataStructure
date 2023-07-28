#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct n{
	n *next;
	int data;
}node;

void printStack(node *);
void push(node **,int);
void pop(node **);

int main(){
	node *root=NULL;
	push(&root,6);
	push(&root,5);
	push(&root,7);
	push(&root,12);
	push(&root,3);
	printStack(root);
	pop(&root);
	printStack(root);
	pop(&root);
	printStack(root);
	return 0;
}

void printStack(node *root){
	while(root!=NULL){
		printf("%d\n",root->data);
		root=root->next;
	}
	printf("\n");
	usleep(100000);
}

void push(node **root,int data){
	if(*root==NULL){
		*root=(node*)malloc(sizeof(node));
		(*root)->data=data;
		(*root)->next=NULL;
	}
	else{
		node *iter=*root;
		while(iter->next!=NULL)
			iter=iter->next;
		iter->next=(node*)malloc(sizeof(node));
		iter->next->data=data;	
		iter->next->next=NULL;
	}	
}

void pop(node **root){
	node *iter=*root;
	if(*root==NULL)
		printf("Stack is empty.\n");
	else if((*root)->next==NULL){
		*root=NULL;
	}
	else{
		while(iter->next->next!=NULL)
			iter=iter->next;
		node *temp=(node*)malloc(sizeof(node));
		temp=iter->next;
		free(temp);
		iter->next=NULL;
	}
	
}
