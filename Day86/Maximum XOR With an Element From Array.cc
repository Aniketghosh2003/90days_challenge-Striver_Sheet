#include "algorithm"
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	vector<int> ans(queries.size(),-1);
    sort(arr.begin(),arr.end());
    int n = arr.size();

    for(int i = 0;i < queries.size();i++){
        int x = queries[i][0];
        int y = queries[i][1];
        int s = 0,e = n-1,mid,ind = -1;

        while(s <= e){
           mid = s+(e-s)/2;
           if(arr[mid] <= y){
               ind = mid;
               s = mid+1;
           }
           else{
               e = mid - 1;
           }
        }

        if(ind != -1){
            for(int j = 0;j <= ind;j++){
                ans[i] = max(ans[i],x ^ arr[j]);
            }
        }
        
    }
    return ans;
}