long long maxSubarraySum(vector<int> arr, int n)
{
    long long sum = 0;
    long long max_sum = INT_MIN;

    for(int i = 0;i < n;i++){
        sum += arr[i];

        if(sum < 0)
          sum = 0;

        max_sum = max(max_sum,sum);
    }

    

    return max_sum;
}