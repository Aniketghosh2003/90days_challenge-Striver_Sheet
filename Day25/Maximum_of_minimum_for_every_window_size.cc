#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> a, int n) {
    //vector<int> ans(n,INT_MIN);

    // for(int i = 0;i < n;i++){
    //     for(int j = 0;j < n-i;j++){
    //         int num = INT_MAX;
    //         for(int k = j ; k < i+j+1;k++){
    //             num = min(a[k],num);
    //         }
    //         ans[i] = max(ans[i],num);
    //     }
    // }
    // return ans;


    vector<int> ans(n,INT_MIN);
    
    stack<int> s;
    a.push_back(INT_MIN);
    
    for (int i = 0; i < a.size(); i++)
    {
        while(!s.empty() && a[s.top()]>=a[i]){
            int top = a[s.top()]; s.pop();
            int smal_left = s.empty()? -1 : s.top();
            int range = i - smal_left - 1;
            if(ans[range-1]<top) ans[range-1] = top;
        }
        s.push(i);
    }

    int max=INT_MIN;

    for(int i = ans.size()-1;i>-1;i--){
        if(ans[i]>max) max = ans[i];
        ans[i] = max;
    }
    
    return ans;

}