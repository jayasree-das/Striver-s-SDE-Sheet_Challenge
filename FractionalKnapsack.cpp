//Greedy solution
T.C:-O(n log n)+O(n)
S.C:-O(1)
#include <bits/stdc++.h>
bool compare(pair<int,int>a,pair<int,int>b){
    //r1 = value / weight
    double r1=(double)a.second/(double)a.first;
    double r2=(double)b.second/(double)b.first;
    return r1>r2;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    //we will greedily take the item having more value/weight first 
    //sort in decreasing order of value/weight
    sort(items.begin(),items.end(),compare);

    int currWeight=0;
    double finalValue=0.0;

    for(int i=0;i<n;i++){
        if(currWeight+items[i].first<=w){
            currWeight+=items[i].first;
            finalValue+=items[i].second;
        }
        else{
            //if the weight exceeds w then find remaining weight
            int remain=w-currWeight;
            //go to next item,find the value/weight and multiply by remaining weight
            finalValue+=(items[i].second/(double)items[i].first)*(double)remain;
            break;
        }
    }
    return finalValue;
}
