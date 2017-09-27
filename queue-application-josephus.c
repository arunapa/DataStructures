//solution by circular linked list
#include <stdio.h>
#include <malloc.h>

struct node{
	int pos;
	struct node *NEXT;
} *start, *ptr, *temp;

void createList(int n){
	int i;
	for(i = 2; i <= n; i++){
		temp = malloc(sizeof(struct node));
		ptr -> NEXT = temp;
		temp -> pos = i;
		ptr = temp;
	}
	ptr -> NEXT = start;
}

int lastPos(int n, int k){
	int count, i;
	createList(n);
	for(count = n; count > 1; count --){
		for(i = 0; i < k - 1; i++)
			ptr = ptr -> NEXT;
			ptr -> NEXT = ptr -> NEXT -> NEXT;
	}
	return ptr -> pos;
}

int main(){
	int n, k;
	printf("Enter n: ");
	scanf("%d", &n);
	printf("Enter k: ");
	scanf("%d", &k);
	start = (struct node *)malloc(sizeof(struct node));
	start -> pos = 1;
	ptr = start;
	printf("Last player left is: %d", lastPos(n, k));
	return 0;
}
