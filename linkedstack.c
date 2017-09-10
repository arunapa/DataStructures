//stack as linked list
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node{
	int data;
	struct Node *NEXT;
}*top = NULL;

void push(){
	char ch;
	do{
		struct Node *temp;
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp -> NEXT = NULL;
		printf("Enter data: ");
		scanf("%d", &temp -> data);
		if(top == NULL){
			top = temp;
		}
		else{
			temp -> NEXT = top;
			top = temp;
		}
		printf("Want to continue? (Y/N) ");
		scanf(" %c", &ch);
	}while(ch == 'y' || ch == 'Y');
}

void pop(){
	char ch;
	struct Node *temp;
	temp = (struct Node *)malloc(sizeof(struct Node));
	do{
		if(top == NULL){
			printf("Stack Underflow!");
			break;
		}
		else{
			temp = top;
			top = top -> NEXT;
			printf("Popped: %d", temp -> data);
			free(temp);
			printf("\nWant to continue? (Y/N) ");
			scanf(" %c", &ch);
		}
	}while(ch == 'y' || ch == 'Y');
}

void display(){
	if(top == NULL)
		printf("Stack Underflow!");
	else{
		struct Node *temp;
		temp = top;
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
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Display stack\n");
		printf("4. EXIT\n\n");
		printf("Enter option: ");
		scanf("%d", &op);
		printf("\n");
		switch(op){
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
		}
		printf("\n\n");
	}while(op > 0);
	return 0;
}
