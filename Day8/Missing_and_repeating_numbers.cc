#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int mising , repeating;
	bool present[n+1] = {false};
    for(int i = 0;i <n;i++){
		if(present[arr[i]] == true){
             repeating = arr[i];
			 
		}
		present[arr[i]] = true;
	}
	for(int i = 1;i <= n;i++){
		if(present[i] == false){
			mising = i;
			break;
		}
	}

	return {mising,repeating};
}
