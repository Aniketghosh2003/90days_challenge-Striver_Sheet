#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    // int n = price.size();
    // vector<int> ans;
    // int cnt = 1;
    // for(int i = 0;i < n;i++){
    //     for(int j = i-1;j >= 0 ;j--){
    //         if(price[i] < price[j]){
    //             break;
    //         }
    //         else if(price[i] >= price[j]){
    //             cnt++;
    //         }
    //     }
    //     ans.push_back(cnt);
    //     cnt = 1;
    // }
    // return ans;
    
    int n = price.size();
    vector<int> ans;
    stack<int> st;

    for(int i = 0;i < n ;i++){
        while(!st.empty() && price[st.top()] <= price[i]){
             st.pop();
        }
        if(st.empty()) ans.push_back(i+1);
        else ans.push_back(i-st.top());

         st.push(i);
    }

    return ans;
}