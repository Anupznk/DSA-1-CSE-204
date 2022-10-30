#include<bits/stdc++.h>
using namespace std;

int maxRevenue(int m, int sites[], int revenue[], int n, int t){
    int solution[m+1];
    memset(solution, 0, sizeof(solution));
    int nextbb = 0;

    for(int i = 1; i <= m; i++){
        if(nextbb > n){ // meaning all the available billboards are done
            solution[i] = solution[i-1];    // now all we can do is copy the revenue for the rest of the miles,
                                           // there is no option to increase the revenue since we are out of billboards
        } else{
            if(i != sites[nextbb]) {
                solution[i] = solution[i-1]; // just copying the previous revenue since we do not have any billboard available for i-th mile
            } else{ // we have billboards available for this position
                if(i<=t){  // we are less than or equal to t distance from the starting position
                          // meaning we can place only 1 billboard

                    if(solution[i-1] > revenue[nextbb]){
                        solution[i] = solution[i-1];
                    } else{
                        solution[i] = revenue[nextbb];
                    }
                } else { // we have two options now
                    solution[i] = max(solution[i-t-1]+revenue[nextbb], // 1. take the next billboard and add revenue
                                                  solution[i-1]);     // 2. do not take the next billboard
                }
                nextbb++;
            }
        }
    }
    return solution[m];
}

int main(){

    int miles = 20;
    int sites[] = {6, 7, 12, 13, 14};
    int revenue[] = {5, 6, 5, 3, 2};
    int n = sizeof(sites)/sizeof(sites[0]);
    int t = 5;
    cout << maxRevenue(miles, sites, revenue, n, t) << endl;
}
