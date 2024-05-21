int search(int* arr, int n, int key) {
    // for(int i = 0;i < n;i++){
    //     if(arr[i] == key) return i;
    // }
    // return -1
    int s = 0;
    int e = n-1;

    while(s <= e){
         int mid = s+(e-s)/2;
         if(arr[mid] == key){
             return mid;
         }
         else if(arr[s] <= arr[mid]){
               if(arr[s] <= key && key < arr[mid]){
                    e = mid-1;
               }
               else{
                  s = mid+1;
               }
         }
         else{
            if(arr[mid] < key && key <= arr[e]){
                   s = mid+1;
               }
               else{
                  e = mid-1;
               }
         }
         
    }
    return -1;