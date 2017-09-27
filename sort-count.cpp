#include <cstdlib>
#include <iostream>
#include <vector>


using namespace std;

int main() {
    unsigned int n;
    cin >> n;
    vector<int> A(n);
    int freq[1001] = {0};
    for(int i = 0; i < n; i++){
        scanf("%d". &A[i]);
        freq[A[i]]++;
    }
    for(int  i = 0; i <= 1000; i++){
        if(freq[i]!=0){
            for(int j = 0; j < freq[i]; j++)
                printf("%d\n", i);
        }
    }
    return 0;
}

