#include<bits/stdc++.h>

int solvemem(vector<int> &price, int n,int i,vector<vector<int>> &dp){
    
	if(i == 0) return n*price[0];
	if(dp[i][n] != -1) return dp[i][n];

   int rodlen = i+1;
   int no_take = solvemem(price,n,i - 1,dp);
    int take = INT_MIN;

    if (rodlen <= n) {
      take = price[i] + solvemem(price, n - rodlen, i,dp);
    }

    return dp[i][n] = max(take,no_take);
}

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
	return solvemem(price,n,n-1,dp);
}