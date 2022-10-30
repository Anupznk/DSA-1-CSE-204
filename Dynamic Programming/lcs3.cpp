#include <bits/stdc++.h>
using namespace std;

int max_of_three(int a, int b, int c) {
    return max(max(a,b),c);
}

int lcs3(string s1, string s2, string s3) {
    int m = s1.size();
    int n = s2.size();
    int o = s3.size();
    int i,j,k;
    int table[m+1][n+1][o+1];

    for(i = 0;i<=m; i++){
        for(j = 0;j<=n; j++){
            for(k =0;k<=o;k++){
                if(i==0 || j == 0 || k==0)
                    table[i][j][k] = 0;
                else if((s1[i-1] == s2[j-1]) && (s1[i-1] == s3[k-1])) { // all three chars are the same
                    table[i][j][k] = 1+table[i-1][j-1][k-1];

                }
                else {
                    table[i][j][k] = max_of_three(table[i-1][j][k], table[i][j-1][k], table[i][j][k-1]);
                }
            }
        }
    }

    int index = table[m][n][o];
    char lcs [index + 1];
    lcs[index] = '\0';

    i = m;
    j = n;
    k = o;
    while (i >= 0 && j >= 0 && k >= 0){
        if ((s1[i-1] == s2[j-1]) && (s1[i-1] == s3[k-1])){
            lcs[index-1] = s1[i-1];
             cout << i-1 << ": " << s1[i-1] << " ";
            index--; i--; j--, k--;   // going diagonally up

        }
        else if ((table[i-1][j][k] > table[i][j-1][k]) && (table[i-1][j][k] > table[i][j][k-1])){ // check from here
            i--;
        }
        else if ((table[i][j-1][k] > table[i-1][j][k]) && (table[i][j-1][k] > table[i][j][k-1])){
            j--;
        }
        else {
            k--;
        }
    }
    cout << "The LCS is: " << lcs << endl;

    return table[m][n][o];
}

int main() {
    string a, b, c;
    cin >> a >> b >> c;

    cout << lcs3(a, b, c);
}
