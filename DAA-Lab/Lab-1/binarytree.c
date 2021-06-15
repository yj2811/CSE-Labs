#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode *TreeNodePtr;

struct TreeNode{
	int data;
	TreeNodePtr left;
	TreeNodePtr right;
};

TreeNodePtr BuildBST(TreeNodePtr root, int item){
	if(root == NULL){
		root = (TreeNodePtr)malloc(sizeof(struct TreeNode));
		root->data = item;
		root->left = NULL;
		root->right = NULL;

		printf("\nKey Inserted\n");
		
	}else if(item < root->data){
		root->left = BuildBST(root->left, item);
	}else if(item > root->data){
		root->right = BuildBST(root->right, item);
	}else{
		printf("\nKey Found (No duplicates allowed)\n");
	}
	return root;
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
	printf("Enter root element of the BST:\n");
	scanf("%d", &key);

	printf("Enter the keys for the BST");

	while(key != -1){
		root = BuildBST(root, key);
		printf("Enter next item:");
		scanf("%d", &key);
	}

	printf("\nInorder Traversal of the BST: \n");
    Inorder(root);
    printf("\nPreorder Traversal of the BST: \n");
    Preorder(root);
    printf("\nPostorder Traversal of the BST: \n");
    Postorder(root);


}