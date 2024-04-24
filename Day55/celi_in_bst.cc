#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

void func(BinaryTreeNode<int> *root,vector<int> &arr){
    if(root == NULL)
       return ;

    func(root->left, arr);
    arr.push_back(root->data);
    func(root->right,arr);
}

int findCeil(BinaryTreeNode<int> *node, int x){
    vector<int> arr;
    func(node, arr);

    for(int i = 0;i < arr.size();i++){
        if(arr[i] >= x){
            return arr[i];
        }
    }
    return -1;
}