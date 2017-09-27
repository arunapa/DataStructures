//singly linked list
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node{
	int data;
	struct Node *NEXT;
}*start = NULL;

void lcreate(){
	char ch;
	do{
		struct Node *temp, *ptr;
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp -> NEXT = NULL;
		printf("Enter data: ");
		scanf("%d", &temp -> data);
		if(start == NULL){
			start = temp;
			ptr = start;
		}
		else{
			ptr -> NEXT = temp;
			ptr = temp;
		}
		printf("Want to continue? (Y/N) ");
		scanf(" %c", &ch);
	}while(ch == 'y' || ch == 'Y');
}

void linsert(){
	int pos, i;
	struct Node *temp, *ptr, *ins;
	ptr = start;
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp -> NEXT = NULL;
	printf("Enter index to insert: ");
	scanf("%d", &pos);
	printf("Enter data: ");
	scanf("%d", &temp -> data);
	if(pos == 0){ //first insert
		temp -> NEXT = start;
		start = temp;
	}
	else{
		for(i = 0; i < pos - 1; i++)
			if(ptr -> NEXT != NULL)
				ptr = ptr -> NEXT;
		if(ptr -> NEXT == NULL){ //last insert
			ptr -> NEXT = temp;
		}
		else{
			ins = ptr -> NEXT;
			ptr -> NEXT = temp;
			temp -> NEXT = ins;
		}
	}
}

void ldelete(){
	if(start == NULL)
		printf("Single Linked List empty!");
	else{
		int pos, i;
		struct Node *ptr, *del;
		ptr = start;
		printf("Enter index to delete: ");
		scanf("%d", &pos);
		if(pos == 0){ //first delete
			printf("Deleted: %d", ptr -> data);
			start = start -> NEXT;
			free(ptr);
		}
		else{
			for(i = 0; i < pos - 1; i++){
				if(ptr -> NEXT != NULL){
					del = ptr;
					ptr = ptr -> NEXT;
				}
			}
			if(ptr -> NEXT == NULL){ //last insert
				printf("Deleted: %d", ptr -> data);
				del -> NEXT = NULL;
				free(ptr);
			}
			else{
				del = ptr -> NEXT;
				ptr -> NEXT = del -> NEXT;
				printf("Deleted: %d", del -> data);
				free(del);

			}
		}
	}
}

void ldisplay(){
	if(start == NULL)
		printf("Single Linked List empty!");
	else{
		struct Node *temp;
		temp = start;
		printf("LIST: ");
		while(temp != NULL){
			printf("%d ", temp -> data);
			temp = temp -> NEXT;
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
		printf("5. EXIT\n\n");
		printf("Enter option: ");
		scanf("%d", &op);
		printf("\n");
		switch(op){
			case 1:
				lcreate();
				break;
			case 2:
				linsert();
				break;
			case 3:
				ldelete();
				break;
			case 4:
				ldisplay();
				break;
			case 5:
				exit(0);
		}
		printf("\n\n");
	}while(op > 0);
	return 0;
}
