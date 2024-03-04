#include <bits/stdc++.h>
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	vector<int> ans;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	priority_queue<pair<int,pair<int,int>>> pq;
	set <pair<int,int>> s;
    pq.push({a[n - 1] + b[n - 1],{n-1,n-1}});
    s.insert({n-1,n-1});

	while(k--){
		auto top = pq.top();
		pq.pop();
        ans.push_back(top.first);
		int l = top.second.first;
		int r = top.second.second;
		if(s.find({l-1,r})==s.end()){
			pq.push({a[l-1] + b[r],{l-1,r}});
			s.insert({l-1,r});
		}
		if(s.find({l,r-1})==s.end()){
			pq.push({a[l]+b[r-1],{l,r-1}});
			s.insert({l,r-1});
		}
	}

	return ans;
}