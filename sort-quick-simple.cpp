#include <iostream>
#include <vector>

using std::vector;

int partition(vector<int> &arr, int l, int r){
	int p = l;
	int i = l;
	int j = 0;

	for(int x = l + 1; x < r; x++){
		else if(arr[x] <= arr[p] && j == 0)
			i++;
		else if(arr[x] > arr[p] && j == 0)
			j = x;
		else if(arr[x] <= arr[p] && j != 0){
			int temp = arr[x];
			arr[x] = arr[j];
			arr[j] = temp;
			i++;
			j++;
		}
	}
	int temp = arr[i];
	arr[i] = arr[p];
	arr[p] = temp;
	/*std::cout << "L = " << l << " R = " << r <<" P = " << p << "\n";
	for(int i = 0; i < 5; i++)
		std::cout << arr[i] << ' ';
	std::cout << "\n";*/
	return p;
}
void quicksort(vector<int> &arr, int l, int r){
	if(l < r){
		int pi = partition(arr, l, r);
		quicksort(arr, l, pi - 1);
		quicksort(arr, pi + 1, r);
	}
}

int main(){
	int n;
	std::cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		std::cin >> arr[i];
	quicksort(arr, 0, n);
	for(int i = 0; i < n; i++)
		std::cout << arr[i] << ' ';
	return 0;
}
