#include <stdio.h>
#include <stdlib.h>

typedef struct n{
	int data;
	n* next;
}node;

void printNode(node *);
void addNode(node *);
void addSelectively(node *,int,int);


int main(){
	node* root;
	root=(node*)malloc(sizeof(node));
	root->data=9;
	root->next=(node*)malloc(sizeof(node));
	root->next->data=5;
	root->next->next=(node*)malloc(sizeof(node));
	root->next->next->data=6;
	root->next->next->next=NULL;
	printf("%d \n%d \n%d",root->data,root->next->data,root->next->next->data);
	node* iter;
	iter=root;
	printf("\n%d",iter->data);
	iter=iter->next;
	printf("\n%d",iter->data);
	iter=root;
	
	while(iter->next!=NULL){
		printf("\na %d",iter->data);
		iter=iter->next;
		
	}
	
	for(int i=0;i<5;i++){
		iter->next=(node*)malloc(sizeof(node));
		iter=iter->next;
		iter->data=i*2;
		iter->next=NULL;
	}
	addNode(root);
	//printNode(root);
	addSelectively(root,8,3);
	printNode(root);

}

void printNode(node * root){
	int i=1;
	while(root!=NULL){
	
		printf("\n%d-%d",i,root->data);
		root=root->next;
		i++;
	}
}

void addNode(node * root){
	while(root->next!=NULL){
		root=root->next;
	}
	for(int i=0;i<5;i++){
		root->next=(node*)malloc(sizeof(node));
		root=root->next;
		root->data=i*2;
		root->next=NULL;
	}
}

void addSelectively(node * root,int listElement,int newData){
	while(root->next->data!=listElement){
		root=root->next;
	}
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp=root->next;
	root->next=(node*)malloc(sizeof(node));
	root->next->data=newData;
	root->next->next=temp;
}


