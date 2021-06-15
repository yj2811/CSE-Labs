#include <stdio.h>
#include <stdlib.h>

int opcount=0;

typedef struct TreeNode *TreeNodePtr;

struct TreeNode{
	int data;
	TreeNodePtr left;
	TreeNodePtr right;
};

TreeNodePtr root;
TreeNodePtr CreateBT(){
	int x;
	printf("\t Enter the node value (-1 for NULL):  ");
	scanf("%d", &x);

	if(x==-1) return NULL;

	TreeNodePtr node = (TreeNodePtr)malloc(sizeof(struct TreeNode));
	node->data = x;

	printf("\nLeft child of %d -> \t", x);
	node->left = CreateBT();

	printf("\nRight child of %d -> \t", x);
	node->right = CreateBT();

	return node;

}

int NumberOfNodes(TreeNodePtr root){
	opcount++;
	if(root==NULL) return 0;
	else
		return 1+ NumberOfNodes(root->left) + NumberOfNodes(root->right);

}

int main(){
	root = CreateBT();
	printf("The number of nodes in the binary tree are: %d \n", NumberOfNodes(root));
	printf("Opcount = %d\n", opcount);
}