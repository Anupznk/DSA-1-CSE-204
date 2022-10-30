#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int left, int mid, int right) {

    int leftArrLen = mid - left + 1;
    int rightArrLen = right - mid;

    for (int i = 0; i<leftArrLen; i++) {
        leftArr[i] = arr[left + i];
    }

    for (int i = 0; i<rightArrLen; i++) {
        rightArr[i] = arr[mid + i + 1];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < leftArrLen && j < rightArrLen) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
            k++;
        } else {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }

    while(i < leftArrLen) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while(j < rightArrLen) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

void printSorted(int arr1[], int arr2[], int n) {
    cout << "Merge Sort\tQuick Sort" << endl;
    cout << "----------\t----------" << endl;
    for (int i = 0; i<n; i++) {
        cout << arr1[i] << "\t\t";
        cout << arr2[i];
        cout << endl;
    }
}

void swapNums(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int partition (int arr[], int left, int right) {
    int pivot = arr[right];     // taking the last element of the sub array as pivot
    int i = left - 1;
    int j;
    for (j = left; j<right; j++) {
        if (pivot > arr[j]){    // if pivot > current element, we need to bring the current element,
                                // which is smaller than pivot, to the left of the pivot

            i++;                // i leads to the place where the pivot needs to sit after
                                // shifting all the elements that are smaller than the pivot to the left of the pivot
            swapNums(arr[i], arr[j]);
        }
    }
    swapNums(arr[right], arr[i+1]);
    return i + 1;
}

int partition_random(int arr[], int left, int right){
    srand(time(0));
    int random = left + rand() % (right - left);

    swap(arr[random], arr[right]);

    return partition(arr, left, right);
}

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int q = partition(arr, left, right);    // element of q is in the right place

        quickSort(arr, left, q-1);
        quickSort(arr, q+1, right);
    }
}
}
