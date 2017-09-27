





#include <stdio.h>

int linear_search(int a[], int n, int x) {
	int i;
	for(i = 0; i < n; i++){
		if(a[i] == x)
			return i;
	}
	return -1;
}

int main() {
	int n, a[20], i, x, index;
	printf("Enter size: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("Enter element to search for: ");
	scanf("%d", &x);
	index = linear_search(a, n, x);
	if(index != -1)
		printf("Element present at index %d", index);
	else
		printf("Element not found!");
}

