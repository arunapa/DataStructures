#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>

struct Node{
	int data;
	struct Node *LEFT, *RIGHT;
}*start = NULL;

void dlcreate();
void dldisplay();
void dlfirstinsert();
void dlendinsert();
void dlinsertbefore();
void dlinsertafter();
void dlfirstdelete();
void dlenddelete();
void dldeletebefore();
void dldeleteafter();
void dldeletefull();

int main(){
	int op;
	do{
		printf("MENU\n----\n");
		printf("1. Create list\n");
		printf("2. Display list\n");
		printf("3. Add node to start of list\n");
		printf("4. Add node to end of list\n");
		printf("5. Add node before a given position\n");
		printf("6. Add node after a given position\n");
		printf("7. Delete node from beginning\n");
		printf("8. Delete node from end\n");
		printf("9. Delete node before given position\n");
		printf("10. Delete node after given position\n");
		printf("11. Delete the entire list\n");
		printf("12. EXIT\n");
		printf("\nEnter option: ");
		scanf("%d", &op);
		switch(op){
			case 1:
				dlcreate();
				break;
			case 2:
				dldisplay();
				break;
   			case 3:
				dlfirstinsert();
				break;
			case 4:
				dlendinsert();
				break;
			case 5:
				dlinsertbefore();
				break;
			case 6:
				dlinsertafter();
				break;
			case 7:
				dlfirstdelete();
				break;
			case 8:
				dlenddelete();
				break;
			case 9:
				dldeletebefore();
				break;
			case 10:
				dldeleteafter();
				break;
			case 11:
				dldeletefull();
				break;
			case 12:
				exit(0);
		}
		
	}while(op > 0);
	return 0;
}

void dlcreate(){
	char ch;
	do{
		struct Node *temp, *ptr;
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp -> LEFT = NULL;
		temp -> RIGHT = NULL;
		printf("\nEnter data: ");
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
		printf("Do you want to continue? (Y / N)");
		scanf(" %c", &ch);
	}while(ch == 'y' || ch == 'Y');
}

void dldisplay(){
	int i = 0;
	if(start == NULL)
		printf("Doubly Linked List empty!\n");
	else{
		printf("\nCONTENTS OF LIST: ");
		struct Node *ptr;
		ptr = start;
		while(ptr != NULL){
			printf("%d ", ptr -> data);
			ptr = ptr -> RIGHT;
		}
	}
	printf("\n\n");
}

void dlfirstinsert(){
	struct Node *temp;
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp -> LEFT = NULL;
	temp -> RIGHT = NULL;
	printf("\nEnter data: ");
	scanf("%d", &temp -> data);
	temp -> RIGHT = start;
	start -> LEFT = temp;
	start = temp;
}

void dlendinsert(){
	struct Node *temp, *ptr;
	ptr = start;
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp -> LEFT = NULL;
	temp -> RIGHT = NULL;
	printf("\nEnter data: ");
	scanf("%d", &temp -> data);
	while(ptr -> RIGHT != NULL){
		ptr = ptr -> RIGHT;
	}
	ptr -> RIGHT = temp;
	temp -> LEFT = ptr;
}

void dlinsertbefore(){
	int pos, i = 0;
	struct Node *temp, *ptr, *ins;
	ptr = start;
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp -> LEFT = NULL;
	temp -> RIGHT = NULL;
	printf("\nEnter position to insert: ");
	scanf("%d", &pos);
	printf("Enter data: ");
	scanf("%d", &temp -> data);
	for(i = 0; i < pos-1; i++);
		ptr = ptr -> RIGHT;
	ins = ptr -> LEFT;
	ptr -> LEFT = temp;
	temp -> LEFT = ins;
	ins -> RIGHT = temp;
	temp -> RIGHT = ptr;
}

void dlinsertafter(){
	int pos, i = 0;
	struct Node *temp, *ptr, *ins;
	ptr = start;
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp -> LEFT = NULL;
	temp -> RIGHT = NULL;
	printf("\nEnter position to insert: ");
	scanf("%d", &pos);
	printf("Enter data: ");
	scanf("%d", &temp -> data);
	for(i = 0; i < pos - 1; i++);
		ptr = ptr -> RIGHT;
	ins = ptr -> RIGHT;
	ptr -> RIGHT = temp;
	temp -> LEFT = ptr;
	ins -> LEFT = temp;
	temp -> RIGHT = ins;
}

void dlfirstdelete(){
	if(start == NULL)
		printf("Doubly Linked List empty!\n");
	else{
		struct Node *temp;
		temp = start;
		printf("DELETED: %d\n\n", temp -> data);
		start = start -> RIGHT;
		free(temp);
	}
}

void dlenddelete(){
	if(start == NULL)
		printf("Doubly Linked List empty!\n");
	else{
		struct Node *temp, *ptr;
		temp = start;
		while(temp -> RIGHT != NULL){
			temp = temp -> RIGHT;
		}
		ptr = temp -> LEFT;
		ptr -> RIGHT = NULL;
		printf("DELETED: %d\n\n", temp -> data);
		free(temp);
	}
}

void dldeletebefore(){
	if(start == NULL)
		printf("Doubly Linked List empty!\n");
	else{
		int i, pos;
		struct Node *temp, *ptr, *pre;
		temp = start;
		printf("Enter position to delete: ");
		scanf("%d", &pos);
		for(i = 0; i < pos - 1; i++)
			temp = temp -> RIGHT;
		pre = temp -> LEFT;
		ptr = temp -> RIGHT;
		pre -> RIGHT = ptr;
		ptr -> LEFT = pre;
		printf("DELETED: %d\n\n", temp -> data);
		free(temp);
	}
}

void dldeleteafter(){
	if(start == NULL)
		printf("Doubly Linked List empty!\n");
	else{
		int i, pos;
		struct Node *temp, *ptr, *pre;
		temp = start;
		printf("Enter position to delete: ");
		scanf("%d", &pos);
		for(i = 0; i < pos; i++)
			temp = temp -> RIGHT;
		pre = temp -> LEFT;
		ptr = temp -> RIGHT;
		pre -> RIGHT = ptr;
		ptr -> LEFT = pre;
		printf("DELETED: %d\n\n", temp -> data);
		free(temp);
	}
}

void dldeletefull(){
	struct Node *temp;
	temp = start;
	while(start -> RIGHT != NULL){
		free(temp);
		temp = start -> RIGHT;
	}
	free(start);
	printf("\nDoubly Linked List emptied!\n\n");
}
