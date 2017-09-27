//simple stack program
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void push(char c, char stack[], int *top){
	if(*top == -1)
		*top = 0;
	else
		(*top)++;
	stack[*top] = c;
}

void pop(char stack[], int *top){
	printf("%c", stack[*top]);
	(*top)--;
}

void toPostFix(char E[]){
	char stack[100];
	stack[0] = '(';
	E[strlen(E)] = ')';
	int top = 0;
	
	for(int i = 0; i < strlen(E); i++){
		switch(E[i]){
			case '^':
			case '(':
				push(E[i], stack, &top);
				break;
			case ')':
				while(stack[top] != '('){
					pop(stack, &top);
				}
				top--;
				break;
			case '+':
			case '-':
				if(stack[top] == '*' || stack[top] == '/' || stack[top] == '^' ||
				stack [top] == '+' || stack[top] == '-'){
					pop(stack, &top);
					push(E[i], stack, &top);
				}
				else
					push(E[i], stack, &top);
				break;
			case '/':
			case '*':
				if(stack[top] == '*' || stack[top] == '/' || stack[top] == '^'){
					pop(stack, &top);
					push(E[i], stack, &top);
				}
				else
					push(E[i], stack, &top);
				break;
			default:
				printf("%c", E[i]);
		}
	}
}

int main(){
	char E[100];
	printf("Enter expression: ");
	gets(E);
	toPostFix(E);
	return 0;
}
