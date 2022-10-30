#include <bits/stdc++.h>

using namespace std;

class Job{
public:
    int profit;
    int deadline;

    Job(){
    }

    Job(int p, int d){
        profit = p;
        deadline = d;
    }

    void printJob(){
        cout << "Profit: " << profit << ", Deadline: " << deadline <<endl;
    }
};

bool compare(Job j1, Job j2){
    return j1.profit > j2.profit;
}

int main(){
    Job jobs[] = { { 7, 5 }, { 6, 5 }, { 5, 2 }, { 4, 7 }, { 3, 7 }, { 3, 7 }, { 3, 6 }, { 2, 7 }, { 2, 1 }, { 2, 5 }, { 2, 3 }, { 2, 1 }, { 1, 1 } };
    int n = sizeof(jobs) / sizeof(jobs[0]);
    sort(jobs, jobs + n, compare);

    int maxDeadline = jobs[0].deadline;

    for (int i = 1; i<n; i++){
        if (maxDeadline < jobs[i].deadline)
            maxDeadline = jobs[i].deadline;
    }

    bool slots[maxDeadline];
    for (int i = 0; i<n; i++){
        slots[i] = false;
    }
    double maxProfit = 0;

    for (int i = 0; i<n; i++){
        // trying the allot a slot for the current job
        for (int j = jobs[i].deadline - 1; j>=0; j--){
            if (!slots[j]){
                slots[j] = true;
                maxProfit += jobs[i].profit;
                cout << "Profit added: " << jobs[i].profit <<  " | Deadline: " << jobs[i].deadline << endl;
                break;
            }
        }
    }
    cout<<maxProfit;

}
