//Greedy solution
T.C:-O(n log n)
S.C:-O(n)
#include<bits/stdc++.h>
struct activity{
    int startTime;
    int endTime;
};
bool compare(struct activity a,struct activity b){
    return a.endTime<b.endTime;
}
int maximumActivities(vector<int> &start, vector<int> &end) {
    int n=start.size();
    struct activity act[n];
    for(int i=0;i<n;i++){
        act[i].startTime=start[i];
        act[i].endTime=end[i];
    }
    sort(act,act+n,compare);
    int ans=1;
    int limit=act[0].endTime;
    for(int i=1;i<n;i++){
        if(act[i].startTime>=limit){
            ans++;
            limit=act[i].endTime;
        }
    }
    return ans;
}


Another Method:-
T.C:-O(n log n)
S.C:-O(n)
#include<bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n=start.size();
    vector<pair<int,int>>activity(n);
    for(int i=0;i<n;i++){
        activity[i].first=finish[i];
        activity[i].second=start[i];
    }
    sort(activity.begin(),activity.end());
    int ans=1;
    int limit=activity[0].first;
    for(int i=1;i<n;i++){
        if(activity[i].second>=limit){
            ans++;
            limit=activity[i].first;
        }
    }
    return ans;
}
