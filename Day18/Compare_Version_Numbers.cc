#include <bits/stdc++.h>
int compareVersions(string a, string b) {
    int i = 0;
    int j = 0;
    while(i < a.length() || j < b.length()){
          long  x = 0;
          long  y = 0;

          while(i < a.length() && a[i] != '.'){
             x = x*10 + (a[i++] - '0');
          }
          while(j < b.length() && b[j] != '.'){
               y = y*10 + (b[j++] - '0');
          }

          if(x > y){
              return 1;
          }
          if(y > x){
              return -1;
          }
          i++;
          j++;
    }
    return 0;
}