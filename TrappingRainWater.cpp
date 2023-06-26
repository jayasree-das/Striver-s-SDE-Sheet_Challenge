//Brute Force solution
T.C:-O(n2)
S.C:-O(1)
#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    long water=0;
    for(int i=0;i<n;i++){
        long left=0,right=0;
        int j=i;
        while(j>=0){
            left=max(left,arr[j]);
            j--;
        }
        j=i;
        while(j<n){
            right=max(right,arr[j]);
            j++;
        }
        water+=min(left,right)-arr[i];
    }
    return water;
}


//Better solution
T.C:-O(3*n)
S.C:-O(n)+O(n)
#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    long prefix[n],suffix[n];
    long water=0;
    prefix[0]=arr[0];
    for(int i=1;i<n;i++){
        prefix[i]=max(prefix[i-1],arr[i]);
    }
    suffix[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        suffix[i]=max(arr[i],suffix[i+1]);
    }
    for(int i=0;i<n;i++){
        water+=min(prefix[i],suffix[i])-arr[i];
    }
    return water;
}
