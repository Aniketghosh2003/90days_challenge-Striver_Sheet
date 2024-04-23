#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void in(TreeNode<int>* root,     vector<int> &inorder){
    if(root == NULL){
        return;
    }

    in(root->left,inorder);
    inorder.push_back(root->data);
    in(root->right,inorder);
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
     vector<int> inorder;
     in(root,inorder);
     if (inorder.size() < k) {
        return -1;
     }
     return inorder[inorder.size()-k];
}
