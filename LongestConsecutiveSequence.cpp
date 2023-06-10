//Brute Force Approach
T.C:-O(n+n log n) -~ O(n log n)
S.C:-O(1)
#include <bits/stdc++.h>
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    sort(arr.begin(),arr.end());
    int ans=1;
    int curr=1;
    int prev=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]==prev+1){
            curr++;
        }
        else if(arr[i]!=prev+1 && arr[i]!=prev){
            curr=1;
        }
        prev=arr[i];
        ans=max(ans,curr);
    }
    return ans;
}


//Optimal solution
T.C:-O(n)
S.C:-O(n)
#include <bits/stdc++.h>
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    unordered_set<int>hash;
    for(int num:arr){
        hash.insert(num);
    }
    int ans=0;
    for(int num:arr){
        //check is the num is the starting point of the sequence i.e its prev num not present
        if(!hash.count(num-1)){
            //starting the sequence
            int curr=num;
            int count=1;
            //till the time the next elements are present
            while(hash.count(curr+1)){
                //make the next element curr and search for its next
                curr+=1;
                count+=1;
            }
            ans=max(ans,count);
        }
    }
    return ans;
}
