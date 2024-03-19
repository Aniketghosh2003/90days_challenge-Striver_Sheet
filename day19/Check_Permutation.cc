#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
      int s1size = str1.length();
      int s2size = str2.length();
     
     unordered_map<char,int> mp;
     for(int i = 0;i < s1size;i++){
         mp[str1[i]]++;
     }

     for(int i = 0;i < s2size;i++){
         mp[str2[i]]++;
     }

     for(auto it:mp){
         if(it.second == 1){
             return false;
         }
     }
     return true;
}