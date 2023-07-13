//Brute force approach
T.C:-O( (n*m) + (n*m) log (n*m) )
S.C:-O(n*m)
#include<bits/stdc++.h>
int getMedian(vector<vector<int>> &matrix)
{
    vector<int>temp;
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            temp.push_back(matrix[i][j]);
        }
    }
    sort(temp.begin(),temp.end());
    int ans=temp[(temp.size()/2)];
    return ans;
}


//Optimal solution (Using Binary Search)
