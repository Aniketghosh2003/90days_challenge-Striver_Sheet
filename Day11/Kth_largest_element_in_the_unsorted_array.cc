#include <bits/stdc++.h>
int kthLargest(vector<int> &arr, int size, int K) {


  // sort(arr.begin(),arr.end());
  // return arr[size - K];

  
  priority_queue<int, vector<int>, greater<int>> minheap;
  for (int i = 0; i < size; i++){
	  minheap.push(arr[i]);
	  if(minheap.size() > K){
		  minheap.pop();
	  }
  }

  return minheap.top();
}