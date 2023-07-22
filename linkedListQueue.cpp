#include <stdio.h>
#include <stdlib.h>

typedef struct n{
	int data;
	n *next;
}node;

void addDataQueue(node **,int);
void printData(node *);
void deleteData(node **,int);


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
	deleteData(&root,19);
	printData(root);
	deleteData(&root,12);
	printData(root);
	deleteData(&root,23);
	printData(root);
	addDataQueue(&root,9);
	printData(root);
	deleteData(&root,9);
	printData(root);
	deleteData(&root,84);
	printData(root);
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
		node* iter = *root;
		while (iter->next != NULL && iter->next->data < data) {
			iter = iter->next;
		}
		node* temp = (node*)malloc(sizeof(node));
		temp->data = data;
		temp->next = iter->next;
		iter->next = temp;
	}
}

void deleteData(node **root , int data){
	node *iter= *root;
	if(iter->data==data){
		iter=iter->next;
		free((*root));
		(*root)=iter;
	}
	else{
		while(iter->next->next!=NULL&&iter->next->data!=data){
			iter=iter->next;
		}
		if(iter->next->next==NULL&&iter->next->data!=data){
			printf("data=%d isn't found in the node\n",data);
		}
		else if(iter->next->next==NULL&&iter->next->data==data){
			free(iter->next);
			iter->next=NULL;
		}
		else{
			node *temp=(node*)malloc(sizeof(node));
			temp=iter->next;
			iter->next=iter->next->next;
			free(temp);
		}	
	}
	
}
