//brute force
T.C:-O(n2)
S.C:-O(1)
#include <bits/stdc++.h> 
int reversePairs(vector<int> &arr, int n){
	int count=0;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]>2*arr[j]) count++;
		}
	}
	return count;	
}

//optimal solution(USE MERGE SORT)
T.C:-O(2*n log n)
S.C:-O(n)
#include <bits/stdc++.h>
void merge(int low,int mid,int high,vector<int>& arr){
	vector<int>temp;
	int left=low;
	int right=mid+1;
	while(left<=mid && right<=high){
		if(arr[left]<=arr[right]){
			temp.push_back(arr[left]);
			left++;
		}
		else{
			temp.push_back(arr[right]);
			right++;
		}
	}
	while(left<=mid){
		temp.push_back(arr[left]);
		left++;
	}
	while(right<=high){
		temp.push_back(arr[right]);
		right++;
	}
	for(int i=low;i<=high;i++){
		arr[i]=temp[i-low];
	}
}
int countpairs(int low,int mid,int high,vector<int>& arr){
	int right=mid+1;
	int cnt=0;
	for(int i=low;i<=mid;i++){
		while(right<=high && arr[i]>2*arr[right]){
			right++;
		}
		cnt+=(right-(mid+1));
	}
	return cnt;
}
int mergeSort(int low,int high,vector<int>& arr){
	int cnt=0;
	if(low>=high) return cnt;
	int mid=(low+high)/2;
	cnt+=mergeSort(low,mid,arr);
	cnt+=mergeSort(mid+1,high,arr);
	cnt+=countpairs(low,mid,high,arr);
	merge(low,mid,high,arr);
	return cnt;
} 
int reversePairs(vector<int> &arr, int n){
	return mergeSort(0,n-1,arr);
}
