//Brute Force Approach
T.C:-O(n2)
S.C:-O(1)
#include <bits/stdc++.h>
int LongestSubsetWithZeroSum(vector < int > arr) {
  int n=arr.size();
  int maxi=0;
  for(int i=0;i<n;i++){
    int sum=0;
    for(int j=i;j<n;j++){
      sum+=arr[j];
      if(sum==0){
        maxi=max(maxi,j-i+1);
      }
    }
  }
  return maxi;
}


//Optimal solution
T.C:-O(n)
S.C:-O(n)
#include <bits/stdc++.h>
int LongestSubsetWithZeroSum(vector < int > arr) {
  int n=arr.size();
  int sum=0;
  int ans=0;
  unordered_map<int,int>mp;//(sum,index)
  for(int i=0;i<n;i++){
    sum+=arr[i];
    if(sum==0){
      ans=i+1;
    }
    else{
      if(mp.find(sum)!=mp.end()){
        ans=max(ans,(i-mp[sum]));
      }
      else{
        mp[sum]=i;
      }
    }
  }
  return ans;
}
