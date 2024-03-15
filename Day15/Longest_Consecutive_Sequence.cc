#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // sort(arr.begin(),arr.end());
    // int max_len = 1;
    // for(int i = 0;i < n;i++){
    //     int curr_len = 1;
    //     int ele = arr[i];
    //     for(int j = i+1;j < n;j++){
    //         if(ele+1 ==  arr[j]){
    //             curr_len++;
    //             ele = arr[j];
    //         }
    //     }
    //     max_len = max(max_len,curr_len);
    // }
    // return max_len; 

    int max_len = 1;
    unordered_set<int> st;

    for(int i = 0;i < n;i++){
        st.insert(arr[i]);
    } 
    
    for(auto it:st){
        if(st.find(it-1) == st.end()){
            int x = it;
            int curr_len = 1;

            while(st.find(x+1) != st.end()){
                x = x+1;
                curr_len ++;
            }
             max_len = max(curr_len,max_len);
        }
       
    }

    return max_len;
}
