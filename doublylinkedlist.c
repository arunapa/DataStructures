//doubly linked list
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node{
	int data;
	struct Node *LEFT, *RIGHT;
}*start = NULL;

void dlcreate(){
	char ch;
	do{
		struct Node *temp, *ptr;
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp -> LEFT = NULL;
		temp -> RIGHT = NULL;
		printf("Enter data: ");
		scanf("%d", &temp -> data);
		if(start == NULL){
			start = temp;
			ptr = temp;
		}
		else{
			ptr -> RIGHT = temp;
			temp -> LEFT = ptr;
			ptr = temp;
		}
		printf("Want to continue? (Y/N) ");
		scanf(" %c", &ch);
	}while(ch == 'y' || ch == 'Y');
}

void dldisplay(){
	if(start == NULL)
		printf("Doubly Linked List empty!\n");
	else{
		struct Node *ptr;
		ptr = start;
		printf("LIST: ");
		while(ptr != NULL){
			printf("%d ", ptr -> data);
			ptr = ptr -> RIGHT;
		}
	}
}

void dlinsert(){
	int pos, i = 0;
	struct Node *temp, *ptr, *ins;
	ptr = start;
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp -> LEFT = NULL;
	temp -> RIGHT = NULL;
	printf("Enter index to insert: ");
	scanf("%d", &pos);
	printf("Enter data: ");
	scanf("%d", &temp -> data);
	if(pos == 0){ //first insert
		temp -> RIGHT = ptr;
		ptr -> LEFT = temp;
		start = temp;
	}
	for(i = 0; i < pos-1; i++){
		if(ptr -> RIGHT != NULL)
			ptr = ptr -> RIGHT;
	}
	if(ptr -> RIGHT == NULL){ //last insert
		ptr -> RIGHT = temp;
		temp -> LEFT = ptr;
	}
	else{
		ins = ptr -> RIGHT;
		ptr -> RIGHT = temp;
		temp -> LEFT = ptr;
		ins -> LEFT = temp;
		temp -> RIGHT = ins;
	}
}

void dldelete(){
	if(start == NULL)
		printf("Doubly Linked List empty!\n");
	else{
		int i, pos;
		struct Node *temp, *ptr, *pre;
		temp = start;
		printf("Enter position to delete: ");
		scanf("%d", &pos);
		//single element list
		if(pos == 0 && start -> LEFT == NULL && start ->RIGHT == NULL){
			//single element list
			temp = start;
			printf("Deleted: %d", temp -> data);
			free(temp);
			start = NULL;
		}
		else if(pos == 0){ // first delete
			printf("Deleted: %d", temp -> data);
			start = start -> RIGHT;
			start -> LEFT = NULL;
			free(temp);
		}
		else{
			for(i = 0; i < pos; i++){
				if(temp -> RIGHT != NULL)
					temp = temp -> RIGHT;
			}
			if(temp -> RIGHT == NULL){
				pre = temp -> LEFT;
				pre -> RIGHT = NULL;
				temp -> LEFT = NULL;
				printf("Deleted: %d", temp -> data);
				free(temp);
			}
			else{
				pre = temp -> LEFT;
				ptr = temp -> RIGHT;
				pre -> RIGHT = ptr;
				ptr -> LEFT = pre;
				printf("Deleted: %d", temp -> data);
				free(temp);
			}
		}
	}
}

int main(){
	int op;
	do{
		printf("MENU\n----\n");
		printf("1. Create list\n");
		printf("2. Insert element\n");
		printf("3. Delete element\n");
		printf("4. Display list\n");
		printf("5. EXIT\n");
		printf("\nEnter option: ");
		scanf("%d", &op);
		printf("\n");
		switch(op){
			case 1:
				dlcreate();
				break;
			case 2:
				dlinsert();
				break;
   			case 3:
				dldelete();
				break;
			case 4:
				dldisplay();
				break;
			case 5:
				exit(0);
		}
		printf("\n\n");
	}while(op > 0);
	return 0;
}
