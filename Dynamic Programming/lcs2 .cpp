#include <bits/stdc++.h>
using namespace std;

int lcs2(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();
    int i,j;
    int table[m+1][n+1];

    for(i = 0;i<=m; i++) {
        for(j = 0;j<=n; j++) {
            if(i==0 || j == 0)
                table[i][j] = 0;
            else if(s1[i-1] == s2[j-1]) { // if the chars match, take the diagonal and add 1
                table[i][j] = 1+table[i-1][j-1];
            }
            else {                      // if the chars do not match, take the max of the top and left values
                table[i][j] = max(table[i-1][j], table[i][j-1]);
            }
        }
    }

    for(i = 0;i<=m; i++) {
        if (i == 0)
            cout << "  ";
        else
            cout << s1[i-1] << " ";
        for(j = 0;j<=n; j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }

    int index = table[m][n];    // the value table[m][n] contains is the length of the LCS
    char lcs [index + 1];
    lcs[index] = '\0';

    i = m;
    j = n;
    while (i > 0 && j > 0){
        if (s1[i-1] == s2[j-1]) {
            lcs[index-1] = s1[i-1];
            index--; i--; j--;   // going diagonally up
            cout << "d";
        }
        else if (table[i-1][j] > table[i][j-1]) {   // the top one is bigger
            i--;    // going up
            cout << "u";
        }
        else {
            j--;    // going left
            cout<< "l";
        }
    }
    cout << endl<<  "The LCS is: " << lcs << endl;

  return table[m][n];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int ans = lcs2(s1, s2);
    cout << "Length of LCS: " << ans;
}
