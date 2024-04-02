#include <bits/stdc++.h>
int distinctSubstring(string &word) {
     unordered_map<string,int> mp;

     for(int i = 0;i < word.length();i++){
         for(int j = i;j < word.length();j++){
             mp[word.substr(i,j-i+1)]++;
         }
     }
     return mp.size();
}
