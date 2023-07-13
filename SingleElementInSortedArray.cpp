//Brute force approach
T.C:-O(n)
S.C:-O(1)
int singleNonDuplicate(vector<int>& arr)
{
	int n=arr.size();
	//edge case
	if(n==1) return arr[0];

	//else if the element occurs twice it will match  either its previous element or next element
	for(int i=0;i<n;i++){
		//check for first index
		if(i==0){
			if(arr[i]!=arr[i+1]) return arr[i];
		}

		//check for last index
		if(i==n-1){
			if(arr[i]!=arr[i-1]) return arr[i];
		}

		//else check for remaining elements
		else{
			if(arr[i]!=arr[i+1] && arr[i]!=arr[i-1]) return arr[i];
		}
	}
	return -1;
}



//Optimal solution(Using Binary Search)
T.C:-O(log n)
S.C:-O(1)
int singleNonDuplicate(vector<int>& arr)
{
	int n=arr.size();
	//edge case
	if(n==1) return arr[0];
	if(arr[0]!=arr[1]) return arr[0];
	if(arr[n-1]!=arr[n-2]) return arr[n-1];

	int low=1,high=n-2;
	while(low<=high){
		int mid=(low+high)/2;
		
		//if arr[mid] is the single element
		if(arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1]) return arr[mid];

		//if not found in left half
		if((mid%2 == 1 && arr[mid]==arr[mid-1]) || (mid%2==0 && arr[mid]==arr[mid+1])){
			low=mid+1;
		}
		
		else{
			high=mid-1;
		}
	}
	return -1;
}
