#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
  int i = 0;
  int mid = 0;
  int j = n-1;
  while( mid <= j){
    if(arr[mid] == 0){
      swap(arr[i],arr[mid]);
      i++;
      mid++;
    }
    else if(arr[mid] == 2){
      swap(arr[mid],arr[j]);
      j--;
    }
    else if(arr[mid] == 1){
      mid++;
    }
  }
}