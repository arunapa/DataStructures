#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node{
	int data;
	struct Node *NEXT, *BACK;
}*start = NULL;

void clcreate(){
	char ch;
	do{
		struct Node *temp, *ptr;
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp -> NEXT = NULL;
		temp -> BACK = NULL;
		printf("Enter data: ");
		scanf("%d", &temp -> data);
		if(start == NULL){
			start = temp;
			ptr = temp;
		}
		else{
			ptr -> NEXT = temp;
			temp -> BACK = ptr;
			ptr = temp;
		}
		temp -> NEXT = start;
		start -> BACK = temp;
		printf("Want to continue? (Y/N) ");
		scanf(" %c", &ch);
	}while(ch == 'y' || ch == 'Y');
}

void cldisplay(){
	if(start == NULL)
		printf("Circular Linked List empty!\n");
	else{
		struct Node *ptr;
		ptr = start;
		printf("LIST: ");
		do{
			printf("%d ", ptr -> data);
			ptr = ptr -> NEXT;
		}while(ptr != start);
	}
}

void clinsert(){
	int pos, i = 0;
	struct Node *temp, *ptr, *ins;
	ptr = start;
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp -> NEXT = NULL;
	temp -> BACK = NULL;
	printf("Enter index to insert: ");
	scanf("%d", &pos);
	printf("Enter data: ");
	scanf("%d", &temp -> data);
	if(pos == 0){ //first insert
		temp -> NEXT = start;
		ins = start -> BACK;
		start -> BACK = temp;
		ins -> NEXT = temp;
		temp -> BACK = ins;
		start = temp;
	}

	for(i = 0; i < pos-1; i++){
		if(ptr -> NEXT != start)
			ptr = ptr -> NEXT;
	}
	if(ptr -> NEXT == start){ //last insert
		ptr -> NEXT = temp;
		temp -> BACK = ptr;
		temp -> NEXT = start;
		start -> BACK = temp;
	}
	else{
		ins = ptr -> NEXT;
		ptr -> NEXT = temp;
		temp -> BACK = ptr;
		ins -> BACK = temp;
		temp -> NEXT = ins;
	}
}

void cldelete(){
	if(start == NULL)
		printf("Circular Linked List empty!\n");
	else{
		int i, pos;
		struct Node *temp, *ptr, *pre;
		temp = start;
		printf("Enter position to delete: ");
		scanf("%d", &pos);
		//single element list
		if(pos == 0 && start -> NEXT == start){
			printf("Deleted: %d", temp -> data);
			free(temp);
			start = NULL;
		}
		else if(pos == 0 && start != NULL){ // first delete
			printf("Deleted: %d", temp -> data);
			pre = start -> BACK;
			start = start -> NEXT;
			start -> BACK = pre;
			pre -> NEXT = start;
			free(temp);
		}
		else{
			for(i = 0; i < pos; i++){
				if(temp -> NEXT != start)
					temp = temp -> NEXT;
			}
			if(temp -> NEXT == start){ // last delete
				pre = temp -> BACK;
				pre -> NEXT = start;
				start -> BACK = pre;
				printf("Deleted: %d", temp -> data);
				free(temp);
			}
			else{
				pre = temp -> BACK;
				ptr = temp -> NEXT;
				pre -> NEXT = ptr;
				ptr -> BACK = pre;
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
				clcreate();
				break;
			case 2:
				clinsert();
				break;
   			case 3:
				cldelete();
				break;
			case 4:
				cldisplay();
				break;
			case 5:
				exit(0);
		}
		printf("\n\n");
	}while(op > 0);
	return 0;
}
