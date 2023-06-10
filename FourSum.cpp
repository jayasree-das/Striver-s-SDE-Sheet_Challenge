//Brute Force Approach
T.C:-O(n4)
S.C:-O(1)
#include <bits/stdc++.h>
string fourSum(vector<int> arr, int target, int n) {
    string ans="";
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    int sum=arr[i]+arr[j];
                    sum+=arr[k];
                    sum+=arr[l];
                    if(sum == target){
                        ans="Yes";
                    }  
                }
            }
        }
    }
    if(ans != "Yes") ans="No";
    return ans;
}


//Better Solution
T.C:-O(n3 log m) //m is the size of the hashset and log m time is required for searching in hashset
S.C:-O(m)//space for hashset
#include <bits/stdc++.h>
string fourSum(vector<int> arr, int target, int n) {
    string ans="";
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<long long>hashset;
            for(int k=j+1;k<n;k++){
                long long sum=arr[i]+arr[j];
                sum+=arr[k];
                long long fourth=target-sum;
                if(hashset.find(fourth)!=hashset.end()){
                    ans="Yes";
                }
                else{
                    hashset.insert(arr[k]);
                }
            }
        }
    }
    if(ans != "Yes") ans="No";
    return ans;
}


//Better solution
T.C:-O(n3)
S.C:-O(1)
#include <bits/stdc++.h>
string fourSum(vector<int> arr, int target, int n) {
    sort(arr.begin(), arr.end());
    if(n < 4) return "No";
    bool flag = false;
    for(int i = 0; i < arr.size(); i++){
        for(int j = i+1; j < arr.size(); j++){
            long long sum =arr[i]+arr[j];
            long long newTarget=target-sum;
            int k = j+1;
            int l = n-1;
            while(k < l){
                int two_sum = arr[k] + arr[l];
                if(two_sum > newTarget){
                    l--;
                }else if(two_sum < newTarget){
                    k++;
                }else{
                    flag = true;
                    break;
                }
            }
        }
    }
    return flag ? "Yes" : "No";
}


//Optimal solution
T.C:-O(n2 log n)
S.C:-O(n)
#include <bits/stdc++.h>
string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    map<long long, pair<int,int>>mp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            long long sum=arr[i]+arr[j];
            if(mp.find(target - sum)!=mp.end()){
                if(mp[target-sum].first!=i && mp[target-sum].second!=i && mp[target-sum].first!=j && mp[target-sum].second!=j){
                    return "Yes";
                }
            }
            mp[sum]={i,j};
        }
    }
    return "No";
}
