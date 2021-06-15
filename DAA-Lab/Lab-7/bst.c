#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode *TreeNodePtr;

struct TreeNode{
	int data;
	TreeNodePtr left;
	TreeNodePtr right;
};

int max(int a, int b){
	return a>b? a: b;
}

int getHeight(TreeNodePtr node){
	if(node==NULL) return -1;

	return 1 + max(getHeight(node->left), getHeight(node->right));
}

int getBalanceFactor(TreeNodePtr node){
	if(node == NULL) return -1;
	
	int lheight = getHeight(node->left);
	int rheight = getHeight(node->right);

	return (lheight - rheight);
}

TreeNodePtr BuildBST(TreeNodePtr root, int item){
	if(root == NULL){
		root = (TreeNodePtr)malloc(sizeof(struct TreeNode));
		root->data = item;
		root->left = NULL;
		root->right = NULL;

		printf("Key Inserted\n");
		
	}else if(item < root->data){
		root->left = BuildBST(root->left, item);
	}else if(item > root->data){
		root->right = BuildBST(root->right, item);
	}else{
		printf("Key Found (No duplicates allowed)\n");
	}
	return root;
}

void printBalanceFactor(TreeNodePtr node){
	if(node){
		printBalanceFactor(node->left);
		printf("%d -> %d\n", node->data, getBalanceFactor(node));
		printBalanceFactor(node->right);
	}
}

void Inorder(TreeNodePtr root){
	if(root){
		Inorder(root->left);
		printf("%d ", root->data);
		Inorder(root->right);
	}
}

void Preorder(TreeNodePtr root){
	if(root){
		printf("%d ", root->data);
		Preorder(root->left);
		Preorder(root->right);
	}
}

void Postorder(TreeNodePtr root){
	if(root){
		Postorder(root->left);
		Postorder(root->right);
		printf("%d ", root->data);
	}
}

int main(){
	printf("Main function:\n");

	TreeNodePtr root = NULL;
	int key = 0;

	while(1){
		
		printf("\nEnter node value:\t");
		scanf("%d", &key);
		if(key != -1)
		root = BuildBST(root, key);
		else break;
	}

	printf("\nInorder Traversal of the BST: \n");
    Inorder(root);
    printf("\nPreorder Traversal of the BST: \n");
    Preorder(root);
    printf("\nPostorder Traversal of the BST: \n");
    Postorder(root);

    printf("\nBalance factor of all nodes in the BST:\n");
    printBalanceFactor(root);
    printf("\n");

}