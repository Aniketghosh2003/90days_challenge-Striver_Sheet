#include <bits/stdc++.h> 

int maximumProfit(vector<int> &prices){
    int mini = prices[0];
    int profit = 0;
    int n = prices.size();
    for(int i = 1;i < n;i++){
       int curr_profit = prices[i] - mini;
       profit = max(curr_profit,profit);
       mini = min(mini,prices[i]);
    }
    return profit;
}