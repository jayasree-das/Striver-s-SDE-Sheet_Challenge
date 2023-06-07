//Brute Force
T.C:-O(n log n)+O(2*n)
S.C:-O(1)

 #include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(),intervals.end());
    int n=intervals.size();
    vector<vector<int>>ans;
    int start=-1;
    int end=-1;
    for(int i=0;i<n;i++){
        start=intervals[i][0];
        end=intervals[i][1];

        if(!ans.empty() && end<=ans.back()[1]){
            continue;
        }

        for(int j=i+1;j<n;j++){
            if(intervals[j][0]<=end){
                end=max(end,intervals[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({start,end});
    }

    return ans;
}



//Optimal approach
T.C:-O(n log n)+O(n)
S.C:-O(1)
  
#include <bits/stdc++.h> 
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    int n=intervals.size();
    vector<vector<int>>ans;
    sort(intervals.begin(),intervals.end());
    for(int i=0;i<n;i++){
        if(ans.empty() || intervals[i][0]>ans.back()[1]){
            ans.push_back(intervals[i]);
        }
        else{
            ans.back()[1]=max(ans.back()[1],intervals[i][1]);
        }
    }
    return ans;
}
