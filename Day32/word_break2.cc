#include <bits/stdc++.h> 

 

void solve(string &s,int idx,vector<string> &dic,vector<string> &ans,string ss){

    if(idx==s.size()){

        ans.push_back(ss);

        return;

    }

    for(int i=idx;i<s.size();i++){

        string target=s.substr(idx,i-idx+1);

        if(find(dic.begin(), dic.end(), target) != dic.end()){

            solve(s,i+1,dic,ans,ss+target+" ");

        }

    }

}

vector<string> wordBreak(string &s, vector<string> &dic){

    vector<string> ans;

    string ss="";

    solve(s,0,dic,ans,ss);

    return ans;

}