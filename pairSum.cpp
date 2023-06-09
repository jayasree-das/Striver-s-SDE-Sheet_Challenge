//brute force approach
T.C:-O(n2+nlogn)
S.C:-O(1)
#include <bits/stdc++.h>
vector<vector<int>> pairSum(vector<int> &arr, int s){
   sort(arr.begin(),arr.end());
   int n=arr.size();
   vector<vector<int>>temp;
   vector<int>ans;
   for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
         if(arr[i]+arr[j]==s){
            ans.push_back(arr[i]);
            ans.push_back(arr[j]);
            temp.push_back(ans);
            ans.clear();
         }
      }
   }
   return temp;
}


//Better solution(HASHING)
T.C:-O(n+n log n)
S.C:-O(n)
#include <bits/stdc++.h>
vector<vector<int>> pairSum(vector<int> &arr, int s){
   int cnt=0;
   vector<vector<int>>ans;
   unordered_map<int,int>mp;
   for(int i=0;i<arr.size();i++){
      if(mp[s-arr[i]]){
         int val=mp[s-arr[i]];
         vector<int>temp;
         while(val--){
            temp.push_back(min(arr[i],s-arr[i]));
            temp.push_back(max(arr[i],s-arr[i]));
            ans.push_back(temp);
         }
      }
      mp[arr[i]]++;
   }
   sort(ans.begin(),ans.end());
   return ans;
}


//Optimal solution
T.C:-O(n log n+n)
S.C:-O(1)
#include <bits/stdc++.h>
vector<vector<int>> pairSum(vector<int> &arr, int s){
   sort(arr.begin(),arr.end());
   int n=arr.size();
   vector<vector<int>>ans;
   int j=0;
   for(int i=1;i<n;i++){
      int sum=arr[j]+arr[i];
      if(sum==s){
         vector<int>temp;
         temp.push_back(arr[j]);
         temp.push_back(arr[i]);
         ans.push_back(temp);
      }
      if((sum>s) || ((i==n-1) && (j<n))){
         j++;
         i=j;
      }
   }
   return ans;
}
