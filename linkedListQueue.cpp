#include <stdio.h>
#include <stdlib.h>

typedef struct n{
	int data;
	n *next;
}node;

void addDataQueue(node *,int);
void printData(node *);


int main(){
	node *root=NULL;	
	addDataQueue(root,4);
	addDataQueue(root,3);
	addDataQueue(root,6);
	addDataQueue(root,8);
	addDataQueue(root,5);
	addDataQueue(root,7);
	addDataQueue(root,2);
	addDataQueue(root,19);
	addDataQueue(root,13);
	printf("test1");
	printData(root);
	return 0;
}

void addDataQueue(node * root,int data){
	if(root==NULL){ 
		printf("test2");
		root=(node*)malloc(sizeof(node));
		root->data=data;
		root->next=NULL;
				
	}
	
	else if(root->next==NULL){
		if(root->data>data){
			node *temp=(node*)malloc(sizeof(node));
			temp=root;
			root->data=data;
			root->next=temp;
		}
		root->next=(node*)malloc(sizeof(node));
		root->next->data=data;
		root->next->next=NULL;
	}
	
	else if(root->data>data){
		node *temp=(node*)malloc(sizeof(node));
		temp=root;
		root->data=data;
		root->next=temp;
	}
	
	else{
		while(root->next->data<data){
			root=root->next;
		}
		if(root->next=NULL){
			root->next=(node*)malloc(sizeof(node));
			root->next->data=data;
			root->next->next=NULL;
		}
		else if(root->next!=NULL){
			node *temp=(node*)malloc(sizeof(node));
			temp=root->next;
			root->next->data=data;
			root->next->next=temp;
		}
	}
}


void printData(node * root){
	int i=1;
	while(root!=NULL){
		printf("%d-%d",i,root->data);
		root=root->next;
		i++;
	}
}
