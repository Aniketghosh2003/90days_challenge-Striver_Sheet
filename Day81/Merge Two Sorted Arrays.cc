#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	vector<int> arr(m);
	for(int i = 0;i < m;i++){
		arr[i] = arr1[i];
	}
    int mainindex = 0,i  = 0,j = 0;

	while(i < m && j < n){
           if(arr[i] < arr2[j]){
			   arr1[mainindex++] = arr[i++];
		   }
		   else{
               arr1[mainindex++] = arr2[j++];
		   }
	}

	while(i < m){
		arr1[mainindex++] = arr[i++];
	}

	while(j < n){
		arr1[mainindex++] = arr2[j++];
	}
    return arr1;
}