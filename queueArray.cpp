#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct q{
	int base;
	int row;
	int size;
	int *arr=NULL;
}queue;

queue que; 

void print();
void enque(int);
void deque();

int main(){
	for(int i=0;i<17;i++)
		enque(i*5*i/2);
	print();
	printf("\nchecklist: size:%d base:%d row:%d \n",que.size,que.base,que.row);	
	for(int i=0;i<10;i++)
		deque();
	print();
	printf("\nchecklist: size:%d base:%d row:%d \n",que.size,que.base,que.row);
	for(int i=0;i<26;i++)
		enque(i*5);
	print();
	printf("\nchecklist: size:%d base:%d row:%d \n",que.size,que.base,que.row);	
	return 0;
}

void print(){
	int i=0;
	while(i<(que.row-que.base)){
		printf("%d ",que.arr[i]);
		i++;
	}
	printf("\n");
	usleep(100000);
}

void enque(int data){
	if(que.arr==NULL){
		que.arr=(int*)malloc(sizeof(int)*que.size);
		que.size=2;
		que.base=0;
		que.row=0;
	}
		
		
	que.arr[que.row]=data;
	que.row++;
	
	if(que.row==que.size){
		que.size*=2;
		int *arr2=(int*)malloc(sizeof(int)*que.size);
		int i=0;
		while(i<=(que.row-que.base)){
			arr2[i]=que.arr[i];
			i++;
		}
		free(que.arr);
		que.arr=arr2;
	}	
}

void deque(){
	if(que.size<=1){
		printf("queue is empty\n");
		if(que.size==0)
			return;
	}
	que.base++;
	
	if((que.row-que.base)<=que.size/2){
		que.size/=2;
		int *arr2=(int*)malloc(sizeof(int)*que.size);
		int i=0;
		int j=que.base;
		while(i<=que.row-que.base){
			arr2[i]=que.arr[j];
			i++;
			j++;
		}
		que.row-=que.base;
		que.base=0;
		free(que.arr);
		que.arr=arr2;
	}
	else{
		int *arr2=(int*)malloc(sizeof(int)*que.size);
		int i=0;
		int j=que.base;
		while(i<=que.row-que.base){
			arr2[i]=que.arr[j];
			i++;
			j++;
		}
		que.row-=que.base;
		que.base=0;
		free(que.arr);
		que.arr=arr2;
	}
}

