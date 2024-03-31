#include <bits/stdc++.h> 

// int solve(int i ,int j,vector<int> &arr){
//     if(i==j){
//         return 0;
//     }
//     int mini = 1e9;
//     for(int k = i;k < j;k++){
//         int steps = arr[i-1]*arr[k]*arr[j] + solve(i,k,arr)+solve(k+1,j,arr);
//         mini = min(steps,mini);
//     }
//     return mini;
// }

int solvemem(int i ,int j,vector<int> &arr,vector<vector<int>> &dp){
     if(i==j){
        return 0;
    }

    if(dp[i][j] != -1) return dp[i][j];

    int mini = 1e9;
    for(int k = i;k < j;k++){
        int steps = arr[i-1]*arr[k]*arr[j] + solvemem(i,k,arr,dp)+solvemem(k+1,j,arr,dp);
        mini = min(steps,mini);
    }
    return dp[i][j] = mini;
}

int solvetab(int i ,int j,vector<int> &arr,int N){
     vector<vector<int>> dp(N,vector<int> (N,0));

     for(int i = N-1;i >= 1;i--){
         for(int j = i+1;j < N;j++){
             int mini = 1e9;
    for(int k = i;k < j;k++){
        int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
        mini = min(steps,mini);
    }
     dp[i][j] = mini;
         }
     }
     return dp[1][N-1];
}

int matrixMultiplication(vector<int> &arr, int N)
{
//    return solve(1,N-1,arr);
vector<vector<int>> dp(N,vector<int> (N,-1));
// return solvemem(1,N-1,arr,dp);
return solvetab(1, N-1, arr,N);
}