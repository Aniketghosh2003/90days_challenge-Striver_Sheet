#include <bits/stdc++.h> 

void solve(vector<vector<int>> &ans,vector<int> temp,vector<int>v,int i){
      if(i >= v.size()){
          ans.push_back(temp);
          return;
      }

      solve(ans,temp,v,i+1);

      temp.push_back(v[i]);

      solve(ans,temp,v,i+1);

     

}

vector<vector<int>> pwset(vector<int>v)
{
    vector<vector<int>> ans;
    vector<int> temp;

    solve(ans,temp,v,0);

    return ans;
}