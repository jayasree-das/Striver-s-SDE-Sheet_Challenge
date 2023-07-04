//Recursion
T.C:-O(2^n)+O(2^n log (2^n))
S.C:-O(2^n)
void solve(vector<int>& num,int n,int ind,int sum,vector<int>& res){
	if(ind==n){
		res.push_back(sum);
		return ;
	}
	//picking the element
	solve(num,n,ind+1,sum+num[ind],res);
	//not picking the element
	solve(num,n,ind+1,sum,res);
}
vector<int> subsetSum(vector<int> &num){
	int n=num.size();
	vector<int>res;
	solve(num,n,0,0,res);
	sort(res.begin(),res.end());
	return res;	
}

