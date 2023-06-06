//Brute Force
Find all the permutations of the array and then do a linear search on all the results(possible permutations of the array) to get the required nums and then return the one next to nums.
T.C:- O(n!*n)+O(m log m)
S.C:-O(1)
#include <bits/stdc++.h>
void solve(int ind,vector<int>& permutation,vector<vector<int>>& ans,int n){
    if(ind==n-1){
        ans.push_back(permutation);
        return;
    }

    for(int i=ind;i<n;i++){
        swap(permutation[i],permutation[ind]);
        solve(ind+1,permutation,ans,n);
        //while returning back
        swap(permutation[i],permutation[ind]);
    }
}
 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    if(n==1) return permutation;
    vector<vector<int>>ans;
    solve(0,permutation,ans,n);
    sort(ans.begin(),ans.end());
    int m=ans.size();
    for(int i=0;i<m-1;i++){
        if(ans[i]==permutation){
            return ans[i+1];
        }
    }

    if(ans[m-1]==permutation) return ans[0];
}


//Better solution
#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    next_permutation(permutation.begin(),permutation.end());
    return permutation;
}


//optimal solution
T.c:- O(3*n)
  S.C:-O(1)
Implementing the next_permutation stl


#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &A, int n)
{
    int ind=-1;
    //finding the break point i.e upto where the prefix will match
    for(int i=n-2;i>=0;i--){
        if(A[i]<A[i+1]){
            ind=i;
            break;
        }
    }

    //if the given one is the last permutation then return the smallest one
    if(ind==-1){
        reverse(A.begin(),A.end());
        return A;
    }
    
    //find the immediate next greater to breakPoint A[ind] 
    for(int i=n-1;i>ind;i--){
        if(A[i] > A[ind]){
            swap(A[i],A[ind]);
            break;
        }
    }

    //after the breakPoint sort the array in ascending 
    //order which is now in descending order
    reverse(A.begin()+ind+1, A.end()); //reversing from ind+1 to end
    return A;
    
}
