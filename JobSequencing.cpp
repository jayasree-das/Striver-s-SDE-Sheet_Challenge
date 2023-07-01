//Greedy solution
T.C:-O(n log n)+O(n*maxDeadline)
S.C:-O(maxDeadline)
#include <bits/stdc++.h>
#include <algorithm>
bool compare(vector<int>a,vector<int>b){
    return a[1]>b[1];
} 
int jobScheduling(vector<vector<int>> &jobs)
{
    //sort in deceasing profit order as we will greedily take max profit
    sort(jobs.begin(),jobs.end(),compare);

    int n=jobs.size();
    int maxDeadline=INT_MIN;
    //finding the maximum dealine among all the jobs
    for(int i=0;i<n;i++){
        maxDeadline=max(jobs[i][0],maxDeadline);
    }
    
    int profit=0;
    //indexing 1 is used for deadlines so +1 used
    //taking a vector with max deadline days to track when to complete which job
    vector<int>ans(maxDeadline+1,-1);
    for(int i=0;i<n;i++){
        int currDeadline=jobs[i][0];
        int currprofit=jobs[i][1];
        //we will try to do every job on the last day of deadline
        for(int j=currDeadline;j>0;j--){
            if(ans[j]==-1){
                profit+=currprofit;
                ans[j]=1;//marking that day as visited
                break;
            }
        }
    }
    return profit;
}


