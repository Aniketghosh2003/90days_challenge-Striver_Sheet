#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

    int n = arr.size();
    int cnt =  0;
    int sum = 0;

    unordered_map<int,int> map;
    map[0] = -1;
    for(int i = 0;i < n;i++){
      sum +=  arr[i];
      
      if(map.find(sum) != map.end()) {
        cnt = max(cnt,i-map[sum]);
      }
      else{
        map[sum]=i;
      }
    }
    return cnt;

    // int n = arr.size();
    // int cnt =  0;
    
    // for(int i = 0;i < n;i++){
    //   int sum = 0;
    //   for(int  j = i;j < n;j++){
    //     sum += arr[j];
        
    //     if(sum == 0){
    //        cnt  = max(cnt,j-i+1); 
    //     }
    //   }
      
    // }
    // return cnt;
}