#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
  int n = arr.size();
  vector<int> ans;
  unordered_map<int, int> map;

  for (int i = 0; i < n; i++){
	  map[arr[i]]++;
  }
  
  for(auto i:map){
	  if(i.second > n/3){
		  ans.push_back(i.first);
	  }
    }
    return ans;
}