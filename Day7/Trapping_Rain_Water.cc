#include<algorithm>
//this approch has misake in it
// long long ans = 0;
//     long long *left = new long long[n];
//     long long *right = new long long[n];

    
//     left[0] = arr[0];
//     for(int i = 1;i < n;i++){
//         left[i] = max(left[i-1],arr[i]);
//     }

    
//     right[n-1] = arr[n-1];
//     for(int i = n-2;i >= 0;i--){
//        right[i] = max(right[i],arr[i]);
//     }

//     for(int i = 0;i < n;i++){
//         ans += min(left[i],right[i]) - arr[i];
//     }
//     return ans;
long long getTrappedWater(long long* arr, int n) {
    long long ans = 0;
    int left = 0;
    int right = n-1;

    long long lmax = 0;
    long long rmax = 0;

    while(left <= right){
        if(arr[left] <= arr[right]){
            if(arr[left] > lmax){
                lmax = arr[left];
            }
            else{
                ans += lmax - arr[left];
            }
            left++;
        }
        else{
            if(arr[right] > rmax){
                rmax = arr[right];
            }
            else{
                ans += rmax - arr[right];
            }
            right--;
        }
    }
    return ans;
}