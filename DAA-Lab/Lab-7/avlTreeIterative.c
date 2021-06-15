#include <stdio.h>
#include <stdlib.h>
#define SPACE 10

typedef struct TreeNode *TreeNodePtr;

struct TreeNode{
	int data;
	TreeNodePtr left;
	TreeNodePtr right;
	int balance;
};

int max(int a, int b){
	return a>b? a: b;
}

int getHeight(TreeNodePtr node){
	if(node==NULL) return -1;

	return 1 + max(getHeight(node->left), getHeight(node->right));
}


TreeNodePtr rightRotate(TreeNodePtr x){
	TreeNodePtr y = x->left;
	TreeNodePtr z = y->right;

	// perform rotation
	y->right = x;
	x->left = z;
	return y;
}

TreeNodePtr leftRotate(TreeNodePtr x){
	TreeNodePtr y = x->right;
	TreeNodePtr z = y->left;

	// perform rotation
	y->left = x;
	x->right = z;
	return y;
}


void balance_factor(TreeNodePtr root,TreeNodePtr st[],int *top)
{
	if(root==NULL)
		return;
	if(root->left==NULL && root->right==NULL)
	{
		
		return;
	}
	balance_factor(root->left,st,top);
	int bf = getHeight(root->left)- getHeight(root->right);
	root->balance=bf;
	if(bf>1 || bf<-1)
		st[++(*top)]=root;
	balance_factor(root->right,st,top);
}

TreeNodePtr AVL(TreeNodePtr root, int key){
	TreeNodePtr st[10];
	int top=-1;
	balance_factor(root,st,&top);
	if(top==-1)
		return root;
	
	TreeNodePtr snode;
	if(top==1)
		snode=st[top-1];
	else
		snode=st[top];
	TreeNodePtr nd=root;
	
	if(snode->balance>1 && key<nd->left->data)
		root=rightRotate(snode);
	
	else if(snode->balance<-1 && key>nd->right->data)
		root=leftRotate(snode);
	
	else if(snode->balance>1 && key>nd->left->data)
	{
		snode->left =leftRotate(snode->left);
		root=rightRotate(snode);
	}
	
	else if(snode->balance<1 && key<nd->right->data)
	{
		snode->right =rightRotate(snode->right);
		root=leftRotate(snode);
	}
	return root;
}


TreeNodePtr insertAVLIterative(TreeNodePtr root, int item){

	TreeNodePtr node = (TreeNodePtr)malloc(sizeof(struct TreeNode));
	node->data = item;
	node->left = NULL;
	node->right = NULL;

	if(root == NULL) return node;

	TreeNodePtr temp = root;
	TreeNodePtr parent;

	while(temp != NULL){
		parent = temp;
		if(temp->data<item){
			temp = temp->right;
		}else{
			temp = temp->left;
		}
	}

	if(parent->data < item){
		parent->right = node;
	}else{
		parent->left = node;
	}

	printf("Key Inserted\n");

	root = AVL(root, item);
	return root;
}


void Inorder(TreeNodePtr root){
	if(root){
		Inorder(root->left);
		printf("%d ", root->data);
		Inorder(root->right);
	}
}



void print2D(TreeNodePtr root, int space){
	if(root == NULL){
		return;
	}
	space += SPACE;
	print2D(root->right, space);
	printf("\n");
	for(int i=SPACE; i<space; i++){
		printf(" ");
	}
	printf("%d\n", root->data);
	print2D(root->left, space);
}

int main(){
	printf("Main function:\n");

	TreeNodePtr root = NULL;
	int key = 0;

	while(1){
		
		printf("\nEnter node value:\t");
		scanf("%d", &key);
		if(key != -1)
		root = insertAVLIterative(root, key);
		else break;
	}

	printf("\nInorder Traversal of the AVL tree created: \n");
    Inorder(root);
    

    printf("Printing the tree in 90 degree anticlockwise direction:\n");
    print2D(root, 5);
    printf("\n");

}