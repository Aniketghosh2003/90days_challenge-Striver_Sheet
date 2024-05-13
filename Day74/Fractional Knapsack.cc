#include <bits/stdc++.h> 

bool cmp(pair<int,int> &a,pair<int,int> & b){
       double r1 = (double)a.second/a.first;
       double r2 = (double)b.second/b.first;

       return r1 > r2;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
   double ans = 0;
   double currwt = 0;

   sort(items.begin(),items.end(),cmp);

   for(int i = 0;i < n;i++){
       if(currwt + items[i].first <= w){
            currwt += items[i].first;
            ans += items[i].second;
       }
       else{
           int remain = w - currwt;
           currwt += remain;

           ans += ((double)items[i].second/items[i].first) * remain;
       }
   }

   return ans;
}