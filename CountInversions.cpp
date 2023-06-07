//Brute Force Approach
T.C:-O(n2)
S.C:-O(1)
  
#include <bits/stdc++.h> 
long long getInversions(long long *arr, int n){
    long long count=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]) count++;
        }
    }
    return count;
}


//Optimal solution
T.C:-O(n log n)
S.C:-O(n)
  
#include <bits/stdc++.h>
long long merge(long long *arr,int low,int mid,int high){
    long long count = 0;
    vector<int>temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            //when found one greater element since the array is sorted 
            //add all the elements after that to the count
            count+=(mid-left+1); 
            right++;
        }
    }

    //if elements of right array is over
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    //if elements of left array is over
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }

    return count;
}
long long mergeSort(long long *arr,int low,int high){
    long cnt=0;
    if(low>=high) return cnt;
    int mid=(low+high)/2;
    cnt+=mergeSort(arr,low,mid);
    cnt+=mergeSort(arr,mid+1,high);
    cnt+=merge(arr,low,mid,high);

    return cnt;
} 
long long getInversions(long long *arr, int n){
    return mergeSort(arr,0,n-1);
}
