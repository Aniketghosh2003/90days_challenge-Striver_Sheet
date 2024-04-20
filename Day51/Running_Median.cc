#include <bits/stdc++.h>

void findMedian(int *arr, int n)
{
    priority_queue<int> max;
    priority_queue<int,vector<int> ,greater<int>> min;

    for(int i = 0;i < n;i++){
        if(max.size() == 0) max.push(arr[i]);
        else if (arr[i] > max.top()) min.push(arr[i]);
        else{
            max.push(arr[i]);
        }

        if (max.size() > min.size() + 1) {
            min.push(max.top());
            max.pop();
        }
    else if(max.size() < min.size()){
        max.push(min.top());
        min.pop();
    }

    if (max.size() == min.size()) {
        cout << (max.top() + min.top()) / 2
        << " ";
    } 
    else {
        cout << max.top() << " ";
    }
    }
}