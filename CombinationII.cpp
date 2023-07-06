//Recursion 
T.C:-O(n*2^n)
S.C:-(n* x) where x is the no of subsets
#include<bits/stdc++.h>
void solve(vector<int>& arr,int n ,int target,vector<vector<int>>& ans,vector<int>& ds,
int ind){
	if(target==0){
		ans.push_back(ds);
		return ;
	}
	for(int i=ind;i<n;i++){
		if(i>ind && arr[i]==arr[i-1]) continue;
		if(arr[i] > target) break;
		//take
		ds.push_back(arr[i]);
		solve(arr,n,target-arr[i],ans,ds,i+1);
		ds.pop_back();
	}
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	sort(arr.begin(),arr.end());
	vector<vector<int>>ans;
	vector<int>ds;
	solve(arr,n,target,ans,ds,0);
	return ans;
}
