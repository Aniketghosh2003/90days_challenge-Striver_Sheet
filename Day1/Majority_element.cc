#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {

  unordered_map<int, int> map;

  for (int i = 0; i < n; i++){
	  map[arr[i]]++;
  }

  for(auto i:map){
	  if(i.second > n/2){
		  return i.first;
	  }
  }
  return -1;
}