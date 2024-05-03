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
void func(TreeNode<int> *root,vector<int> &arr){
    if(root == NULL)
       return ;

    func(root->left, arr);
    arr.push_back(root->val);
    func(root->right,arr);
}
int floorInBST(TreeNode<int> * root, int X)
{
    vector<int> arr;
    func(root, arr);
     int s  = 0;
    for(int i = 0;i < arr.size();i++){
        if(arr[i] <= X)
            s = arr[i];
    }

    return s;
}