//Recursion
T.C:-O(2^n*(n/2)*k) where there are 2^n palindromes and for each time we need to check if it is a palindrome so (N/2) and then O(k) for inserting them into another data structure
S.C:-O(x*k) where there are x plaindromes of average size k

#include <bits/stdc++.h> 
bool isPalindrome(string &s,int start,int end){
    while(start<=end){
        if(s[start]!=s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}
void solve(string &s,vector<vector<string>>& ans,vector<string>& ds,int ind){
    if(ind==s.size()){
        ans.push_back(ds);
        return;
    }
    for(int i=ind;i<s.size();i++){
        if(isPalindrome(s,ind,i)){
            ds.push_back(s.substr(ind,i-ind+1));
            solve(s,ans,ds,i+1);
            ds.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s) 
{
    vector<vector<string>>ans;
    vector<string>ds;
    solve(s,ans,ds,0);
    return ans;
}
