//Brute Force
T.C:-O(m+n)+O((m+n)log(m+n))
S.C:- O(m+n)

#include <bits/stdc++.h>
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	vector<int>merged;
	for(int i=0;i<arr1.size();i++){
		if(arr1[i]==0) continue;
		merged.push_back(arr1[i]);
	}

	for(int i=0;i<arr2.size();i++){
		if(arr2[i]==0) continue;
		merged.push_back(arr2[i]);
	}
	sort(merged.begin(),merged.end());
	return merged;
}


//Better Solution
T.C:- O(m+n)
S.C:- O(1)
  
#include <bits/stdc++.h>
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	int i=m-1;
	int j=n-1;
	int ind=m+n-1;
	while(j>=0){
		if(i>=0 && arr1[i]>arr2[j]){
			arr1[ind]=arr1[i];
			i--;
		}
		else{
			arr1[ind]=arr2[j];
			j--;
		}
		ind--;
	}
	return arr1;
}
