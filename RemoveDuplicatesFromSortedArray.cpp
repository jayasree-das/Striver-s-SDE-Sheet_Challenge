//Brute Force Approach
T.C:-O(n*log n)+O(n)
S.C:-O(n)
#include<bits/stdc++.h>
int removeDuplicates(vector<int> &arr, int n) {
	set<int>s;
	for(int i=0;i<n;i++){
		s.insert(arr[i]);
	}
	int j=0;
	for(auto it:s){
		arr[j++]=it;
	}
	return s.size();
}


//optimal solution
T.C:-O(n)
S.C:-O(1)
int removeDuplicates(vector<int> &arr, int n) {
	int i=0;
	for(int j=1;j<n;j++){
		if(arr[i]!=arr[j]){
			i++;
			arr[i]=arr[j];
		}
	}
	return i+1;
} 
