#include <stdio.h>

void insertionsort(int a[], int n){
	int i, j, m, temp;
	for(i = 1; i < n; i++){
		m = i;
		j = i - 1;
		while(j >= 0){
			if(a[m] < a[j]){
				temp = a[m];
				a[m] = a[j];
				a[j] = temp;
				m--;
			}
			j--;
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
	insertionsort(a, n);
	printf("\nSORTED ARRAY\n");
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}
