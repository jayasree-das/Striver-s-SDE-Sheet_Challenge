//Brute Force
T.C:-O(n)
S.C:-O(1)
#include <bits/stdc++.h>
int modularExponentiation(int x, int n, int m) {
	int ans=1;
	for(int i=1;i<=n;i++){
		ans=(1LL*ans*x)%m;
	}
	return ans;
}

//optimal solution
T.C:-O(log n)
S.C:- O(log n) -->recursive stack space
#include <bits/stdc++.h>
int modularExponentiation(int x, int n, int m) {
	if(n==0) return 1;
	int ans=modularExponentiation(x,n/2,m);
	//if n is even then return the square of ans
	if(n%2 ==0){
		return (1LL*ans*ans)%m;
	}
	//else return the square of ans multiplied with x
	else{
		return (1LL*(1LL*ans*ans)%m *x%m)%m;
	}
}


//optimal solution
T.C:-O(log n)
S.C:-O(1)
  
#include <bits/stdc++.h>
int modularExponentiation(int x, int n, int m) {
	int ans=1;
	while(n>0){
		//if n is odd
		if(n%2){
			ans=(1LL*ans*x)%m;
			n=n-1;
		}
		//if n is even
		else{
			x=(1LL*x*x)%m;
			n=n/2;
		}
	}
	return ans;
}
