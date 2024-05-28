#include <bits/stdc++.h> 

void solve(int n, vector<int> &arr,vector<vector<int>> &ans,vector<int> &temp,int i){
       if(i == n){
           ans.push_back(temp);
           return ;
       }

       temp.push_back(arr[i]);
       solve(n, arr, ans, temp, i+1);
       temp.pop_back();
       while(i+1 < n && arr[i] == arr[i+1]) i++;
       solve(n,arr,ans,temp,i+1);
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    vector<int> temp;
    solve(n,arr,ans,temp,0);
    sort(ans.begin(),ans.end());
    return ans;
}