#include <bits/stdc++.h>
static bool cmp(pair<int,int>a,pair<int,int>b){
    return a.second<b.second;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n  = start.size();
    int max  =  1;

    vector<pair<int,int>>arr;

    for(int i = 0;i < n;i++){
        arr.push_back({start[i],finish[i]});
    }

    sort(arr.begin(),arr.end(),cmp);
    int j = 0;

    for(int i = 1;i < n;i++){
        if(arr[i].first>=arr[j].second){
            max++;
            j = i;
        }
    }
    return max;
}