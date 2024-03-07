#include <bits/stdc++.h>
// set<vector<int>> st;
  
//   for(int i = 0;i < n-2;i++)
//   {
// 	  for(int j = i+1; j<n-1;j++)
// 	  {
// 		  for(int k = j+1; k<n;k++)
// 		  {
// 			  if(arr[i]+arr[j]+arr[k] == K)
// 			  {
// 				   vector<int> temp = {arr[i],arr[j],arr[k]};
//                 sort(temp.begin(),temp.end());
//                 st.insert(temp);
// 			  }
// 		  }
// 	  }
//   }
//   vector<vector<int>> ans(st.begin(),st.end());
//   return ans; 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {

    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());

    for(int i = 0;i < n;i++){
    if (i > 0 && arr[i] == arr[i - 1]) {
      
      continue;
    }
       int j = i+1;
       int k = n-1;
       while(j < k){
           int sum = arr[i] + arr[j] + arr[k];
           if(sum < K){
               j++;
           }
           else if(sum > K){
               k--;
           }
           else{
               vector<int> temp = {arr[i],arr[j],arr[k]};
               ans.push_back(temp);
              j++;
              k--;
              while(j < k && arr[j] == arr[j-1]) j++;
              while(j < k && arr[k] == arr[k+1]) k--;
            
           }
       }
    }
    return ans;
}