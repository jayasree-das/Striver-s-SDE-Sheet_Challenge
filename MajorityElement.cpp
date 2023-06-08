more then (n/2) times

//Brute Force
T.C:-O(n2)
S.C:-O(1)
#include <bits/stdc++.h>
int findMajorityElement(int arr[], int n) {
	for(int i=0;i<n;i++){
		int count=0;
		for(int j=0;j<n;j++){
			if(arr[j]==arr[i]) count++;
		}
		if(count > n/2) return arr[i];
	}
	return -1;
}

//Better solution
T.C:-O(n)+O(n)
S.C:-O(n)
#include <bits/stdc++.h>
int findMajorityElement(int arr[], int n) {
	unordered_map<int,int>freq;
	for(int i=0;i<n;i++){
		freq[arr[i]]++;
	}
	for(auto it:freq){
		if(it.second > n/2)
			return it.first;
	}
	return -1;
}


//optimal solution(MOORE'S VOTING ALGO)
T.C:-O(2*n)
S.C:-O(1)
#include <bits/stdc++.h>
int findMajorityElement(int arr[], int n) {
	int cnt=0;
	int ele;
	for(int i=0;i<n;i++){
		if(cnt==0){
			cnt=1;
			ele=arr[i];
		}
		else if(arr[i]==ele){
			cnt++;
		}
		else{
			cnt--;
		}
	}
	int cnt1=0;
	for(int i=0;i<n;i++){
		if(arr[i]==ele){
			cnt1++;
		}
		if(cnt1 > n/2) return ele;
	}
	return -1;
}
