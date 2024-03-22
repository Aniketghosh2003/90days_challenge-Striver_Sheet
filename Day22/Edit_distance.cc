#include <bits/stdc++.h> 
int solvemem(string &str1, string &str2, vector<vector<int >> &dp,int i ,int j){
    if(i == str1.length()){
       return str2.length() - j;
    }

    if(j == str2.length()){
        return str1.length() - i;
    }
    
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int ans  = INT_MIN;
    if(str1[i] == str2[j]){
        return solvemem(str1,str2,dp,i+1,j+1);
    }
    else{
           int insert = 1+ solvemem(str1,str2,dp,i,j+1);
           int delete1 = 1+ solvemem(str1,str2,dp,i+1,j);
           int replace = 1+solvemem(str1,str2,dp,i+1,j+1);

           ans = min(insert,min(delete1,replace));
    }
    return dp[i][j] = ans;
}

int editDistance(string str1, string str2) {
     vector<vector<int >> dp(str1.size()+1,vector<int> (str2.size()+1,-1));
     return  solvemem(str1,str2,dp,0,0);
}