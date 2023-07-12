//Backtracking
T.C:-O(n^m) since there are n nodes and for each one of them we are trying m colors
S.C:-O(n)+O(n) which approximates to O(n) where one O(n) is for the col vector and the other is recursion stack space

bool isPossible(int node,int i,vector<vector<int>>& mat,vector<int>& col){
    for(int j=0;j<mat.size();j++){
        if(j!=node && mat[j][node]==1 && col[j]==i) return false;
    }
    return true;
}

bool solve(int node,vector<vector<int>>& mat,int m,int n,vector<int>& col){
    if(node==n) return true;

    for(int i=1;i<=m;i++){
        if(isPossible(node,i,mat,col)){
            col[node]=i;
            if(solve(node+1,mat,m,n,col)) return true;
            col[node]=0;
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int n=mat.size();
    //vector to check which node is assigned which color
    vector<int>col(n,0);

    int node=0;
    if(solve(node,mat,m,n,col)) return "YES";
    return "NO";
}
