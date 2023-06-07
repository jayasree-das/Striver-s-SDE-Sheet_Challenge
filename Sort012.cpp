//Brute Force

//Merge Sort
#include <bits/stdc++.h> 
void merge(int *arr,int low,int mid,int high){
   vector<int>temp;
   int left=low;
   int right=mid+1;
   while(left<=mid && right<=high){
      if(arr[left]<=arr[right]){
         temp.push_back(arr[left]);
         left++;
      }
      else{
         temp.push_back(arr[right]);
         right++;
      }
   }
   
   while(left<=mid){
      temp.push_back(arr[left]);
      left++;
   }
   while(right<=high){
      temp.push_back(arr[right]);
      right++;
   }

   for(int i=low;i<=high;i++){
      arr[i]=temp[i-low];
   }
}
void solve(int *arr,int low,int high){
   if(low>=high) return;
   int mid=(low+high)/2;
   solve(arr,low,mid);
   solve(arr,mid+1,high);
   merge(arr,low,mid,high);
}
void sort012(int *arr, int n)
{
   solve(arr,0,n-1);
}

T.C:-O(n log )
S.C:- O(n)
  
//sorting stl
#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   sort(arr,arr+n);
}
T.C:-O(n log n)
S.C:-O(1)
  
  
//Better solution
 #include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   int count0=0,count1=0,count2=0;
   for(int i=0;i<n;i++){
      if(arr[i]==0) count0++;
      if(arr[i]==1) count1++;
      if(arr[i]==2) count2++;
   }

   for(int i=0;i<count0;i++) arr[i]=0;
   for(int i=count0;i<count0+count1;i++) arr[i]=1;
   for(int i=count0+count1;i<n;i++) arr[i]=2;
}

T.C:-O(2*n)
S.C:-O(1)
  
//Optimal Solution (DUTCH NATIONAL FLAG ALGO)
#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   int low=0,mid=0,high=n-1;
   while(mid<=high){
      if(arr[mid]==0){
         swap(arr[low],arr[mid]);
         mid++;
         low++;
      }
      else if(arr[mid]==1){
         mid++;
      }
      else{
         swap(arr[mid],arr[high]);
         high--;
      }
   }
}

T.C:-O(n)
S.C:-O(1)
