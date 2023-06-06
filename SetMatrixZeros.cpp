//Brute Approach
#include <bits/stdc++.h>
void markRow(int row,vector<vector<int>> &matrix){
	int m=matrix[0].size();
	for(int j=0;j<m;j++){
		//if elements in that row are not 0 then mark as -1
		if(matrix[row][j]!=0){
			matrix[row][j]=-1;
		}
	}
}
void markCol(int col,vector<vector<int>> &matrix){
	int n=matrix.size();
	for(int i=0;i<n;i++){
		//if elements in that col are not 0 mark -1
		if(matrix[i][col]!=0){
			matrix[i][col]=-1;
		}
	}
}
void setZeros(vector<vector<int>> &matrix)
{
	int n=matrix.size();
	int m=matrix[0].size();
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(matrix[i][j]==0){
				markRow(i,matrix);
				markCol(j,matrix);
			}
		}
	}

	//finally mark that row and col elelemts marked as -1 to 0
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }
}

T.C:- O((n*m)(n+m)+(n*m))
S.C:- O(1)


//Better solution
#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	int n=matrix.size();
	int m=matrix[0].size();
	int row[n]={0};
	int col[m]={0};
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(matrix[i][j]==0){
				row[i]=1;
				col[j]=1;
			}
		}
	}

	//traversing the row and col array and checking for 1.
	//mark the corresponding row and col of matrix where 1 is found.
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(row[i]==1 || col[j]==1){
				matrix[i][j]=0;
			}
		}
	}


}

T.C:- O((n*m)+(n*m))
S.C:- O(n+m)


//Optimal Solution
#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	int n=matrix.size();
	int m=matrix[0].size();
	int col0=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(matrix[i][j]==0){
				//mark the ith row
				matrix[i][0]=0;

				//mark the jth col
				if(j != 0){
					matrix[0][j]=0;
				}
				else{
					col0=0;
				}
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(matrix[i][j]!=0){
				//check for row and col
				if(matrix[i][0]==0 || matrix[0][j]==0){
					matrix[i][j]=0;
				}
			}
		}
	}
	if(matrix[0][0]==0){
		for(int j=0;j<m;j++){
			matrix[0][j]=0;
		}
	}
	if(col0==0){
		for(int i=0;i<n;i++){
			matrix[i][0]=0;
		}
	}

}

T.C:- O((n*m)+(n*m))
S.C:- O(1)
