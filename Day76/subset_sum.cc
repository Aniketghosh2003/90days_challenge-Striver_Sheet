void solve(vector<int> &num,vector<int> &ans,int n ,int sum,int i){
	if(i == n){
		ans.push_back(sum);
		return ;
	}

	solve(num,ans,n,sum, i+1);

	solve(num, ans, n, sum + num[i], i+1);
}

vector<int> subsetSum(vector<int> &num){
	vector<int> ans;
	solve(num,ans,num.size(),0,0);
	sort(ans.begin(),ans.end());
	return ans;
}