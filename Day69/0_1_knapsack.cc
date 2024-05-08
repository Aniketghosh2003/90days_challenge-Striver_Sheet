#include <bits/stdc++.h> 

int solvemem(vector<int> &values, vector<int> &weights, int n, int w,vector<vector<int>>& dp){
    if(n == 0){
		if(weights[0] <= w)
		    return values[0];
		else  return 0;	
	}

	if(dp[n][w] != -1)
	  return dp[n][w];

	int include = 0;
    int excl = 0;
	
	if(weights[n] <= w)
	   include = values[n] + solvemem(values,weights, n-1, w - weights[n], dp);
	
	excl = solvemem(values, weights, n- 1,  w, dp);   
    
	dp[n][w] = max(include,excl);
	return dp[n][w];
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> dp(n,vector<int>(w+1,-1));

	return solvemem(values,weights,n-1,w,dp);
}