#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {5, 3, 4, 2, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 1; i<size; i++){
        int key = arr[i];       // select the first unsorted element
        int j = i - 1;
        for (int i = 0; i<size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        while (j>=0 && arr[j] > key){
            arr[j+1] = arr[j];  // shifts all the elements that are larger than the key
                                // in order to make room for the key to sit at the right place
            j--;
        }
        arr[j+1] = key;         // inserting the key in the right place
    }

    cout << "sorted array" << endl;
    for (int i = 0; i<size; i++){
        cout << arr[i] << " ";
    }


}













