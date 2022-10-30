#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {-2, -3, -4, -1, -2, -1, -5, -3};
    int n = sizeof(arr)/sizeof(arr[0]);

    int maxSoFar = arr[0];
    int maxEndingHere = arr[0];
    int startIndex = 0;
    int endIndex = 0;
    int s = 0;

    for (int i = 0; i < n; i++) {
        maxEndingHere += arr[i];
        if (maxEndingHere > maxSoFar){
            maxSoFar = maxEndingHere;
            startIndex = s;
            endIndex = i;
        }
        if (maxEndingHere < 0){
            maxEndingHere = 0;
            s = i + 1;

        }
    }
    for (int i = startIndex; i<=endIndex; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Max sum is: " << maxSoFar << endl;
}

/*
8
-2 -3 4 -1 -2 1 5 -3
*/
