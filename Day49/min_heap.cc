#include <bits/stdc++.h> 

void minheapify(int index,vector<int>& heap){
    int lchild=2*index+1;
    int rchild=2*index+2;
    int smallest=index;
    if(lchild<heap.size()&&heap[lchild]<heap[smallest]) 
    smallest=lchild;
    if(rchild<heap.size()&&heap[rchild]<heap[smallest]) 
    smallest=rchild;
    if(smallest!=index){
        swap(heap[smallest],heap[index]);
        minheapify(smallest,heap);
    }
}
int remove(vector<int>& heap){
    int ans=heap[0];
    swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();
    minheapify(0,heap);
    return ans;
}

void insert(vector<int> &heap,int ele){
      heap.push_back(ele);
      int ind = heap.size() - 1;
      int mid = (ind-1)/2;
      while(heap[mid] > heap[ind]){
           minheapify(mid, heap);
           ind = mid;
           mid = (ind-1)/2; 
      }
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> heap;
    vector<int> ans;
    for(int i  =0;i < q.size();i++){
        if(q[i][0] == 0){
            insert(heap,q[i][1]);
        }
        else{
            ans.push_back(remove(heap));
        }
    }
    return ans;
}
