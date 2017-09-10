//simple stack program
#include <stdio.h>
#include <stdlib.h>

void push(int stack[], int size, int *top){
	char ch;
	do{
		if(*top == size - 1){
			printf("Stack Overflow!");
			break;
		}
		else{
			if(*top == -1)
				*top = 0;
			else
				(*top)++;
			printf("Enter data: ");
			scanf("%d", &stack[*top]);
			printf("Want to continue? (Y/N) ");
			scanf(" %c", &ch);
		}
	}while(ch == 'y' || ch == 'Y');
}

void pop(int stack[], int size, int *top){
	char ch;
	do{
		if(*top == - 1){
			printf("Stack Underflow!");
			break;
		}
		else{
			printf("Popped: %d", stack[*top]);
			(*top)--;
			printf("\nWant to continue? (Y/N) ");
			scanf(" %c", &ch);
		}
	}while(ch == 'y' || ch == 'Y');
}

void display(int stack[], int *top){
	if(*top == - 1){
		printf("Stack Underflow!");
	}
	else{
		int i;
		printf("STACK: ");
		for(i = 0; i <= *top; i++)
			printf("%d ", stack[i]);
	}
}

int main(){
	int stack[30], size, top = -1, op;
	printf("Enter stack size: ");
	scanf("%d", &size);
	printf("\n");
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
				push(stack, size, &top);
				break;
			case 2:
				pop(stack, size, &top);
				break;
			case 3:
				display(stack, &top);
				break;
			case 4:
				exit(0);
		}
		printf("\n\n");
	}while(op > 0);
	return 0;
}
