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
