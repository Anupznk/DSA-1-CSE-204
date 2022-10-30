#include <bits/stdc++.h>
using namespace std;

int countWays(int arr[], int m, int N){
    int table[N + 1];
    memset(table, 0, sizeof(table));

    table[0] = 1;

    // count ways for all values up to 'N' and store the result
    for (int i = 1; i <= N; i++){
        for (int j = 0; j < m; j++){
            // if i >= arr[j] then accumulate count for value 'i' as ways to form value 'i-arr[j]'
            if (i >= arr[j])
                table[i] += table[i - arr[j]];
        }
    }

    for (int i = 0; i <= N; i++){
        cout << table[i] << "  ";
    }

    return table[N];
}

int main(){
    int arr[] = {1, 5, 6};
    int m = sizeof(arr) / sizeof(arr[0]);
    int N = 6;
    int ans = countWays(arr, m, N);
    cout << endl << "Total number of ways: " << ans;
}

/*
    6
    5 + 1
    1 + 5
    1 + 1 + 1 + 1
*/
