#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct n{
	n *left;
	n *right;
	int data;
}node;

node * insertion(node *,int);
void traversal(node *);
int search(node *,int);
int max(node *);
int min(node *);
node *deleteData(node *,int);

int main(){
	node *tree=NULL;
	//srand(time(NULL));
	for(int i=0;i<10;i++)
		tree=insertion(tree,rand()%100);
	traversal(tree);
	printf("\n%d\n%d\n%d\n",search(tree,45),max(tree),min(tree));
	tree=deleteData(tree,58);
	traversal(tree);
	return 0;
}

node * insertion(node *tree,int data){
	if(tree==NULL){
		node *root=(node*)malloc(sizeof(node));
		root->data=data;
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	if(tree->data>data){
		tree->left=insertion(tree->left,data);
		return tree;
	}
	tree->right=insertion(tree->right,data);
	return tree;
}

void traversal(node *tree){
	if(tree==NULL)
		return;
	traversal(tree->left);
	printf("%d ",tree->data);
	traversal(tree->right);
}

int search(node *tree,int data){
	if(tree==NULL)
		return -1;
	if(tree->data==data)
		return data;
	if(tree->data>data)
		search(tree->left,data);
	if(tree->data<data)
		search(tree->right,data);
	if(tree->data!=data)
		return -1;
}

int max(node *tree){
	if(tree->right!=NULL)
		return max(tree->right);
	return tree->data;
}

int min(node *tree){
	if(tree->left!=NULL)
		return min(tree->left);
	return tree->data;
}

node *deleteData(node *tree,int data){
	if (data > tree->data)
		tree->right = deleteData(tree->right, data);
	else if (data < tree->data)
		tree->left = deleteData(tree->left, data);
	else {
		if (tree->left == NULL) {
			node *temp = tree->right;
			free(tree);
			return temp;
		}
		if (tree->right == NULL) {
			node *temp = tree->left;
			free(tree);
			return temp;
		}
		tree->data = min(tree->right);
		tree->right = deleteData(tree->right, tree->data);
	}
	return tree;	
}
