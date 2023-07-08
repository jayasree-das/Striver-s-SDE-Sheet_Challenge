//Brute Force (Generating all permutations recursively and then returning)
T.C:-O(n*n!)+O(n! log n!)
S.C:-O(n) since we are storing the permutations in a vector

#include<bits/stdc++.h>
void solve(string input,int n,int index, vector<string>& ans){
    if(index>=n){
        ans.push_back(input);
        return;
    }
    for(int i=index;i<n;i++){
        swap(input[i],input[index]);
        solve(input,n,index+1,ans);
        swap(input[i],input[index]);
    }
    return;
}
string kthPermutation(int n, int k) {
    // input string create
    string input = "";
    for(int i=1;i<=n;i++){
        char ch = i+48;
        input+=ch;
    }
    //storing all permutations
    vector<string> ans;
    solve(input,n,0,ans);
    //sorting all the stored permutations
    sort(ans.begin(),ans.end());
    //consider 0 based indexing, so kth sequence will be at (k-1) index
    return ans[k-1];
}


//Optimal solution
T.C:-O(n^2)
S.C:-O(n)

string kthPermutation(int n, int k) {
    vector<int>numbers;
    int fact=1;
    for(int i=1;i<n;i++){
        fact=fact*i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    string ans="";
    //0 based indexing
    k=k-1;

    while(true){
        ans=ans+to_string(numbers[k/fact]);
        numbers.erase(numbers.begin()+k/fact);
        if(numbers.size()==0) break;
        k=k%fact;
        fact=fact/numbers.size();
    }

    return ans;
}
