//Brute Force Solution
T.C:-O(m+n)
S.C:-O(m+n)
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    vector<int>temp;
    int i=0,j=0;
    while(i<m && j<n){
        if(row1[i]<row2[j]){
            temp.push_back(row1[i]);
            i++;
        }
        else{
            temp.push_back(row2[j]);
            j++;
        }
    }
    while(i<m){
        temp.push_back(row1[i]);
        i++;
    }
    while(j<n){
        temp.push_back(row2[j]);
        j++;
    }
    return temp[k-1];
}


//Better solution (space optimisation)
T.C:-O(k)
S.C:-O(1)
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    int i=0,j=0;
    while(i<m && j<n){
        if(i+j == k-1) return min(row1[i],row2[j]);
        if(row1[i]<row2[j]) i++;
        else j++;
    }

    while(i<m){
        if(i+j==k-1){
            return row1[i];
        }
        i++;
    }

    while(j<n){
        if(i+j==k-1) return row2[j];
        j++;
    }
    return row2[i+j];
}


//optimal solution
T.C:-O( log (min(m,n)))
S.C:-O(1)
#include<bits/stdc++.h>
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    if(m>n) return ninjaAndLadoos(row2,row1,n,m,k);
    if(m==0) return row2[k-1];
    if(k==1) return min(row1[0],row2[0]);

    int low=max(0,k-n),high=min(k,m);
    while(low<=high){
        int cut1=(low+high)/2;
        int cut2=k-cut1;
        
        int l1 = (cut1 == 0) ? INT_MIN : row1[cut1 - 1]; 
        int l2 = (cut2 == 0) ? INT_MIN : row2[cut2 - 1];
        int r1 = (cut1 == m) ? INT_MAX : row1[cut1]; 
        int r2 = (cut2 == n) ? INT_MAX : row2[cut2];
        
        if(l1<=r2 && l2<=r1){
            return max(l1,l2);
        }
        else if(l1>r2){
            high=cut1-1;
        }
        else{
            low=cut1+1;
        } 
    }
    return 1;
}
