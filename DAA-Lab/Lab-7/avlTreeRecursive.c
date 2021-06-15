#include <stdio.h>
#include <stdlib.h>
#define SPACE 10

typedef struct TreeNode *TreeNodePtr;

struct TreeNode{
  int key;
  TreeNodePtr left;
  TreeNodePtr right;
  int height;
};

int height(TreeNodePtr N){
  if (N == NULL)
  return 0;
  return N->height;
}

int max(int a, int b){
  return (a > b)? a : b;
}

TreeNodePtr newNode(int key){
  TreeNodePtr node = (TreeNodePtr)malloc(sizeof(struct TreeNode));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return(node);
}


TreeNodePtr rightRotate(TreeNodePtr y){
  TreeNodePtr x = y->left;
  TreeNodePtr T2 = x->right;
  x->right = y;
  y->left = T2;

  y->height = max(height(y->left), height(y->right))+1;
  x->height = max(height(x->left), height(x->right))+1;

  return x;
}

TreeNodePtr leftRotate(TreeNodePtr x){
  TreeNodePtr y = x->right;
  TreeNodePtr T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right))+1;
  y->height = max(height(y->left), height(y->right))+1;

  return y;
}

int getBalance(TreeNodePtr N){
  if (N == NULL)
  return 0;
  return height(N->left) - height(N->right);
}

TreeNodePtr insert(TreeNodePtr node, int key){
  if (node == NULL)
  return(newNode(key));

  if (key < node->key)
  node->left = insert(node->left, key);
  else if (key > node->key)
  node->right = insert(node->right, key);
  else
  return node;

  node->height = 1 + max(height(node->left), height(node->right));

  int balance = getBalance(node);

  if (balance > 1 && key < node->left->key)
  return rightRotate(node);

  if (balance < -1 && key > node->right->key)
  return leftRotate(node);

  if (balance > 1 && key > node->left->key){
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  if (balance < -1 && key < node->right->key){
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

void inorder(TreeNodePtr root){
  if(root != NULL){
    
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
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
  printf("%d\n", root->key);
  print2D(root->left, space);
}

int main(){
  TreeNodePtr root = NULL;
  int n;
  printf("Enter the Number of Nodes of The AVL Tree : \n");
  scanf("%d",&n);
  int x;
  for(int i=0;i<n;i++){
    printf("Enter the %d Node in the AVL Tree \n",(i+1));
    scanf("%d",&x);
    root=insert(root, x);
  }

  printf("Inorder traversal of the constructed AVL tree is \n");
  inorder(root);

  printf("Printing the tree in 90 degree anticlockwise direction:\n");
  print2D(root, 5);
  printf("\n");

  return 0;
}