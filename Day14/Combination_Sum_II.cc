#include <bits/stdc++.h> 

void solve(int target,int ind,vector<vector<int>> &ans,vector<int> &ds,vector<int> &arr){
    if(target == 0){
        ans.push_back(ds);
        return;
    }
    for (int i = ind; i < arr.size(); i++) {
        if (i > ind && arr[i] == arr[i - 1])
          continue;
        if (arr[i] > target)
          break;

        ds.push_back(arr[i]);
        solve(target - arr[i], i + 1, ans, ds, arr);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
    sort(arr.begin(),arr.end());
	vector<vector<int>> ans;
    vector<int> ds;
    
    solve(target,0,ans,ds,arr);
    return ans;
}