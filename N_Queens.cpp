//Backtracking
T.C:-O(n)
S.C:-O(n^2)

#include<bits/stdc++.h>
bool isValid(vector<vector<int>>& board,int row,int col,int n){
    //upper diagonal 
    int r=row,c=col;
    while(r>=0 && c>=0){
        if(board[r][c]==1){
            return false;
        }
        r--,c--;
    }

    //lower diagonal
    r=row,c=col;
    while(r<n && c>=0){
        if(board[r][c]==1) return false;
        r++,c--;
    }

    //backwards
    r=row,c=col;
    while(c>=0){
        if(board[r][c]==1) return false;
        c--;
    }

    return true;
}

void solve(int col,int n,vector<vector<int>>& board,vector<vector<int>>& ans){
    if(col==n){
        vector<int>temp;
        for(auto it: board){
            for(int i=0;i<it.size();i++)
            temp.push_back(it[i]);
        }
        ans.push_back(temp);
    }

    for(int row=0;row<n;row++){
        if(isValid(board,row,col,n)){
            board[row][col]=1;
            solve(col+1,n,board,ans);
            board[row][col]=0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>>board(n,vector<int>(n,0)); 
    vector<vector<int>>ans;//to store the ans
    solve(0,n,board,ans);
    return ans;
}
