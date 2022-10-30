#include<bits/stdc++.h>
using namespace std;

int knapsack(int capacity, int wt[], int val[], int n){
    // time and space O(N*W)

    int valueTable[n+1][capacity+1];

    for (int i = 0; i <= n; i++){
        for (int w = 0; w<=capacity; w++) {
            if (i == 0 || w == 0){
                valueTable[i][w] = 0;
            }
            else if (wt[i-1] <= w){  // w is the current max capacity for the optimal subproblem
                valueTable[i][w] = max(valueTable[i-1][w - wt[i-1]] + val[i-1],  // taking the i-1-th item and decreasing the wt by the wt of the i-1-th item
                                       valueTable[i-1][w]);   // not taking the i-1-th item and not decreasing the wt

            }
            else{   // when taking the i-1-th item exceeds the current max capacity
                valueTable[i][w] = valueTable[i-1][w];
            }
        }
    }

    for (int i = 0; i<=n; i++){
        for (int w = 0; w<=capacity; w++) {
            cout << valueTable[i][w] << "  ";
        }
        cout << endl;
    }
    cout<<"bottom right theke dekha start koro. jodi tar thik upore same value na thake tahole oi item tar jonnoi ei profit increase hoise\n";
    cout<<"erpor oi particular item er value ta current value theke minus kore check korbo seta tar uporer row te ache kina, thakle tar upore same value thakle\n";
    cout<<"upore jao jotokkhon tar upore different value ache, last er oi value ta je row theke asche sei element ta nao and continue.\n";

    return valueTable[n][capacity];
}

int main(){
    int val[] = { 5, 6, 12 };
    int wt[] = { 3, 1, 3 };
    int capacity = 5;
    int n = sizeof(val) / sizeof(val[0]);
    int ans = knapsack(capacity, wt, val, n);
    cout << "Max value: " << ans;
}








