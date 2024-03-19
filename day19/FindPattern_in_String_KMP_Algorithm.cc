#include <bits/stdc++.h> 
bool findPattern(string p, string s)
{
    int n = s.size();
    int m = p.size();
    for(int i = 0;i < n-m+1;i++){
        if(s.substr(i,m) == p){
            return true;
        }
    }
    return false;
}