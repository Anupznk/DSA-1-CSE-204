#include<iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

#define MOD 1000000007
int faces[101];
long long table[101][10001];

void printTable(int n, int sum) {
    for (int i = 0; i<=n; i++) {
        for (int j = 0; j<=sum; j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}

long long diceThrow(int n, int sum) {
    // cumulative sum approach

    table[0][0] = 1;
    for (int i = 1; i<=n; i++) {
        for (int j = i; j<= sum; j++) {

            table[i-1][j] = (table[i-1][j-1] + table[i - 1][j])%MOD;
            //  calculating cumulative sum of the previous row
            if (j - (faces[i] + 1) >= 0){
                table[i][j] = table[i-1][j-1] - table[i-1][j - (faces[i] + 1)] + MOD;
            } else {
                table[i][j] = table[i-1][j-1];
            }
            table[i][j] %= MOD;
            printTable(n, sum);
            cout<< endl;
        }
    }
    return (table[n][sum])%MOD;
}

int main() {
    int n, s;
    ifstream myStream ("test.txt", ios::in);
    if (!myStream.is_open()) {
        cout << "Error accessing the file" << endl;
        exit(1);
    }
    myStream >> n >> s;

    for (int i = 1; i<=n; i++) {
        int face;
        myStream >> face;
        faces[i] = face;
    }
    myStream.close();
    cout << diceThrow(n, s);
}
