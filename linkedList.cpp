#include <stdio.h>
#include <stdlib.h>

typedef struct n{
	int data;
	n* next;
}node;

int main(){
	node* root;
	root=(node*)malloc(sizeof(node));
	root->data=9;
	root->next=(node*)malloc(sizeof(node));
	root->next->data=5;
	root->next->next=(node*)malloc(sizeof(node));
	root->next->next->data=6;
	printf("%d \n%d \n%d",root->data,root->next->data,root->next->next->data);
}
