#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct n{
	int data;
	n *next;
	n *root;
	n *position;
}node;

node que;

void print();
void enque(int);
void deque();

int main(){
	que.root=NULL;
	for(int i=0;i<10;i++)
		enque(i*10);
	print();
	for(int i=0;i<15;i++){
		deque();
		print();
	}
	for(int i=0;i<15;i++)
		enque(i*10/2);
		print();
	return 0;
}

void print(){
	node *iter=que.root;
	if(que.root==NULL){
		printf("queue is empty\n");
		return;
	}
	while(iter!=NULL){
		printf("%d ",iter->data);
		iter=iter->next;
	}
	printf("\n");
	usleep(100000);
}

void enque(int data){
	if(que.root==NULL){
		que.root=(node*)malloc(sizeof(node));
		que.root->data=data;
		que.root->next=NULL;
		que.position=que.root;
		return;
	}
	que.position->next=(node*)malloc(sizeof(node));
	que.position->next->data=data;
	que.position->next->next=NULL;
	que.position=que.position->next;
}

void deque(){
	if(que.root==NULL){
		printf("queue is already empty\n");
		return;
	}
	node *temp=que.root;
	que.root=que.root->next;
	free(temp);
}
