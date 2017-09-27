//https://www.hackerrank.com/challenges/insertion-sort/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void merge(vector<long int> &a, int l, int r, int m, long int &count){
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
            count += (n1 - x);
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
    /*for(int abc = 0; abc < z; abc++)
		cout << a[abc] << " ";
    cout << endl;*/
}
void mergesort(vector<long int> &a, int l, int r, long int &count){
	if(l < r){
		int m = (l + r) / 2;
		mergesort(a, l, m, count);
		mergesort(a, m + 1, r, count);
		merge(a, l, r, m, count);
	}
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
	    long int count = 0;
	    
        mergesort(a, 0, n - 1, count);
        cout << count << "\n";

    }
    return 0;
}

