#include <bits/stdc++.h>
#include <vector>

int findDuplicate(vector<int> &arr, int n){
	// for(int i = 0; i < n;i++){
	// 	for(int j = i+1;j < n;j++){
	// 		if(arr[i] == arr[j]){
	// 			return arr[i];
	// 		}
	// 	}
	// }

	sort(arr.begin(),arr.end());
	for(int i = 0; i < n;i++){
		if(arr[i] == arr[i+1]){
			return arr[i];
		}
	}
}
