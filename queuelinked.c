//queue as linked list
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node{
	int data;
	struct Node *NEXT;
} *front = NULL, *rear = NULL;

void enqueue(){
	char ch;
	struct node *temp;
	do{
		temp = (struct node *)malloc(sizeof(struct node));
		temp -> NEXT = NULL;
		printf("Enter data: ");
		scanf("%d", &temp -> data);
		if(rear == NULL){
			front = temp;
			rear = temp;
		}
		else{
			rear -> NEXT = temp;
			rear = temp;
		}
		printf("Want to continue? (Y/N) ");
		scanf(" %c", &ch);
	}while(ch == 'y' || ch == 'Y');
}

void dequeue(){
	char ch;
	struct node *temp;
	do{
		if(front == NULL){
			rear == NULL;
			printf("Queue Empty!");
			break;
		}
		temp = front;
		printf("DELETED: %d\n", temp -> data);
		front = front -> NEXT;
		free(temp);
		printf("Want to continue? (Y/N) ");
		scanf(" %c", &ch);
	}while(ch == 'y' || ch == 'Y');
}

void peek(){
	if(front == NULL){
		printf("Queue Empty");
	}
	else{
		printf("QUEUE: ");
		struct node *temp;
		temp = front;
		while(temp != NULL){
			printf("%d ", temp -> data);
			temp = temp -> NEXT;
		}
	}
}

void isEmpty(){
	if(rear == NULL)
		printf("Queue Empty!");
	else
		printf("Queue not Empty!");
}

int main(){
	int op;
	do{
		printf("MENU\n----\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Peek\n");
		printf("4. isEmpty\n");
		printf("5. EXIT\n\n");
		printf("Enter option: ");
		scanf("%d", &op);
		printf("\n");
		switch(op){
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				peek();
				break;
			case 4:
				isEmpty();
				break;
			case 5:
				exit(0);
		}
		printf("\n\n");
	}while(op > 0);
	return 0;
}
