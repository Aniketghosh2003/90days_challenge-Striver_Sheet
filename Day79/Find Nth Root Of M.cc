// long long func(int b, int exp) {
//     long long  ans = 1;
//     long long base = b;
//     while (exp > 0) {
//         if (exp % 2) {
//             exp--;
//             ans = ans * base;
//         }
//         else {
//             exp /= 2;
//             base = base * base;
//         }
//     }
//     return ans;
// }

int solve(int mid,int n,int m){
    long long ans = 1;
    for(int i = 1;i <= n;i++){
        ans *= mid;
        if(ans > m) return 2;
    }
    if(ans == m) return 1;
    else return 0;
}

int NthRoot(int n, int m) {
    
    // for (int i = 1; i <= m; i++) {
    //     long long val = func(i, n);
    //     if (val == m * 1ll) return i;
    //     else if (val > m * 1ll) break;
    // }
    // return -1;

    int low = 1,high = m,mid;
    while(low <=high){
        mid = low + (high - low)/2;
         int midn = solve(mid,n,m);
        if(midn == 1){
            return mid;
        }
        else if(midn == 0){
              low = mid+1;
        }
        else high = mid -1;
    }
     return -1;
}