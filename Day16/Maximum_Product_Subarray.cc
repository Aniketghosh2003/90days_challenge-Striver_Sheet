#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n)
{
	// int max_prod = INT_MIN;
	// for(int i = 0;i < n-1;i++){
	// 	for(int j = i+1;j < n;j++){
	// 		int product = 1;
	// 		for(int k = i;k <= j;k++){
	// 			product = product * arr[k];
	// 		}
	// 		max_prod = max(product ,max_prod);
	// 	}
	// }
    // return max_prod;
    
	int ans = INT_MIN;
	int preffix = 1;
	int suffix = 1;
	for(int  i = 0;i < n;i++){
        if(preffix == 0) preffix = 1;
		if(suffix == 0) suffix = 1;

		preffix = preffix * arr[i];
		suffix = suffix * arr[n - i - 1];

		ans = max(ans ,max(preffix,suffix));
	}

    return ans;
}