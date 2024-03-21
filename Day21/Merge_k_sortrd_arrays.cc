#include <bits/stdc++.h> 

vector<int> merge(vector<int> a,vector<int> b){
    int n = a.size();int m = b.size();
    int i = 0;int j = 0;
    vector<int> ans;

    while(i < n && j < m){
        if(a[i] > b[j]){
            ans.push_back(b[j++]);
        }
        else{
            ans.push_back(a[i++]);
        }
    }
    while(i < n){
          ans.push_back(a[i++]);
    }
    while (j < m) {
          ans.push_back(b[j++]);
    }
    return ans;
}

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> ans;
    for(int i  = 0;i < k;i++){
         ans = merge(ans,kArrays[i]);
    }
    return ans;
}
