//Brute force approach
T.C:-O(n3)
S.C:-O(3*no of unique triplets)
#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	vector<vector<int>>ans;
	set<vector<int>>visited;
	vector<int>temp;
	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n-1;j++){
			for(int k=j+1;k<n;k++){
				temp.clear();
				if(arr[i]+arr[j]+arr[k]==K){
					temp.push_back(arr[i]);
					temp.push_back(arr[j]);
					temp.push_back(arr[k]);

					sort(temp.begin(),temp.end());
					if(visited.find(temp)==visited.end()){
						ans.push_back(temp);
						visited.insert(temp);
					}
				}
			}
		}
	}
	return ans;
}


//Better solution
T.C:-O(n2)
S.C:-O(3*no of unique triplets)
#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	sort(arr.begin(),arr.end());
	vector<vector<int>>ans;
	set<vector<int>>s;
	vector<int>temp;
	for(int i=0;i<n-2;i++){
		int low=i+1;
		int high=n-1;
		while(low<high){
			temp.clear();
			int sum=arr[i]+arr[low]+arr[high];
			if(sum==K){
				temp.push_back(arr[i]);
				temp.push_back(arr[low]);
				temp.push_back(arr[high]);

				if(s.find(temp)==s.end()){
					s.insert(temp);
					ans.push_back(temp);
				}
				low++;
				high--;
			}
			else if(sum<K){
				low++;
			}
			else{
				high--;
			}
		}
	}
	return ans;
}

