#include <bits/stdc++.h> 

bool solve(int i , string & target , set < string > & arr) {
if(i == target.size()) return true;

string temp;

for (int k = i; k < target.size(); k++) {
  temp += target[k];
  if (arr.find(temp) != arr.end()) {

    if (solve(k + 1, target, arr))
      return true;

  }
}
return false;
}

int solvemem(int i , string & target , set < string > & arr,vector<int> & dp){
     if(i == target.size()) return 1;

string temp;
 if(dp[i] != -1)  return dp[i];

for (int k = i; k < target.size(); k++) {
  temp += target[k];
  if (arr.find(temp) != arr.end()) {

    if (solve(k + 1, target, arr))
      return dp[i] =  1;

  }
}
return dp[i] = 0;
}


bool wordBreak(vector < string > & arr, int n, string & target) {
       set<string> st;
       for(auto a:arr) st.insert(a);
       
       vector<int> dp(n,-1);
       return solvemem(0,target,st,dp);
}