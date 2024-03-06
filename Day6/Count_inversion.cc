#include <bits/stdc++.h> 
long long merge(long long *arr, long long s, long e)
{
    
    long long c = 0;
    long long mid = s + (e - s) / 2;
    long long len1 = mid - s + 1;
    long long len2 = e - mid;
    long long mainindex = s;
    long long *a = new long long[len1];
    long long *b = new long long[len2];

    for (long long i = 0; i < len1; i++)
    {
        a[i] = arr[mainindex++];
    }

    mainindex = mid + 1;
    for (long long i = 0; i < len2; i++)
    {
        b[i] = arr[mainindex++];
    }

    int i1 = 0;
    int i2 = 0;
    mainindex = s;

    while (i1 < len1 && i2 < len2)
    {
        if (a[i1] < b[i2])
        {
            arr[mainindex++] = a[i1++];
        }
        else
        {
            arr[mainindex++] = b[i2++];
            c += len1 - i1  ;
        }
    }

    while (i1 < len1)
    {
        arr[mainindex++] = a[i1++];
    }
    while (i2 < len2)
    {
        arr[mainindex++] = b[i2++];
    }
    delete[] a;
    delete[] b;
    return c;
}

long long mergesort(long long *arr, long long  s, long long e)
{
    long long c = 0;
    if (s < e)
    {
    int mid = s + (e - s) / 2;
    c += mergesort(arr, s, mid);
    c += mergesort(arr, mid + 1, e);
    c += merge(arr, s, e);
    }
    
    return c;
}


long long getInversions(long long *arr, int n){
    long long cnt = 0;
    cnt = mergesort(arr,0,n-1);
    // for(int i = 0;i < n;i++){
    //     for(int j = i+1;j < n;j++){
    //       if(arr[i] > arr[j]){
    //           cnt++;
    //       }
    //     }
    // }
    return cnt;
}