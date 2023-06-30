//Brute Force solution
T.C:-O(n2)
S.C:-O(1)
int longestSubSeg(vector<int> &arr , int n, int k){
    int maxLen=0;
    int i,j;
    for(i=0;i<n;i++){
        int flip=k;
        if(arr[i]==0){
            if(flip>0){
                flip--;
            }
            else{
                continue;
            }
        }
        for(j=i+1;j<n;j++){
            if(arr[j]==0){
                if(flip>0){
                    flip--;
                }
                else{
                    break;
                }
            }
        }

        maxLen=max(maxLen,j-i);
    }
    return maxLen;
}



//Better solution
T.C:-O(n)
S.C:-O(k) where k is the no of flips possible
#include<bits/stdc++.h>
int longestSubSeg(vector<int> &arr , int n, int k){
    int start=0;//starting point of subarray
    int maxLen=0;//length of the subarray
    queue<int>q;//storing the no of flips ar indexes
    int size=0;//size of queue i.e no of flips occured
    for(int end=0;end<n;end++){
        if(arr[end]==0){
            q.push(end);
            size++;
        }
        if(size>k){
            start=q.front()+1;
            q.pop();
            size--;
        }
        maxLen=max(maxLen,end-start+1);
    }
    return maxLen;
}



//Optimal solution
T.C:-O(n)
S.C:-O(1)
int longestSubSeg(vector<int> &arr , int n, int k){
    int cnt0=0;//stores count of zero in the subarray taken
    int maxLen=0;
    int start=0;
    for(int end=0;end<n;end++){
        if(arr[end]==0){
            cnt0++;
        }
        while(cnt0>k){
            if(arr[start]==0){
                cnt0--;
            }
            start++;
        }
        maxLen=max(maxLen,end-start+1);
    }
    return maxLen;
}
