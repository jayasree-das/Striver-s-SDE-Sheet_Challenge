//Backtracking
T.C:-O(9^k) where k is the no of empty cells and for each cell we are trying 9 digits, in the worst case k=n^2 then T.C:-O(9^(n^2))
S.C:-O(1) , the recursion stack space can become O(k) which is approximately constant.

#include<bits/stdc++.h>
bool isValid(int matrix[9][9],int row,int col,int num){
    for(int i=0;i<9;i++){
        if(matrix[i][col]==num) return false;
        if(matrix[row][i]==num) return false;
        if(matrix[3*(row/3)+i/3][3*(col/3)+i%3]==num) return false;
    }

    /*int r=(row/3)*3;
    int c=(col/3)*3;
    for(int i=r;i<r+3;i++){
        for(int j=c;j<c+3;j++){
            if(matrix[i][j]==num) return false;
        }
    }*/

    return true;
}
bool solve(int matrix[9][9],int row,int col){
    if (row == 8 && col == 9) {
        return true;
    } 
    else {
        if (col == 9) {
            row += 1;
            col = 0;
        }
    }

    if(matrix[row][col]!=0){
        return solve(matrix,row,col+1);
    }

    if(matrix[row][col]==0){
        for(int num=1;num<=9;num++){
            if(isValid(matrix,row,col,num)){
                matrix[row][col]=num;
                if(solve(matrix,row,col+1)) return true;
            }
            matrix[row][col]=0;
        }
    }
    return false;
}
bool isItSudoku(int matrix[9][9]) {
    if(solve(matrix,0,0)) return true;
    return false;
}
