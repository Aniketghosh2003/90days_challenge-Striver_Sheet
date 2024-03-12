#include <bits/stdc++.h> 
int longestSubSeg(vector<int> &arr , int n, int k){
    int i = 0;
    int j = 0;
    int zerocount = 0;int ans = 0;

    while(j < n){
        if(arr[j] == 0){
            zerocount++;
        } 

        while(zerocount > k){
            if(arr[i] == 0) zerocount--;

            i++;
        }

        ans = max(ans,j-i+1);
        j++;
    }
    return ans;
}