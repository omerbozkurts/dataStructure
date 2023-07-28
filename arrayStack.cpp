#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s{
	int top;
	int size;
	int *arr;
}stack;

stack s1;

void push(int);
void pop();
void printStack();

int main(){
	s1.top=0;
	s1.size=2;
	s1.arr=(int*)malloc(sizeof(int)*s1.size);
	push(10);
	push(13);
	push(1);
	push(7);
	printStack();
	pop();
	printStack();
	push(40);
	push(50);
	push(12);
	push(32);
	printStack();
	pop();
	printStack();
	pop();
	printStack();
	free(s1.arr);
	return 0;
}

void push(int data){
	if(s1.top==s1.size){
		s1.size *=2;
		int *arr2=(int*)malloc(sizeof(int)*s1.size);
		int i=0;
		while(i<s1.top){
			arr2[i]=s1.arr[i];
			i++;
		}
		free(s1.arr);
		s1.arr=arr2;
	}
	s1.arr[s1.top]=data;
	s1.top++;
}

void pop() {
    if (s1.top == 0) {
        printf("Stack is empty.\n");
        return;
    }
    s1.top -= 1;
    if (s1.top <= (s1.size / 2 - 1)) {
        s1.size /= 2;
        int *arr2 = (int*)malloc(sizeof(int) * s1.size);
        for (int i = 0; i < s1.top; i++) {
            arr2[i] = s1.arr[i];
        }
        free(s1.arr);
        s1.arr = arr2;
    }
}

void printStack(){
	int i=s1.top-1;
	while(i>=0){
		printf("%d\n",s1.arr[i]);
		i--;
	}
	printf("\n");
	usleep(100000);
}
