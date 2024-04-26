#include <bits/stdc++.h> 

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(T x) : data(x), left(NULL), right(NULL) {}
        TreeNode(T x, TreeNode<T> *left, TreeNode<T> *right) : data(x), left(left), right(right) {}
    };

************************************************************/
void func(TreeNode<int> *root,vector<int> &arr){
    if(root == NULL)
       return ;

    func(root->left, arr);
    arr.push_back(root->data);
    func(root->right,arr);
}
int kthSmallest(TreeNode<int> *root, int k)
{
    vector<int> arr;
    func(root, arr);

    return arr[k-1];
}
