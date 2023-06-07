//Brute Force
T.C:- O(n2)
S.C:- O(1)
  
#include <bits/stdc++.h>
int findDuplicate(vector<int> &arr, int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[j]==arr[i]){
				return arr[j];
			}
		}
	}
}


//Better Solution
T.C:-O(2*n)
S.C:-O(n)
  
#include <bits/stdc++.h>
int findDuplicate(vector<int> &arr, int n){
	int hash[n]={0};
	for(int i=0;i<n;i++){
		hash[arr[i]]++;
	}
	for(int i=0;i<n;i++){
		if(hash[i]>1) return i;
	}
}


//Optimal Solution
T.C:-O(n)
S.c:-O(1)
#include <bits/stdc++.h>
int findDuplicate(vector<int> &arr, int n){
	int tortoise=arr[0];
	int hare=arr[0];
    do{
    	tortoise = arr[tortoise];
        hare = arr[arr[hare]];
    }
	while(tortoise != hare);

    tortoise=arr[0];
	while(tortoise!=hare){
		tortoise=arr[tortoise];
		hare=arr[hare];
	}
	return hare;
}


