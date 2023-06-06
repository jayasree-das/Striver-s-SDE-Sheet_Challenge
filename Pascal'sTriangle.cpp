//Brute Force Approach

T.C:- O(n*n*n)
S.C:- O(1)
#include <bits/stdc++.h>
long long int nCr(int n, int r) {
    long long int res = 1;
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}
vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<long long int>>ans;
  //Store the entire Pascal's Triangle
  for (int row = 1; row <= n; row++) {
    vector<long long int> temp; // temporary list
    for (int col = 1; col <= row; col++) {
      temp.push_back(nCr(row - 1, col - 1));
    }
    ans.push_back(temp);
  }
  return ans;
}



//Optimal solution
T.C:- O(n2)
S.C:- O(1)
  
#include <bits/stdc++.h>
vector<long long int>generateRow(int row){
  long long ans=1;
    vector<long long int>ansRow;
    ansRow.push_back(1);
    for(int col=1;col<row;col++){
        ans=ans*(row-col);
        ans=ans/col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<long long int>>ans;
  for(int i=1;i<=n;i++){
    ans.push_back(generateRow(i));
  }
  return ans;
}
