#include <stdio.h>
#include <stdlib.h>

typedef struct n{
	int data;
	n* next;
}node;

void printData(node *);
void addDataCircular(node **,int);
void deleteData(node **,int);

int main(){
	node *root=NULL;
	addDataCircular(&root,5);
	addDataCircular(&root,3);
	addDataCircular(&root,4);
	addDataCircular(&root,6);
	addDataCircular(&root,8);
	addDataCircular(&root,12);
	addDataCircular(&root,9);
	addDataCircular(&root,1);
	printData(root);
	deleteData(&root,1);
	printData(root);
	addDataCircular(&root,1);
	printData(root);
	deleteData(&root,12);
	printData(root);
	addDataCircular(&root,7);
	printData(root);
	deleteData(&root,15);
	printData(root);
	addDataCircular(&root,11);
	printData(root);
	deleteData(&root,6);
	printData(root);
	return 0;
}

void printData(node *root){
	node *iter=root;
	if(root==NULL){
		printf("NULL node");
	}
	else{
		printf("1.%d\n",iter->data);
		iter=iter->next;
		int i=2;
		while(iter!=root){
			printf("%d.%d\n",i,iter->data);
			iter=iter->next;
			i++;
		}	
	}
	printf("\n");
}

void addDataCircular(node **root,int data){
	if((*root)==NULL){
		*root=(node*)malloc(sizeof(node));
		(*root)->data=data;
		(*root)->next=*root;
	}
	else if((*root)->data>data){
		if((*root)->next==(*root)){
			node *temp=*root;
			(*root)->next=(node*)malloc(sizeof(node));
			(*root)->next->data=data;
			(*root)->next->next=*root;
			(*root)=(*root)->next;
			(*root)->next=temp;		
		}
		else{
			node *iter=*root;
			while(iter->next!=(*root)){
				iter=iter->next;
			}
			node *temp=(node*)malloc(sizeof(node));
			temp->data=data;
			temp->next=*root;
			iter->next=temp;
			*root=temp;
			
		}
	
	}
	else{
		node *iter=*root;
		while(iter->next!=(*root)&&iter->next->data<data){
			iter=iter->next;
		}
		if(iter->next==(*root)){
			node *temp;
			temp=(node*)malloc(sizeof(node));
			temp->data=data;
			temp->next=*root;
			iter->next=temp;
		}
		else{
			node *temp;
			temp=(node*)malloc(sizeof(node));
			temp->data=data;
			temp->next=iter->next;
			iter->next=temp;
		}
	}
}

void deleteData(node **root, int data){
	node *iter=*root;
	if((*root)->data==data){
		while(iter->next!=*root){
			iter=iter->next;
		}
		node *temp=*root;
		iter->next=iter->next->next;
		*root=iter->next;
		free(temp);		
	}
	else{
		iter=*root;
		while(iter->next->next!=(*root)&&iter->next->data!=data){
			iter=iter->next;
		}
		if(iter->next->next==*root&&iter->next->data!=data){
			printf("data=%d isn't found in the node\n",data);
		}
		else if(iter->next->next==*root&&iter->next->data==data){
			node *temp=iter->next;
			iter->next=*root;
			free(temp);
		}
		else if(iter->next->data==data){
			node *temp=iter->next;
			iter->next=iter->next->next;
			free(temp);
		}
	}

}
