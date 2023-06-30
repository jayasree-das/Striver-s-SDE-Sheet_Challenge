//Greedy solution
T.C:-O(n log n)
S.C:-O(n)

#include <bits/stdc++.h>
//creating the new array strucure
struct meeting{
    int pos;
    int startTime;
    int endTime;
};
bool compare(struct meeting m1,meeting m2){
    if(m1.endTime==m2.endTime){
        return m1.pos<m2.pos;
    }
    else{
        return m1.endTime<m2.endTime;
    }
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    int n=start.size();
    //creating a meet array of size n
    struct meeting meet[n];
    for(int i=0;i<n;i++){
        meet[i].startTime=start[i];
        meet[i].endTime=end[i];
        meet[i].pos=i+1;
    }
    //sorting the meetings in increasing order of ending time
    sort(meet,meet+n,compare);

    vector<int>res;
    //initially room is empty so push the meeting and take the ending time
    res.push_back(meet[0].pos);
    int limit=meet[0].endTime;

    for(int i=1;i<n;i++){
        if(meet[i].startTime>limit){
            res.push_back(meet[i].pos);
            limit=meet[i].endTime;
        }
    }
    return res;
}


//Alternative approach using a vector instead of making a new object
#include <bits/stdc++.h> 
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    vector<pair<int,pair<int,int>>>ans;
    for(int i=0;i<start.size();i++){
        ans.push_back({end[i],{i+1,start[i]}});
    }
    sort(ans.begin(),ans.end());
    vector<int>res;
    int endingTime=-1;
    for(auto it:ans){
        if(it.second.second>endingTime-1){
            res.push_back(it.second.first);
            endingTime=it.first+1;
        }
    }
    return res;
}
