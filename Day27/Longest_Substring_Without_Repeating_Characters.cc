#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    int ans = 0;
    int n = input.size();
    
    for(int i  =0;i < n;i++){
        unordered_map<char,bool> mp;

        for(int j = i;j < n;j++){
            if(mp[input[j]])  break;
            else{
                ans  = max(ans,j - i+1);
                mp[input[j]] = true;
            }
        }
        mp[input[i]] = false;
    }
    return ans;
}
