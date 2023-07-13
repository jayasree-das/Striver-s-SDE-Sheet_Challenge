//Brute Force Approach
T.C:-O(m * log n) which is approximately O(m)
S.C:-O(1)
int solve(int i,int n){
  int ans=1;
  int num=i;
  while(n>0){
    //if power is odd
    if(n%2){
      n--;
      ans=ans*num;
    }
    //if power is even
    else{
      n=n/2;
      num=num*num;
    }
  }
  return ans;
}

int NthRoot(int n, int m) {
  for(int i=1;i<=m;i++){
    int val=solve(i,n);
    if(val==m) return i;
    else if(val>m) break;
  }
  return -1;
}



//Optimal solution using Binary Search
T.C:-O(log m * log n) which is approximately O(log n)
S.C:-O(1)
int solve(int mid,int n,int m){
  long long ans=1;
  for(int i=1;i<=n;i++){
    ans=ans*mid;
    if(ans>m) return 2;
  }
  if(ans==m) return 1;
  return 0;
}

int NthRoot(int n, int m) {
  int low=1,high=m;
  while(low<=high){
    int mid=(low+high)/2;
    int val=solve(mid,n,m);
    if(val==1) return mid;
    else if(val==0) low=mid+1;
    else high=mid-1;
  }
  return -1;
}
