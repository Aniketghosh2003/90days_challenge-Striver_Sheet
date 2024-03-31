vector<int> stringMatch(string text, string pattern) {
	vector<int> ans;

	int n = text.length();
	int m = pattern.length();

	for(int i = 0;i < n -m+1;i++){
        int first = i;
		int second = 0;
		int flag = 0;
		while(second < m){
            if(text[first] == pattern[second]){
				first++;
				second++;
			}
			else{
				flag = 1;
				break;
			}
		}

		if(flag == 0){
            ans.push_back(i+1);
		}
	}
	return ans;
}
