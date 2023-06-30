//Brute force solution
T.C:-O(n*2360)
S.C:-O(1)
int calculateMinPatforms(int at[], int dt[], int n) {
    //array to store platforms required at different points of time
    int platforms[2360]={0};
    
    int ans=1;//final ans;
    for(int i=0;i<n;i++){
        //incrementing platforms required for all times 
        //between that arrival and departure
        for(int j=at[i];j<=dt[i];j++){
            platforms[j]++;

            //updating the platforms at that interval
            ans=max(ans,platforms[j]);
        }
    }
    return ans;
}


//Better solution
T.C:-O(n log n)
S.C:-O(1)
int calculateMinPatforms(int at[], int dt[], int n) {
    int i=0,j=0;
    int ans=0;//final no of platforms required
    int cnt=0;//current no of platforms required
    sort(at,at+n);
    sort(dt,dt+n);
    while(i<n && j<n){
        if(at[i]<=dt[j]){
            cnt++;
            i++;
        }
        else{
            cnt--;
            j++;
        }
        ans=max(ans,cnt);
    }
    return ans;
}

//Optimal solution
