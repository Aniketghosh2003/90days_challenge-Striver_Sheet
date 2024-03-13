#include <bits/stdc++.h> 
// int solve(int arr[],int n, int curr,int prev){
//     if(curr == n){
//         return 0;
//     }
//     int take  = 0;
//     if(prev == -1 || arr[curr] > arr[prev]){
//         take = 1 + solve(arr,n,curr+1, curr);
//     }
//     int notake = solve(arr,n,curr+1,prev);
//     return max(take,notake);
// }
// int solvedp(int arr[],int n, int curr,int prev,vector<vector<int>> &dp){
    
//     if(curr == n){
//          return 0;
//     }

//     if(dp[curr][prev+1] != -1){
//         return dp[curr][prev+1];
//     }
//     int take  = 0;
//     if(prev == -1 || arr[curr] > arr[prev]){
//         take = 1 + solvedp(arr,n,curr+1, curr,dp);
//     }
//     int notake = solvedp(arr,n,curr+1,prev,dp);
//     return dp[curr][prev+1] = max(take,notake);
// }

int solvetab(int arr[], int n){
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    
    for(int curr = n-1; curr>= 0;curr--){
        for(int prev = n-1;prev >= -1;prev--){
            int take  = 0;
            if(prev == -1 || arr[curr] > arr[prev]){
              take = 1 + dp[curr+1][curr+1];
            }
            int notake = dp[curr+1][prev+1];
            dp[curr][prev+1] = max(take,notake);
        }
    }
    return dp[0][0];
}

int longestIncreasingSubsequence(int arr[], int n)
{   
    // vector<vector<int>> dp(n,vector<int>(n+1,-1));
    // // return solvedp(arr,n,0,-1,dp);
    return solvetab(arr, n) ;

}

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> ans;
    ans.push_back(arr[0]);
    for(int i = 1;i < n;i++){
        if(arr[i] > ans.back()){
            ans.push_back(arr[i]);
        }
        else{
            int index = lower_bound(ans.begin(),ans.end(),arr[i]) - ans.begin();
            ans[index] = arr[i];
        }
    }
    return ans.size();
}
