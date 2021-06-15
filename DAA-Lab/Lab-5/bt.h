#include<stdio.h>

typedef struct node{
  int data;
  struct node *left;
  struct node *right;
} node;

node *root;
node *create(){
  node *p;
  int x;
  printf("Enter value (-1 for NULL)\t:");
  scanf("%d",&x);
  if(!x)
  return NULL;
  p=(node*)malloc(sizeof(node));
  p->data=x;
  printf("\nEnter left child of %d:\t",x);
  p->left=create();

  printf("\nEnter right child of %d:\t",x);
  p->right=create();
  return p;
}

void preorder(node *t){
  if(t!=NULL){
    printf("\n%d",t->data);
    preorder(t->left);
    preorder(t->right);
  }
}

void bt(){
  root=create();
}
