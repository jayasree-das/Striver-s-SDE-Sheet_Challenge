More then (n/3) times

//Brute Force
T.C:-O(n2)
S.C:- O(1)
#include <bits/stdc++.h>
vector<int> majorityElementII(vector<int> &arr){
  int n=arr.size();
  vector<int>ans;
  for(int i=0;i<n;i++){
    if(ans.size()==0 || ans[0]!=arr[i]){
      int cnt=0;
      for(int j=0;j<n;j++){
        if(arr[j]==arr[i]){
          cnt++;
        }
      }
      if(cnt > n/3) ans.push_back(arr[i]);
    }
    
    if(ans.size()==2) break;
  } 
  return ans;
}


//Better solution
T.C:-O(n log n)
S.C:-O(n)
#include <bits/stdc++.h>
vector<int> majorityElementII(vector<int> &arr)
{
  int n=arr.size();
  vector<int>ans;//store the ans
  map<int,int>freq;
  int minFreq=(n/3)+1;//min freq of the majority elements
  for(int i=0;i<n;i++){
    freq[arr[i]]++;//marking the frequency
    if(freq[arr[i]]==minFreq){
      ans.push_back(arr[i]); //check the freq and push to ans
    }
    if(ans.size()==2) break;
  }
  return ans;
}

//optimal Solution(Extended MOORE'S VOTING ALGO)
T.C:-O(n)+O(n)
S.C:-O(1)
#include <bits/stdc++.h>
vector<int> majorityElementII(vector<int> &arr)
{
  int n=arr.size();
  int cnt1=0,cnt2=0;
  int ele1=INT_MIN;
  int ele2=INT_MIN;
  for(int i=0;i<n;i++){
    if(cnt1==0 && ele2!=arr[i]){
      cnt1=1;
      ele1=arr[i];
    }
    else if(cnt2==0 && ele1!=arr[i]){
      cnt2=1;
      ele2=arr[i];
    }
    else if(arr[i]==ele1) cnt1++;
    else if(arr[i]==ele2) cnt2++;
    else{
      cnt1--;
      cnt2--;
    }
  }
  cnt1=0,cnt2=0;
  for(int i=0;i<n;i++){
    if(arr[i]==ele1) cnt1++;
    if(arr[i]==ele2) cnt2++;
  }
  vector<int>ans;
  int minFreq=(n/3)+1;
  if(cnt1>=minFreq) ans.push_back(ele1);
  if(cnt2>=minFreq) ans.push_back(ele2);
  return ans;
}
