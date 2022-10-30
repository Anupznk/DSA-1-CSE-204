#include<bits/stdc++.h>
using namespace std;

int findMax(int arr[], int low, int high){
    if(high -  low == 1)
        return max(arr[low], arr[high]);
    if (high == low){
        return arr[high];
    }

    int mid = (low + high)/2;

    return max(findMax(arr, low, mid), findMax(arr, mid + 1, high));
}

int main(){
    int arr[] = {222222, 34, -1, 22, 333, 32232};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << findMax(arr, 0, n-1);

}
