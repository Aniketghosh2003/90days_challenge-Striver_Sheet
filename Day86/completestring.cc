#include <bits/stdc++.h> 
string completeString(int n, vector<string> &a){
    map<string,int> mp;
    for(auto i:a){
        mp[i]++;
    }
     sort(a.begin(),a.end());
    string res = "";
    for(auto i:a){
         string s = "";
         bool flag = true;
         for(int j = 0;j < i.size();j++){
            s += i[j];
             if(mp.find(s) == mp.end()){
                 flag = false;
                 break;
             }
         }
         if(flag && i.size() > res.size()){
             res = i;
         }
    }
    if(res == "") return "None";
    return res;
}
