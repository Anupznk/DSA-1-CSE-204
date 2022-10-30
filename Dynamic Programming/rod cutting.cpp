#include<bits/stdc++.h>
using namespace std;

int bottomUpCutRod(int price[], int n){
    int val[n+1] = {0};
    val[0] = 0;

    for (int i = 1; i<=n;i++) {
        int maxRevenue = INT_MIN;
        for (int j = 0; j<=i; j++) {
            if(maxRevenue < price[j] + val[i-j-1]){
                maxRevenue = price[j] + val[i-j-1];
            }
        }
        val[i] = maxRevenue;
    }

    for (int i = 0; i<=n;i++) {
        cout << val[i] << " ";
    }
    cout << endl;

    return val[n];
}

int main(){

    int n;
    int price[] = {1  , 5  , 8  , 9 , 10 , 13 , 17 , 18, 22, 25, 30};

    n = sizeof(price)/sizeof(price[0]);

    cout << bottomUpCutRod(price, n);
}
