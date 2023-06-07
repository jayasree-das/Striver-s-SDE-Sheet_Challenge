//Brute Force Approach
T.C:-O(n2)
S.C:-O(1)
  
#include <bits/stdc++.h>
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int missing=-1;
	int repeating=-1;
	for(int i=1;i<=n;i++){
		int count=0;
		for(int j=0;j<n;j++){
			if(arr[j]==i){
				count++;
			}
		}
		if(count>1) repeating=i;
		if(count==0) missing=i;

		if(missing!=-1 && repeating!=-1) break;
	}
	return {missing,repeating};
}


//Better solution
T.C:- O(2*n)
S.C:-O(n)
  
 #include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int hash[n+1]={0};
	for(int i=0;i<n;i++){
		hash[arr[i]]++;
	}
	int missing=-1,repeating=-1;
	for(int i=1;i<=n;i++){
		if(hash[i]==0) missing=i;
		if(hash[i]>1) repeating=i;

		if(missing!=-1 && repeating!=-1) break;
	}
	return {missing,repeating};
}


//optimal solution
T.C:-O(n)
S.C:-O(1)
  
#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	long long s=0; //sum of all the array numbers
    long long s2=0;//sum of the squares of all array numbers
    long long sn=(long long)(n*(n+1))/2;//sum of n natural numbers
    long long s2n=((long long)n*(long long)(n+1)*(long long)(2*n+1))/6; //sum of squares of n natural numbers
    for(int i=0;i<n;i++){
        s+=arr[i];
        s2+=(long long)arr[i]*(long long)arr[i];
    }
    long long val1=s-sn;
    long long val2=s2-s2n;
    val2=val2/val1;
    long long x=(val1+val2)/2; //repeating
    long long y=x-val1; //missing

    return {(int)y,(int)x};
}
