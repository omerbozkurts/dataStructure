#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int x;
    n *next;
}node;

int main(){
    node *root;
    root=(node*)malloc(sizeof(node));
    root -> x=20;
    root -> next=(node*)malloc(sizeof(node));
    root -> next -> x=3;
    root -> next -> next= (node*)malloc(sizeof(node));
    root -> next -> next -> x=5;

    return 0;
}