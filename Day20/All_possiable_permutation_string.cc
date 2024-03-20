#include <bits/stdc++.h> 

void solve(string &s,vector<string> &ans,int ind){
    if(ind >= s.length()){
        ans.push_back(s);
        return ;
    }

    for(int i = ind;i < s.length();i++){
        swap(s[ind],s[i]);
        solve(s,ans,ind+1);
         swap(s[ind],s[i]);
    }
}

vector<string> findPermutations(string &s) {
    vector<string> ans;

    solve(s,ans,0);
    return ans;
}