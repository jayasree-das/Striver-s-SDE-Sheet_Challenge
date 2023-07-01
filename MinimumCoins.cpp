//Greedy solution
T.C:-O(amount)
S.C:-O(1)
#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    //notes available in india
    int deno[]={1,2,5,10,20,50,100,500,1000};
    //total no of coins required
    int coins=0;
    //n=8 as it is zero based indexing
    int n=8;
    while(amount && n>=0){
        if(amount<deno[n]){
            n--;
            continue;
        }

        coins++;
        amount-=deno[n];
    }
    return coins;
}

//optimzed greedy solution
T.C:-O(n) where n is the no of available denominations
S.C:-O(1)
#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    int deno[]={1,2,5,10,20,50,100,500,1000};
    int coins=0;
    int n=9;
    for(int i=n-1;i>=0;i--){
        coins+=amount/deno[i];
        amount=amount%deno[i];
    }
    return coins;
}
