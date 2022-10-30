#include <iostream>
#include<vector>
using namespace std;

int LIS(int arr[], int n){
    int table[n+1];

    for (int i=0; i<=n; i++){
        table[i] = 1;   // each element is an increasing subsequence of size 1
    }

    vector<vector<int> > sequences (n+1, vector<int>());

    for (int i=1; i<=n; i++){
        for (int j=0; j<i; j++){
            if (arr[i] > arr[j]){ // found increasing sequence
                if (table[j] + 1 > table[i]){
                    table [i] = table[j] + 1;
                    sequences[i].push_back(arr[j]);
                }
            }
        }
        sequences[i].push_back(arr[i]);
    }

    for (int i=0; i<=n; i++){
        cout << table[i] << " ";
    }
    cout << endl;

    int maxIndex = 0;
    int maxVal = INT_MIN;
    for (int i=0; i<=n; i++){
        if (maxVal < table[i]){
            maxVal = table[i];
            maxIndex = i;
        }
    }

    cout << "Longest increasing subsequence: ";
    for (int i = 0; i<sequences[maxIndex].size(); i++) {
        cout << sequences[maxIndex][i] << " ";
    }
    cout << endl;

    return maxVal;
}

int main(){
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<< LIS(arr, n);
}
