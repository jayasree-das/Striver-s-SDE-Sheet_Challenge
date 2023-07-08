//Backtracking
T.C:-O(n*n!)
S.C:-O(n) //recursion stack space

#include <bits/stdc++.h> 
void permute(string &s,vector<string>& res,int ind){
    if(ind>=s.size()){
        res.push_back(s);
        return;
    }
    for(int i=ind;i<s.size();i++){
        swap(s[i],s[ind]);
        permute(s,res,ind+1);
        swap(s[i],s[ind]);
    }
}
vector<string> findPermutations(string &s) {
    vector<string>res;
    permute(s,res,0);
    return res;
}
