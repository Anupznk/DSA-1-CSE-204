#include <bits/stdc++.h>
using namespace std;

struct Job{
    int start, finish, profit;
};

bool myfunction(Job s1, Job s2){
    return (s1.finish < s2.finish);
}

// A Binary Search based function to find the "latest" job
// (before current job) that doesn't conflict with current
// job.  "index" is index of the current job.  This function
// returns -1 if all jobs before index conflict with it.
// The array jobs[] is sorted in increasing order of finish time.
int binarySearch(Job jobs[], int index){
    int lo = 0, hi = index - 1;

    while (lo <= hi){
        int mid = (lo + hi) / 2;
        if (jobs[mid].finish <= jobs[index].start){
            if (jobs[mid + 1].finish <= jobs[index].start)
                lo = mid + 1;
            else
                return mid;
        }
        else
            hi = mid - 1;
    }
    return -1;
}

int findMaxProfit(Job arr[], int n){
    // Sort jobs according to least finish time
    sort(arr, arr+n, myfunction);

    int table[n];
    table[0] = arr[0].profit;

    for (int i=1; i<n; i++){
        // Find profit including the current job
        int inclProf = arr[i].profit;
        int l = binarySearch(arr, i);
        if (l != -1)
            inclProf += table[l];

        // Store maximum of including and excluding
        table[i] = max(inclProf, table[i-1]);
    }

    for (int i=0; i<n; i++){
        cout << table[i] << " ";
    }

    return table[n-1];
}

int main(){
    Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int n = sizeof(arr)/sizeof(arr[0]);

    int ans = findMaxProfit(arr, n);
    cout << "\nOptimal profit: " << ans;
}







