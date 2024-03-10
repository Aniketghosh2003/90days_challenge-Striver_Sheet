#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
      int n = arr.size();
      vector<vector<int>> ans;
      sort(arr.begin(),arr.end());
      for(int i = 0;i < n;i++){
         for(int j = i+1;j < n;j++){
            if(arr[i] + arr[j] == s){
             vector<int> temp;
             temp.push_back(min(arr[i],arr[j]));
             temp.push_back(max(arr[i],arr[j]));
             ans.push_back(temp);
            }
         }
      }
      return ans;
}