#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int>* createbst(int s,int e,vector<int> &arr){
    if(s >e){
        return nullptr;
    }
    int mid = s+(e-s)/2;
    TreeNode<int>* root =  new TreeNode<int>(arr[mid]);
    root->left =  createbst(s,mid-1,arr);
    root->right =  createbst(mid+1,e,arr);
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    int start = 0;
    int end =  n-1;
    int mid = start + (end-start)/2;
    TreeNode<int>* root =  new TreeNode<int>(arr[mid]);
    root->left =  createbst(start,mid-1,arr);
    root->right =  createbst(mid+1,end,arr);
}