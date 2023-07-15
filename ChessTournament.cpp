Same as aggressive cows
//Brute force solution
T.C:-O(n log n) + O(limit * n) where limit=arr[n-1]-arr[0]
S.C:-O(1)
#include <bits/stdc++.h> 
bool istrue(vector<int>& positions,int dist,int players,int n){
	int cnt=1;//counting the no of players who got room

	/*lastpos is the room the last player took, 
	initially we will always place the first player in the first room*/
	int lastpos=positions[0];

	for(int i=1;i<=n-1;i++){
		if(positions[i]-lastpos>=dist){
			cnt++;
			lastpos=positions[i];
		}
		if(cnt>=players) return true;
	}
	return false;
}

int chessTournament(vector<int> positions , int n ,  int c){
	sort(positions.begin(),positions.end());
	//max dist we can have between two rooms
	int limit=positions[n-1]-positions[0];

	/*we can have a min dist of 1 and max dist of limit betweeen two rooms, so we will iterate 
	over that limit and check the max dist till which we can place our given players*/
	for(int i=1;i<=limit;i++){
		if(istrue(positions,i,c,n)==true) continue;
		else return i-1;//if the present i dist is not possible it means the last dist 
		//was the max dist we can have while placing all the cows
	}
	return limit;
}




//Optimal solution
T.C:-O(n log n)+O(n * log (max(positions[]) - min(positions[])))
S.C:-O(1)
#include <bits/stdc++.h> 
bool weCanPlace(vector<int>& positions,int dist,int players,int n){
	int cnt=1;//counting the no of players who got room

	/*lastpos is the room the last player took, 
	initially we will always place the first player in the first room*/
	int lastpos=positions[0];

	for(int i=1;i<=n-1;i++){
		if(positions[i]-lastpos>=dist){
			cnt++;
			lastpos=positions[i];
		}
		if(cnt>=players) return true;
	}
	return false;
}

int chessTournament(vector<int> positions , int n ,  int c){
	sort(positions.begin(),positions.end());
	//high is the max dist we can have between two rooms
	//low is the min dist between two rooms
	int low=1,high=positions[n-1]-positions[0];

	while(low<=high){
		int mid=(low+high)/2;
		if(weCanPlace(positions,mid,c,n)==true) low=mid+1;
		else high=mid-1;
	}
	return high;
}
