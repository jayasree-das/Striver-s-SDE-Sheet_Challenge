//Recursive solution
T.C:-O(k*2^n) where O(2^n) for generating subsets and O(k) for inserting every subset in another data structure with average length k
S.C:-O(k*2^n)

#include <bits/stdc++.h> 
void solve(int ind,vector<int>& arr,int n,vector<vector<int>>& ans,
vector<int>& ds){
    ans.push_back(ds);
    for(int i=ind;i<n;i++){
        if(i!=ind && arr[i]==arr[i-1]) continue;

        ds.push_back(arr[i]);
        solve(i+1,arr,n,ans,ds);
        ds.pop_back();
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>>ans;
    vector<int>ds; //for storing each subset
    sort(arr.begin(),arr.end());//to keep track of duplicate elements
    solve(0,arr,n,ans,ds);
    return ans;
}
