#include <bits/stdc++.h> 
int solve(int i,int j){
	if(i < 0 || j < 0 ){
		return 0;
	}
	if(i == 0 && j== 0) return 1;

   int up = solve(i - 1,j);
   int left = solve(i,j-1);

   return up+left;

}

int solvemem(int i,int j,vector<vector<int>> &dp){
	if(i < 0 || j < 0 ){
		return 0;
	}
	if(i == 0 && j== 0) return 1;

	if(dp[i][j] != -1) return dp[i][j];

   int up = solvemem(i - 1,j,dp);
   int left = solvemem(i,j-1,dp);

   return dp[i][j] = up+left;

}

int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m,vector<int>(n,-1));
	return solvemem(m-1,n-1,dp);
}