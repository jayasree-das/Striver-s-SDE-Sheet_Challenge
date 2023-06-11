//Brute Force Approach
T.C:-O(n3)
S.C:-O(1)
#include <bits/stdc++.h>
int subarraysXor(vector<int> &arr, int x)
{
    int n=arr.size();
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int ans=0;
            for(int k=i;k<=j;k++){
                ans=ans^arr[k];
            }
            if(ans==x){
                count++;
            }
        }
    }
    return count;
}

//Better solution
T.C:-O(n2)
S.C:-O(1)
#include <bits/stdc++.h>
int subarraysXor(vector<int> &arr, int x)
{
    int n=arr.size();
    int count=0;
    for(int i=0;i<n;i++){
        int ans=0;
        for(int j=i;j<n;j++){
            ans=ans^arr[j];
            if(ans==x){
                count++;
            }
        }
    }
    return count;
}

//Optimal solution
T.C:-O(n)
S.C:-O(n)
#include <bits/stdc++.h>
int subarraysXor(vector<int> &arr, int x)
{
    int n=arr.size();
    int curr_xr=0;
    map<int,int>mp;//(curr_xr,occurence)
    mp[curr_xr]++;//setting the occurence of as 1 in map
    int cnt=0;
    for(int i=0;i<n;i++){
        //calculating xor till i
        curr_xr=curr_xr^arr[i];
        //checking if x existed till now cz we know
        //k^x=curr_xr
        int k=curr_xr^x;

        // add the occurrence of xr^x
        // to the count
        cnt += mp[k];

        // Insert the prefix xor till index i
        // into the map
        mp[curr_xr]++;
    }
    return cnt;
}

