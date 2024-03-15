#include <bits/stdc++.h>

void solve(int target,int ind,vector<vector<int>> &ans,vector<int> &ds,vector<int> &arr,int sum){
    if(target == sum){
        ans.push_back(ds);
    }
    for (int i = ind; i < arr.size(); i++) {
        ds.push_back(arr[i]);
        solve(target, i + 1, ans, ds, arr,sum+ arr[i]);
        ds.pop_back();
    }
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
	vector<vector<int>> ans;
    vector<int> ds;
     
    solve(k,0,ans,ds,arr,0);
    return ans;
}