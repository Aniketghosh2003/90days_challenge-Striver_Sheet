vector<int> MinimumCoins(int n)
{
    int arr[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
   vector<int> ans;
    for(int i = 8;i >= 0;i--){
        if(arr[i] <= n){
            ans.push_back(arr[i]);
            n-= arr[i];

            i++;
        }
    }
    return ans;
}