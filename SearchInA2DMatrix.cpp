//Brute Force Approach
T.C:-O(m*n)
S.C:-O(1)
  
bool searchMatrix(vector<vector<int>>& mat, int target) {
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            if(mat[i][j]==target) return true;
        }
    }

    return false;
}

//Better solution
T.C:-O(m log n)
S.C:-O(1)
  
bool searchMatrix(vector<vector<int>>& mat, int target) {
    int m=mat.size();//row
    int n=mat[0].size();//col    
    int i=0;
    int j=n-1;
    while(i<m && j>=0){
        if(mat[i][j]==target) return true;
        if(mat[i][j]>target) j--;
        if(mat[i][j]<target) i++;
    }  
    return false; 
}

//Optimal solution
T.C:-O(log (m*n))
S.C:-O(1)
  
bool searchMatrix(vector<vector<int>>& mat, int target) {
    int m=mat.size();
    int n=mat[0].size();
    int low=0;
    int high=((m*n)-1);

    while(low<=high){
        int mid=(low+(high-low)/2);
        int ind=mat[mid/n][mid%n];
        if(ind==target) return true;
        else if(ind>target) high=mid-1;
        else low=mid+1;
    }
    return false;
}
