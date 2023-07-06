//Recursion
T.C:-O(n* 2^n) where n is the max subset size with 2^n subsets
S.C:-O(n*2^n) which is recursive stack space

void solve(int i,vector<int>& arr,int k,int n,vector<vector<int>>& ans,
vector<int>& ds){
    if(i==n){
        if(k==0){
            ans.push_back(ds);
        }
        return;
    }
    //take
    ds.push_back(arr[i]);
    solve(i+1,arr,k-arr[i],n,ans,ds);
    ds.pop_back();
    //not take
    solve(i+1,arr,k,n,ans,ds);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>>ans;
    vector<int>ds;
    
    solve(0,arr,k,n,ans,ds);
    return ans;
}
  
