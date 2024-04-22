#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
   vector<int> ans;
   
   if(root == NULL){
       return ans;
   }
   queue<BinaryTreeNode<int>*> q;
   q.push(root);
    bool flag = true;

    while(!q.empty()){
        
         int size = q.size();
         vector<int> row(size);

         for(int i = 0;i < size ;i++){
             BinaryTreeNode<int> * curr = q.front();
             q.pop();
             
             int index = (flag) ? i : size-i-1;

             row[index]  = curr->data;

             if(curr->left != NULL){
                   q.push(curr->left);
             }
             if(curr->right != NULL){
                    q.push(curr->right);
             }
         }
         flag = !flag;
        for(auto i : row)
        ans.push_back(i);
    }
    return ans;
}
