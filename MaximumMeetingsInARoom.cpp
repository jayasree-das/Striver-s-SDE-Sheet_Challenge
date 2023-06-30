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
