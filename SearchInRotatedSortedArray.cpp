//Brute force approach
T.C:-O(n)
S.C:-O(1)
int search(int* arr, int n, int key) {
    for(int i=0;i<n;i++){
        if(arr[i]==key) return i;
    }
    return -1;
}


//Optimal solution
T.C:-O(log n)
S.C:-O(1)
int search(int* arr, int n, int key) {
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==key) return mid;
        
        /*since the array is sorted and rotated 
        for every index either one of the halves will be sorted*/
        
        //if left half is sorted
        if(arr[low]<=arr[mid]){
            //key lies between low and mid
            if(arr[low]<=key && key<=arr[mid]){
                high=mid-1;
            }
            else{//element does not exist
                low=mid+1;
            }
        }

        else{//if right half is sorted
            if(arr[mid]<=key && key<=arr[high]) low=mid+1;
            else high=mid-1;//element does not exist
        }       
    }

    return -1;
}
