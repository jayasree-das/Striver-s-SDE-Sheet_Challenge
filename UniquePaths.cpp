//Brute Force(RECURSIVE)
T.C:-O(2^(m+n))
S.C:-O(max(m,n))
#include <bits/stdc++.h>
int solve(int i,int j,int m,int n){
    if(i==m-1 && j==n-1) return 1;
    if(i>=m || j>=n) return 0;
    else return solve(i+1,j,m,n)+solve(i,j+1,m,n);
} 
int uniquePaths(int m, int n) {
    return solve(0,0,m,n);
}


//Better solution(MEMOIZATION)
T.C:-O(m*n)
S.C:-O(m*n)
#include <bits/stdc++.h>
int solve(int i,int j,int m,int n,vector<vector<int>>& dp){
    if(i==m-1 && j==n-1) return 1;
    if(i>=m || j>=n) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    else return dp[i][j] = solve(i+1,j,m,n,dp)+solve(i,j+1,m,n,dp);
} 
int uniquePaths(int m, int n) {
    vector<vector<int>>dp(m,vector<int>(n,-1));
    return solve(0,0,m,n,dp);
}


//Optimal solution(COMBINATIONS)
T.C:-O(n-1) or O(m-1)
S.C:-O(1)
#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	int totalSteps=m+n-2;//(m-1)+(n-1)
    double ans=1;
    int right=n-1;//steps in right direction i.e col
    for(int i=1;i<=right;i++){
        //calculate the combinations in which those right steps can be given to reach the end
        ans=ans*(totalSteps-right+i)/i; //10C3=(8/1)*(9/2)*(10/3)
    }
    return (int)ans; 
}
