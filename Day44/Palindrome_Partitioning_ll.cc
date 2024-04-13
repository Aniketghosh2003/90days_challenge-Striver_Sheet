bool ispalin(int i ,int j ,string& str){
    while(i < j){
        if(str[i] != str[j]) return false;
        i++;
        j--;
    }
    return true;
}

int solve(int i, int n,string &str,vector<int> &dp){
     if(i == n){
         return 0;
     }

     if(dp[i] != -1)
        return dp[i];

     int mincost = INT_MAX;
     for(int j = i;j < n;j++){
         if(ispalin(i,j,str)){
             int cost = 1+solve(j+1,n,str,dp);
             mincost = min(cost,mincost);
         }
     }
     return dp[i] = mincost;
}

int palindromePartitioning(string str)
{
    int n = str.size();
    vector<int> dp(n,-1);
    return solve(0,n,str,dp) - 1;
}
