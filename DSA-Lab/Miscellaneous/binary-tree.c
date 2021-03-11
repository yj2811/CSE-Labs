#include<stdio.h>
#include<stdlib.h>
#include "StackOfNodePtr.h"
#include "QueueOfNodePtr.h"
#define true 1
#define false 0

typedef struct node* NodePtr;

struct node{
	int data;
	NodePtr rchild;
	NodePtr lchild;
};

NodePtr getNode(){
	NodePtr temp = (NodePtr)malloc(sizeof(struct node));
	temp->data = 0;
	temp->rchild = NULL;
	temp->lchild = NULL;

	return temp;
}

NodePtr CreateBTRecursively(int item){
	int x;
	if(item != -1){
		NodePtr temp = getNode();
	temp->data = item;

	printf("Enter left child of %d\n", item);
	scanf("%d", &x);

	temp->lchild = CreateBTRecursively(x);

	printf("Enter right child of %d\n", item);
	scanf("%d", &x);
	temp->rchild = CreateBTRecursively(x);

	return temp;
	}

	return NULL;
}

void recursiveInorder(NodePtr root){
	if(root){
		recursiveInorder(root->lchild);
		printf("%d", root->data);
		recursiveInorder(root->rchild);
	}
}

void recursivePreorder(NodePtr root){
	if(root){
		printf("%d", root->data);
		recursivePreorder(root->lchild);
		recursivePreorder(root->rchild);
	}
}

void recursivePostorder(NodePtr root){
	if(root){
		recursivePostorder(root->lchild);
		recursivePostorder(root->rchild);
		printf("%d", root->data);
	}
}

void iterativeInorder(NodePtr root){
	NodePtr cur;
	int done = false;

	STACK *s, s1;
	s=&s1;
	s->top=-1;
	//either this or STACK *s = (STACK*)malloc(sizeof(STACK))

	if(root==NULL){
		printf("Empty tree\n");
		return;
	}

	cur = root;
	while(!done){

		 while(cur!=NULL)
        {
            Push(s, cur);
            cur=cur->lchild;
        }
        if(!isEmptyStack(s))
        {
            cur=Pop(s);
            printf("%d ",cur->data);
            cur=cur->rchild;
        }
        else
            done = true;
	}
}

void iterativePostorder(NodePtr root)
{
    struct stack
    {
        NodePtr node;
        int flag;
    };
    NodePtr cur;
    struct stack s[20];
    int top=-1;
    if(root==NULL)
    {
        printf("Tree is empty");
        return;
    }
    cur=root;
    for(; ;){
        while(cur!=NULL){ 
        s[++top].node=cur;
        s[top].flag = 1;
        cur=cur->lchild;
    }
    while(s[top].flag<0){ 
        cur=s[top--].node;
        printf("%d ", cur->data);
        if(top==-1)
            return;
    }
    cur= s[top].node;
    cur=cur->rchild;
    s[top].flag = -1;
    }
}

void iterativePreorder(NodePtr root){
	STACK *s = (STACK*)malloc(sizeof(STACK));
	NodePtr cur = root;

	if(root == NULL){
		printf("Empty tree\n");
		return;
	}

	Push(s, root);
	while(!isEmptyStack(s)){
		cur = Pop(s);
		printf("%d\n", cur->data);
		if(cur->rchild) Push(s, cur->rchild);
		if(cur->lchild) Push(s, cur->lchild);
	}
}

void levelOrder(NodePtr root){
	QUEUE *q, q1;
    q = &q1;
    q->Front=-1;
    q->Rear =-1;
    if (root== NULL)
    {
        printf("\nEmpty Tree\n");
        return;
    }

    InsertQ(q, root);
    while(!isEmptyQueue(q)){
    	NodePtr temp = DeleteQ(q);
    	printf("%d\n", temp->data);
    	if(temp->lchild) InsertQ(q, temp->lchild);
    	if(temp->rchild) InsertQ(q, temp->rchild);
    }
}

void insert(NodePtr root, char direction[], int ele){
	NodePtr temp, parent, cur;

	temp = getNode();
	temp->data = ele;
	temp->lchild = NULL;
	temp->rchild = NULL;

	parent = NULL;
	cur=root;
	int i=0;

	while(cur && direction[i] != '\0'){
		parent = cur;

		if(direction[i]=='L' || direction[i]=='l')
            cur=cur->lchild;
        else
            cur=cur->rchild;
        i++;
	}

	if ((cur != NULL) || (direction[i]!='\0'))
    {
 
       printf("Insertion Not possible\n") ;
       free(temp);
       return;
    }
   
    if(direction[i-1]=='L' || direction[i-1]=='l')
            parent->lchild=temp;
    else
            parent->rchild=temp;
}

int Search(NodePtr root, int ele){
	static int t=0;
	if(root){
		  if(root->data==ele){
            t++;
            return t;
        }
        if (t==0) Search(root->lchild,ele);
        if (t==0) Search(root->rchild,ele);
	}

	return t;
}

int max(int a,int b)
{
    return (a>b)? a:b;
}

int height(NodePtr root){
	if(!root) return 0;
	return 1+max(height(root->lchild), height(root->rchild));
}

int count_leafnodes(NodePtr root){
	static int count;
	if(root!=NULL){
		if(root->lchild==NULL && root->rchild==NULL){
			++count;
		}

		count_leafnodes(root->lchild);

		count_leafnodes(root->rchild);
	}

	return count;
}

int main(){
	NodePtr root = NULL;

    int item;
    char direction[50];

    printf("Creating the tree : \n");
    scanf("%d",&item);
    fflush(stdin);
    root=CreateBTRecursively(item);

    printf("\nInorder Traversal : \n");
    recursiveInorder(root);
    printf("\nPreorder Traversal : \n");
    recursivePreorder(root);
    printf("\nPostorder Traversal : \n");
    recursivePostorder(root);


    printf("\nLevel Order Traversal : \n");
   levelOrder(root);

    printf("\nIterative  inOrder Traversal : \n");
    iterativeInorder(root);

    printf("\nHeight of the tree = %d\n",height(root));

    printf("Enter the item to be searched: ");

    scanf("%d", &item);
    int t = Search(root, item);
    if (t==1)
        printf("the element found\n");
    else
        printf("the element not found\n");
    printf("\n%d", count_leafnodes(root));
    printf("\nEnter the direction string for insertion : ");
    scanf(" %s", direction);
    printf("Enter the item to be inserted : ");
    scanf("%d",&item);
    insert(root, direction, item);
    recursiveInorder(root);
    return 0;
}