//Brute force approach
T.C:-O(n+m)
S.C:-O(n+m)
double median(vector<int>& a, vector<int>& b) {
	int n=a.size();
	int m=b.size();

	vector<int>temp;
	int i=0,j=0;
	while(i<n && j<m){
		if(a[i]<b[j]){
			temp.push_back(a[i]);
			i++;
		}
		else{
			temp.push_back(b[j]);
			j++;
		}
	}
	while(i<n){
		temp.push_back(a[i]);
		i++;
	}
	while(j<m){
		temp.push_back(b[j]);
		j++;
	}

	double ans=0;
	int mid=(0+temp.size())/2;
	if(temp.size()%2==0){
		ans=(temp[mid]+temp[mid-1])/2.00;
		return ans;
	}
	else{
		ans=temp[mid];
		return ans;
	}
}


//Better solution (Space optimisation)
T.C:-O(n+m)
S.C:-O(1)
double median(vector<int>& a, vector<int>& b) {
	int n=a.size(),m=b.size();
	int i=0,j=0,m1=0,m2=0;
	
	//find the median
	for(int cnt=0;cnt<=(n+m)/2;cnt++){
		m2=m1;
		if(i!=n && j!=m){
			if(a[i]<b[j]){
				m1=a[i++];
			}
			else{
				m1=b[j++];
			}
		}

		//if one of the array finishes
		else if(i<n){
			m1=a[i++];
		}
		else{
			m1=b[j++];
		}
	}

	//if the sum of n and m is odd
	if((n+m)%2 == 1){
		return m1;
	}
    //if sum is even
	else{
		double ans=(m1+m2)/2.00;
		return ans;
	}
}


//Optimal solution
T.C:-O(log (min(n,m)))
S.C:-O(1)
double median(vector<int>& a, vector<int>& b) {
	int n=a.size();
	int m=b.size();
	
	//ensuring binary search happens in the smaller array
	if(n>m) return median(b,a);

	//finding where to cut in 'a'
	int low=0,high=n;
	int medianPos=(n+m+1)/2;
	while(low<=high){
		//making the cut in 1st array
		int cut1=(low+high)/2;
		//taking the remaining elements from b
		int cut2=medianPos-cut1;

		//l1 is placed in the left half elements from a
		//l2 is placed in the left half elements from b
		//r1 is placed in the right half elements from a
		//r2 is placed in the right half elements from b
		int l1=(cut1==0)?INT_MIN:a[cut1-1];
		int l2=(cut2==0)?INT_MIN:b[cut2-1];
		int r1=(cut1==n)?INT_MAX:a[cut1];
		int r2=(cut2==m)?INT_MAX:b[cut2];

		//we need to take elements such that all element in left half
		//are smaller than elements in right half
		if(l1<=r2 && l2<=r1){
			//if sum of len is odd
			if((n+m)%2==1) return max(l1,l2);
			//if sum of len is even
			else return (max(l1,l2)+min(r1,r2))/2.0;
		}

		else if(l1>r2) high=cut1-1;
		else low=cut1+1;		
	}

	return 0.0;
}
