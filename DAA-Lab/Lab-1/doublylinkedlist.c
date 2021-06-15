#include<stdio.h>
#include<stdlib.h>

typedef struct node* nodeptr;

struct node{
	int val;
	nodeptr llink;
	nodeptr rlink;
};

nodeptr head = NULL;

void CreateList(int val){
	nodeptr temp;
	if(head == NULL){
		temp = (nodeptr)malloc(sizeof(struct node));
		temp->llink = temp->rlink = NULL;
		temp->val = val;
		head = temp;
	}else{
		printf("List already created.\n");
	}
}

void insertIntoList(int before, int val){
	nodeptr temp, nd;
	nd = head;

	while(nd != NULL && nd->val != before){
		nd = nd->rlink;
	}

	if(nd != NULL){
		temp = (nodeptr)malloc(sizeof(struct node));
		temp->llink = temp->rlink = NULL;
		temp->val = val;

		if(temp->llink != NULL){
			nd->llink->rlink = temp;
			temp->llink = nd->llink;
			temp->rlink = nd;
			nd->llink = temp;
		}else{
			temp->rlink = nd;
			nd->llink = temp;
			head = temp;
		}
	}else{
		printf("Unable to insert.\n");
	}
}

void deleteAll(int val){
	nodeptr nd, nextnd;
	nd = head;

	while(nd != NULL){
		if(nd->val == val){
			if(nd->llink != NULL){
				nd->llink->rlink = nd->rlink;
				if(nd->rlink != NULL){
					nd->rlink->llink = nd->llink;
					nextnd = nd->rlink;
					free(nd);
					nd = nextnd;

				}else{
					nd->llink->rlink = NULL;
					free(nd);
					nd=NULL;
				}
			}else{
				if(nd->rlink != NULL){
					nd->rlink->llink = NULL;
					head = nd->rlink;
					free(nd);
					nd = head;
				}else{
					free(nd);
					head = nd = NULL;
				}
			}
		}else{
			nd = nd->rlink;
		}
	}
}

void searchNode(int val){
	nodeptr temp;
	temp = head;
	while(temp!=NULL){
		if(temp->val == val){
			printf("Node found with key %d\n", val);
			temp = temp->rlink;
		}
	}
}

void displayAll(){
	nodeptr temp;
	temp = head;
	while(temp!=NULL){
			printf("Node with val %d\n", temp->val);
			temp = temp->rlink;
	}
}

int main (){
	int choice,val,before;

	do{
		printf("1. Create List\n"); 
		printf("2. Insert into List\n"); 
		printf("3. Delete all by value\n"); 
		printf("4. Search by value\n"); 
		printf("5. Display all\n"); 
		printf("6. Exit\n");
		printf("Enter your choice :"); 
		scanf("%d", &choice); 

		switch(choice){
			case 1: printf("Please enter the node value"); 
			scanf("%d", &val);
			CreateList(val); break;

			case 2: 
			printf("Please enter the node value to insert: "); 
			scanf("%d", &val);
			printf("Please enter the node value before which new node has to be inserted: ");
			scanf("%d", &before); 
			insertIntoList(before, val); break;

			case 3: 
			printf("Enter the node value to be deleted: "); 
			scanf("%d", &val);
			deleteAll(val); break;

			case 4:
			printf("Enter the node value to be searched: ");
			scanf("%d", &val); 
			searchNode(val); break;

			case 5:
			displayAll(); break;

			case 6:
			break;

			default:
			printf("Invalid choice "); break;

		}
	}while(choice != 6);
	return 0;
}



