#include <bits/stdc++.h>
int singleNonDuplicate(vector<int>& arr)
{
	 int n = arr.size();
    // unordered_map<int,int> mp;
    
    // for(int i = 0;i < n;i++){
    //     mp[arr[i]]++;
    // }

    // for(auto i:mp){
    //     if(i.second == 1){
    //         return i.first;
    //     }
    // }
     
    int low = 0;
    int high = n-1;

    if(n == 1){
        return arr[0];
    }

    while(low <= high){
        int mid = low + (high - low)/2;

        if(arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1]){
            return  arr[mid];
        }

        if(((mid%2 == 0) && (arr[mid] == arr[mid+1]))||((mid%2==1) && (arr[mid] == arr[mid-1]))){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

}