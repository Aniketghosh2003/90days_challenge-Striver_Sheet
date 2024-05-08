#include <bits/stdc++.h> 

bool solve( int k, vector<int> &arr,int i){
    if(k == 0)
       return true;

    if(k < 0)  return false;

    if(i < 0 ) return false;

    bool incl = solve(k-arr[i],arr,i-1);

    bool excl = solve(k,arr,i-1);

    return incl or excl ;
}

bool solvemem( int k, vector<int> &arr,int i, vector<vector<int>> &dp){
    if(k == 0)
       return true;

    if(k < 0)  return false;

    if(i < 0 ) return false;

    if(dp[i][k] != -1)  return  dp[i][k];

    bool incl = solvemem(k-arr[i],arr,i-1,dp);

    bool excl = solvemem(k,arr,i-1,dp);

    return dp[i][k] = incl or excl ;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {

    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return solvemem(k,arr,n-1,dp);
}