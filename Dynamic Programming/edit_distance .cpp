#include<bits/stdc++.h>
using namespace std;

int minimum(int a, int b, int c) {
    return min(min(a,b),c);
}

int edit_distance(string s1, string s2, int m, int n) {
    int a[m+1][n+1];
    int i, j;

    for (i = 0; i<=m; i++) {
        for (j = 0; j<=n; j++) {
            if (i == 0)         //base case (first row)
                a[i][j] = j*2;

            else if (j == 0)    //base case (first col)
                a[i][j] = i*2;

            else if(s1[i-1] == s2[j-1]) {
                a[i][j] = a[i-1][j-1];  // if matched, then copy the value from the diagonal
            }
            else {                      // else find the min of left, top and diagonal and add 1 to it
                a[i][j] = minimum(a[i-1][j]+2,
                                  a[i][j-1]+2,
                                  a[i-1][j-1]+1);
            }
        }
    }
    for (i = 0; i<=m; i++) {
        for (j = 0; j<=n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return a[m][n];
}

int main() {
    string str1;
    string str2;
    cin >> str1 >> str2;
    int ans = edit_distance(str1, str2, str1.length(), str2.length());
    cout << ans;
}
