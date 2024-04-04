#include <bits/stdc++.h> 

// int solve(string &s, string &t,int i,int j){
//       int n = s.length();
//      int m  = t.length();

//      if(i == n || j == m )
//        return 0;

//      if(s[i] == t[j]){
//           return 1+solve(s,t,i+1,j+1);
//      }
//      else{
//           return max(solve(s,t,i+1,j),solve(s,t,i,j+1));
//      }
// }

int solvemem(string &s, string &t,int i,int j,vector<vector<int>>& dp){
      int n = s.length();
     int m  = t.length();

     if(i == n || j == m )
       return 0;

     if(dp[i][j] != -1)return dp[i][j];

     int ans = 0;
     if(s[i] == t[j]){
          ans =  1+solvemem(s,t,i+1,j+1,dp);
     }  
     else{
          ans =  max(solvemem(s,t,i+1,j,dp),solvemem(s,t,i,j+1,dp));
     }

     return dp[i][j] = ans;
}

int solvetab(string &s, string &t){
     int n = s.length();
     int m  = t.length();
     vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i = n-1;i >= 0;i--){
         for(int j = m-1;j >= 0;j--){
              int ans = 0;
     if(s[i] == t[j]){
          ans =  1+dp[i+1][j+1];
     }  
     else{
          ans =  max(dp[i+1][j] , dp[i][j+1]);
     }

     dp[i][j] = ans;
         }
    }

    return dp[0][0];

}

int lcs(string s, string t)
{
      int n = s.length();
     int m  = t.length();
     vector<vector<int>> dp(n,vector<int>(m,-1));
	return solvetab(s,t);
}