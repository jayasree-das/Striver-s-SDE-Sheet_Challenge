//Backtracking
T.C:-O(4^(n^2)) where there are n^2 cells and for each cell we are making 4 recursion calls
S.C:-O(n^2)

#include <bits/stdc++.h> 
void solve(vector<vector<int>> &maze, int n,vector<vector<int>>& ans,
vector<int>& temp,int row,int col){
  //if row and col goes out of boundary 
  //or if that cell is blocked i.e maze[row][col]==0
  //or if that cell is already visited i.e temp[row*n+col]==1
  if(row<0 || col<0 || row>=n || col>=n || maze[row][col]==0 || temp[row*n+col]==1) return ;

  
  //if you have reached the last row then mark it as visited and push the temp to ans
  if(row==n-1 && col==n-1) {
    temp[row*n+col]=1;
    ans.push_back(temp);
  }

  //else for the cell you are checking mark it as visited and then check in all directions where to 
  //move and continue
  temp[row*n+col]=1;
  solve(maze,n,ans,temp,row,col+1);
  solve(maze,n,ans,temp,row,col-1);
  solve(maze,n,ans,temp,row+1,col);
  solve(maze,n,ans,temp,row-1,col);
  //while returning back
  temp[row*n+col]=0;
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  vector<vector<int>>ans;//to store all the paths
  vector<int>temp(n*n,0);//vector to check the paths ,where all cells are initially marked 0
  solve(maze,n,ans,temp,0,0);
  return ans;
}
