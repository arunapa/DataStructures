//simple queue program
#include <stdio.h>
#include <stdlib.h>

void enqueue(int Q[], int size, int *front, int *rear){
	char ch;
	do{
		if(*rear == size){
			printf("Queue Full!");
			break;
		}
		else{
			if(*rear == -1 && *front == -1){
				*rear = 0;
				*front = 0;
			}
			printf("Enter data: ");
			scanf("%d", &Q[*rear]);
			(*rear)++;
			printf("Want to continue? (Y/N) ");
			scanf(" %c", &ch);
		}
	}while(ch == 'y' || ch == 'Y');
}

void dequeue(int Q[], int size, int *front, int *rear){
	char ch;
	do{
		if(*front == - 1){
			printf("Queue Empty!");
			break;
		}
		else{
			printf("DELETED: %d", Q[*front]);
			(*front)++;
			printf("\nWant to continue? (Y/N) ");
			scanf(" %c", &ch);
			if(*front == *rear){
				*front = -1;
				*rear = -1;
			}
		}
	}while(ch == 'y' || ch == 'Y');
}

void peek(int Q[], int size, int *front, int *rear){
	if(*rear == - 1){
		printf("Queue Empty");
	}
	else{
		int i;
		printf("QUEUE: ");
		for(i = *front; i < *rear; i++)
			printf("%d ", Q[i]);
	}
}

void isEmpty(int Q[], int size, int *front, int *rear){
	if(*rear == -1)
		printf("Queue Empty!");
	else
		printf("Queue not Empty!");
}

void isFull(int Q[], int size, int *front, int *rear){
	if(*rear == size)
		printf("Queue Full!");
	else
		printf("Queue not Full!");
}

int main(){
	int Q[30], size, front = -1, rear = -1, op;
	printf("Enter queue size: ");
	scanf("%d", &size);
	printf("\n");
	do{
		printf("MENU\n----\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Peek\n");
		printf("4. isEmpty\n");
		printf("5. isFull\n");
		printf("6. EXIT\n\n");
		printf("Enter option: ");
		scanf("%d", &op);
		printf("\n");
		switch(op){
			case 1:
				enqueue(Q, size, &front, &rear);
				break;
			case 2:
				dequeue(Q, size, &front, &rear);
				break;
			case 3:
				peek(Q, size, &front, &rear);
				break;
			case 4:
				isEmpty(Q, size, &front, &rear);
				break;
			case 5:
				isFull(Q, size, &front, &rear);
				break;
			case 6:
				exit(0);
		}
		printf("\n\n");
	}while(op > 0);
	return 0;
}
