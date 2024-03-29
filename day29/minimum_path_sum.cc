#include <bits/stdc++.h>

// int solve(vector<vector<int>> &grid,int i,int j)
// {

//     if(i==0 && j==0)

//         return grid[0][0];

//     if(i<0 || j<0)

//         return INT_MAX;

//     int up=  solve(grid,i-1,j);

//     int left=   solve(grid,i,j-1);

//     return grid[i][j] + min(up,left);

// } 

int solvemem(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &dp){
      if(i==0 && j==0)

        return grid[0][0];

    if(i<0 || j<0)

        return INT_MAX;

     if(dp[i][j] != -1){
        return dp[i][j];
     }   

    int up=  solvemem(grid,i-1,j,dp);

    int left=   solvemem(grid,i,j-1,dp);

    return dp[i][j] = grid[i][j] + min(up,left);

}

int minSumPath(vector<vector<int>> &grid) {

   
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
   // return solve(grid,m-1,n-1);

   return  solvemem(grid,n-1,m-1,dp);

}