#include <bits/stdc++.h> 

long solve(int *denominations, int n, int value,long i,vector<vector<long>>& dp){
      if(value == 0)
          return 1;

      if(i >= n)  return 0;

      if(value < 0) return 0;
      if(dp[i][value] != -1)  return dp[i][value]; 

      long incl = solve(denominations,n,value - denominations[i],i,dp);
      long excl = solve(denominations,n,value,i+1,dp);

      return dp[i][value] =  (incl+excl);   
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    long i = 0;
    vector<vector<long>> dp(n+1, vector<long>(value+1, -1));
    return solve(denominations,n,value,i,dp);
}