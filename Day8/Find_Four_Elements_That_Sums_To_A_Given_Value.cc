#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    sort(arr.begin(),arr.end());
    for(int i = 0;i < n;i++){
        for(int j = i+1; j < n;j++){
            int k = j+1;
            int l = n-1;
            while(k < l){
                int sum = arr[i] + arr[j] + arr[k] + arr[l];
                if(sum < target){
                    k++;
                }
                else if(sum > target){
                    l--;
                }
                else if(sum == target){
                    return "Yes";
                }
            }
        }
    }
    return "No";
}
