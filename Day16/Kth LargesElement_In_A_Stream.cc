#include <algorithm>

class Kthlargest {
public:
   priority_queue<int,vector<int> ,greater<int>> pq;
   int size1;

    Kthlargest(int k, vector<int> &arr) {
       size1 = k;
       for(int i = 0;i < k;i++){
           add(arr[i]);
       }
    }

    int add(int num) {
       pq.push(num);
       if(pq.size() > size1){
           pq.pop();
       }
       return pq.top();
    }

};