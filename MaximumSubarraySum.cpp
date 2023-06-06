//Brute Force Approach

T.C:-O(n3)
S.C:-O(1)
#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long sum=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            long long curr_sum=0;
            for(int k=i;k<=j;k++){
                curr_sum+=arr[k];
            }
            sum=max(sum,curr_sum);
        }
    }
    return sum;
}


//Better Approach
T.C:-O(n2)
S.C:-O(1)
#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
   long long sum=0;
   for(int i=0;i<n;i++){
       long long curr_sum=0;
       for(int j=i;j<n;j++){
           curr_sum+=arr[j];
           sum=max(sum,curr_sum);
        }
    }
    return sum;
}


//Optimal solution
T.C:-O(n)
  S.C:-O(1)
#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long sum=0;
    long long curr_sum=0;
    for(int i=0;i<n;i++){
        curr_sum+=arr[i];
        if(curr_sum<0) curr_sum=0;
        if(curr_sum>sum) sum=curr_sum;
    }

    return sum;
}
