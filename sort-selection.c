#include <stdio.h>

void selectionsort(int a[], int n){
	int i, j, min, temp;
	for(i = 0; i < n - 1; i++){
		min = i;
		for(j = i + 1; j < n; j++){
			if(a[j] < a[min])
				min = j;
		}
		if(min != i){
			temp = a[min];
			a[min] = a[i];
			a[i] = temp;
		}
	}
}
int main(){
	int a[20], n, i;
	printf("Enter array size: ");
	scanf("%d", &n);
	printf("Enter array: ");
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	selectionsort(a, n);
	printf("\nSORTED ARRAY\n");
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}
