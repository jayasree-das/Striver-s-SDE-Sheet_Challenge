//Brute Force Approach
T.C:-O(n2)
S.C:-O(1)
#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    int n=input.length();
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        unordered_set<char>s;
        for(int j=i;j<n;j++){
            if(s.find(input[j])!=s.end()){
                ans=max(ans,j-i);
                break;
            }
            else{
                s.insert(input[j]);
            }
        }
    }
    if(ans==INT_MIN) ans=n;
    return ans;
}

//Optimal Approach1
T.C:-O(2*n)
S.C:-O(256) means const space cause at max only 256 ellements will be there in the set
#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    int n=input.length();
    if(n==0) return 0;
    int ans=INT_MIN;
    int l=0;
    unordered_set<int>s;
    for(int r=0;r<n;r++){
        //finding duplicates
        //if found
        if(s.find(input[r])!=s.end()){
            //remove the duplicate element from set
            while(l<r && s.find(input[r])!=s.end()){
                s.erase(input[l]);
                l++;//move the right pointer
            }
        }
        s.insert(input[r]);//then again insert the current element in set 
        ans=max(ans,r-l+1);
    }
    return ans;
}


//Optimal approach2
T.C:-O(n)
S.C:-O(1)
#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    unordered_map<char,int>mp;//(char,index)
    int n=input.length();
    int left=0;
    int right=0;
    int ans=0;
    while(left<n && right<n){
        //check if the right ele was already there in map
        if(mp.find(input[right])!=mp.end()){
            //move the left to the next index of where the right previously was
            left=max(left,mp[input[right]]+1);  
        }
            
        //update the last occuring index of the right ele
        mp[input[right]]=right;

        ans=max(ans,right-left+1);//calculate the length
        //move right to next ele and check
        right++;
    }
    return ans;
}
