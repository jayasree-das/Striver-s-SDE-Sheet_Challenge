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
T.C:-O(n * log(m) * log(2^32) which is approximately o(n * log m)
S.C:-O(1)
int countsmallerthanMid(int mid,vector<int>& row){
    int left=0,right=row.size()-1;
    while(left<=right)
    {
        int md=(left+right)/2;
        if (row[md] <= mid)
        {
            left= md+1;
        }
        else
        {
            right=md-1;
        }
    }
    return left;
}

int getMedian(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    int low=1,high=1e9;
    while(low<=high){
        int mid=(low+high)/2;
        int cnt=0;
        //counting the no of elements lesser than our mid value
        for(int i=0;i<n;i++){
            cnt+=countsmallerthanMid(mid,matrix[i]);
        }
        //median should be any index atleast >=(n*m)/2
        //so if the no of elements smaller than our mid is less than or equal to (n*m)/2
        //we need to move our search space to the right
        if(cnt<=(n*m)/2) low=mid+1;
        else high=mid-1;
    }
    return low;
}
