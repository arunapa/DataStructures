#include <iostream>
#include <vector>
using std::vector;

void merge(vector<int> &a, int l, int r, int m){
	int n1 = m - l + 1;
	int n2 = r - m;
	vector<int> l1(n1), l2(n2);
	
	for(int i = 0; i < n1; i++)
		l1[i] = a[i + l];
	for(int i = 0; i < n2; i++)
		l2[i] = a[i + m + 1];
		
	int x = 0, y = 0, z = l;
	while(x < n1 && y < n2){
		if(l1[x] <= l2[y]){
			a[z] = l1[x];
			x++;
		}
		else{
			a[z] = l2[y];
			y++;
		}
		z++;
	}
	while(x < n1){
		a[z] = l1[x];
		x++;
		z++;

	}
	while(y < n2){
		a[z] = l2[y];
		y++;
		z++;
	}
}
void mergesort(vector<int> &a, int l, int r){
	if(l < r){
		int m = (l + r) / 2;
		mergesort(a, l, m);
		mergesort(a, m + 1, r);
		merge(a, l, r, m);
	}
}

int main(){
	int n;
	std::cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
	mergesort(a, 0, n - 1);
	for(int i = 0; i < n; i++)
		std::cout << a[i] << "\n";
	return 0;
}
