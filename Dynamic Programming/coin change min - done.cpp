#include<bits/stdc++.h>
using namespace std;

int minCoins(int coins[], int numOfCoins, int money){
    int table[money + 1];
    int parent[money + 1] = {0};
    memset(table,-1,sizeof table); //<================
    table[0] = 0;

    for (int i = 1; i<=money; i++) {
        int minimum = INT_MAX;
        for (int j = numOfCoins-1; j>=0; j--) {
            if (coins[j] <= i){  // the j-th coin is a probable min
                if ( table[i- coins[j]]!=-1 and 1+table[i - coins[j]] < minimum){ //<==============
                    minimum = 1+table[i - coins[j]];
                    table[i] = minimum; //<===============
                    parent[i] = i - coins[j];
                }
            }
        }
    }

    cout << endl;
    for (int i = 0; i<=money; i++) {
        cout << table[i] << " ";
    }
    cout << endl;
    for (int i = 0; i<=money; i++) {
        cout << parent[i] << " ";
    }
    cout<<"\nbacktrack from the last entry of parent";
    return table[money];
}

int main(){
    int numOfCoins, money;
    cout << "Enter num of coins: ";
    cin >> numOfCoins;
    cout << "Enter amount: ";
    cin >> money;
    cout << "Enter coin values:\n";
    int coins[numOfCoins];
    for (int i = 0; i<numOfCoins; i++) {
        cin >> coins[i];
    }
    cout << endl << "Min num of coins: " << minCoins(coins, numOfCoins, money);
}













