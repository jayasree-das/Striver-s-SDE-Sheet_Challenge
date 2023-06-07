//Brute Force
#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int n=prices.size();
    int profit=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int curr_profit=prices[j]-prices[i];
            profit=max(profit,curr_profit);
        }
    }

    return profit;
}

T.C:-O(n2)
S.C:-O(1)
  
  
//Optimal solution
T.C:- O(n)
S.C:-O(1)
  
#include <bits/stdc++.h>
int maximumProfit(vector<int> &prices) {
    int n=prices.size();
    int profit=0;
    int minBuy=prices[0];
    for(int i=1;i<n;i++){
        int curr_profit=prices[i]-minBuy;
        profit=max(profit,curr_profit);
        minBuy=min(minBuy,prices[i]);
    }
    return profit;
}
