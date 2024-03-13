#include <bits/stdc++.h> 
int solvetab(vector<int> &rack, int n){
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    
    for(int curr = n-1; curr>= 0;curr--){
        for(int prev = n-1;prev >= -1;prev--){
            int take  = 0;
            if(prev == -1 || rack[curr] > rack[prev]){
              take = rack[curr] + dp[curr+1][curr+1];
            }
            int notake = dp[curr+1][prev+1];
            dp[curr][prev+1] = max(take,notake);
        }
    }
    return dp[0][0];
}
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	return solvetab(rack,n);
}