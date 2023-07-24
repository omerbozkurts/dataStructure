#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct n{
	int data;
	n *next;
	n *prev;
}node;

void printData(node*);
void printPrev(node*);
node *addData(node *,int);
node *deleteData(node *,int);

int main(){
	node *root=NULL;
	root=addData(root,5);
	root=addData(root,8);
	root=addData(root,6);
	root=addData(root,3);
	root=addData(root,4);
	root=addData(root,9);
	root=addData(root,1);
	printData(root);
	printPrev(root);
	root=deleteData(root,1);
	printData(root);
	printPrev(root);
	root=deleteData(root,13);
	printData(root);
	printPrev(root);
	root=deleteData(root,8);
	printData(root);
	printPrev(root);
	root=deleteData(root,9);
	printData(root);
	printPrev(root);
	return 0;
}

void printData(node * root){
	int i=1;
	while(root!=NULL){
		printf("%d-%d\n",i,root->data);
		root=root->next;
		i++;
	}
	printf("\n");
	usleep(100000);
}

void printPrev(node *root){
	int i=1;
	while(root->next!=NULL){
		root=root->next;
		i++;
	}
	while(root!=NULL){
		printf("%d-%d\n",i,root->data);
		root=root->prev;
		i--;
	}
	printf("\n");
	usleep(100000);
}

node *addData(node *root,int data){
	if(root==NULL){
		root=(node*)malloc(sizeof(node));
		root->data=data;
		root->next=NULL;
		root->prev=NULL;
		return root;
	}
	else if(root->data>data){
		node *temp=(node*)malloc(sizeof(node));
		temp->data=data;
		temp->prev=NULL;
		temp->next=root;
		temp->next->prev=temp;
		return temp;
	}
	
	node *iter=root;
	while(iter->next!=NULL&&iter->next->data<data)
		iter=iter->next;
	node *temp=(node*)malloc(sizeof(node));
	temp->data=data;
	temp->next=iter->next;
	iter->next=temp;
	temp->prev=iter;
	if(temp->next!=NULL)
		temp->next->prev=temp;
	return root;
	
}

node *deleteData(node *root,int data){
	node *iter=root;
	if(root->data==data){
		node *temp=root->next;
		root->next->prev=NULL;
		free(root);
		return temp;
	}
	while(iter->next!=NULL&&iter->next->data!=data)
		iter=iter->next;
	if(iter->next==NULL&&iter->data!=data)
		printf("data=%d isn't found in the node\n",data);
	else{
		node *temp=iter->next;
		iter->next=iter->next->next;
		if(temp->next!=NULL)
			iter->next->prev=iter;
		free(temp);
	}
	return root;
}
