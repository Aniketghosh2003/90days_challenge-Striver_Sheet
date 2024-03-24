double median(vector<int>& a, vector<int>& b) {
	int n = a.size();
	int m = b.size();
	vector<int> arr(n+m);
    int i1 = 0;
	int i2 = 0;
	int mainindex = 0;
	while(i1 < n && i2 < m){
         if(a[i1] < b[i2]){
			 arr[mainindex++] = a[i1++];
		 }
		 else{
			 arr[mainindex++] = b[i2++];
		 }
	}

	while(i1 < n){
        arr[mainindex++] = a[i1++];
	}
	while(i2 < m){
         arr[mainindex++] = b[i2++];
	}

	if((m+n) % 2 == 0){
        return (arr[(n+m)/2] + arr[(n+m)/2 - 1])/2.0;
	}
	else if((n+m) % 2 != 0){
           return arr[(n+m)/2];
	}
}