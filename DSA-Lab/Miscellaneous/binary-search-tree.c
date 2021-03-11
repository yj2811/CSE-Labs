#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef struct node *Nodeptr;

struct node{
    int data;
    Nodeptr rchild;
    Nodeptr lchild;
};

#include "QueueofNodeptr.h"


Nodeptr getnode(){
    return ((Nodeptr)malloc(sizeof(struct node)));
}

Nodeptr CreateBST(Nodeptr root, int item){
    if (root==NULL){
        root = getnode();
        root->data= item;
        root->lchild=root->rchild = NULL;
        return root;
    }
    else
    if (item<root->data)
        root->lchild = CreateBST(root->lchild, item);
    else
        if (item>root->data)
            root->rchild = CreateBST(root->rchild, item);
        else
            printf("Duplicates are not allowed\n");
    return root;
}

void Inorder(Nodeptr root){
    if (root){
        Inorder(root->lchild);
        printf("%d ",root->data);
        Inorder(root->rchild);
    }

}
Nodeptr Search(Nodeptr root,int ele)
{
    if(root==NULL)
       return NULL;
     if(root->data==ele)
        return root;
     else
        if (ele <root->data)
         return Search(root->lchild,ele);
        else
           return Search(root->rchild, ele);
}

void Insert(Nodeptr root, int ele){
    Nodeptr temp = getnode();
    temp->data = 0;
    temp->lchild = NULL;
    temp->rchild = NULL;

    if(root == NULL){
        root = temp;
        return;
    }

    Nodeptr parent, cur;

    //traverse until the correct position is found

    parent = NULL;
    cur = root;

    while(cur){
        parent = cur;

        if(ele == cur->data){
            printf("Not allowed\n");
        }

        else if (item<cur->data)
                cur=cur->lchild;
        else
            cur=cur->rchild;
    }//this basically ensures empty spot aagaya

    if (item<parent->data)
        parent->lchild = temp;
    else
        parent->rchild = temp;
    return;
}


void Delete(Nodeptr root, int item){
    Nodeptr parent, cur;
    Nodeptr q, succ;

    if(root == NULL){
        printf("Empty tree.\n");
    }

    parent = NULL;
    cur = root;

    while(cur && (cur->data!=item)){
        parent = cur;
            if (item<cur->data)
                cur = cur->lchild;
            else
                cur = cur->rchild;
    }

    if (cur==NULL) { printf("Item Not Found\n"); return;}
        Nodeptr q, succ;

    if (cur->lchild == NULL) //node to be deleted has empty left subtree
        q= cur->rchild;     //get the address of right subtree
    else if (cur->rchild == NULL) //node to be deleted has empty right subtree
        q = cur->lchild; 
    //basically q voh hai jo end mein parent se attach karna hai

    else{
        parent = cur;
            succ = cur->rchild; //get address of rightchild of node to be deleted*/

            while (succ->lchild){    //move to the leftmost node of succ
                parent = succ;
                succ= succ->lchild;
            }
            cur->data = succ->data;//exchange the data of current and succ;
            cur = succ;
            q = cur->rchild;
    }

    if(parent == NULL){
        free(cur);
        root = q;
        return;
    }

    else if(cur == parent->lchild)
        parent->lchild = q;
    else
        parent->rchild = q;
    free(cur);
    return;

    //for leaf node only(check condition), free karna hai aur parent node ka change (vohi until item found)karna hai. Rec code also. BST done.

    //binary tree for postfix expression
    NodePtr temp;
    ! '\0'
    temp mein node daalo
    if isalnum push
        pop rchild
    pop lchild
    push(s, temp)

    return pop(s); //return root

    //evaluation of tree expression using recursion. Done. 
    //Threaded leaving, not coming, smart work!!!

    
} 