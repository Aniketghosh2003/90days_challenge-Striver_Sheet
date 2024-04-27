#include <bits/stdc++.h> 

/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root)
{
   vector<int> ans;
   if(root == NULL) return ans;

   map<int,int> mp;
   queue<pair<TreeNode<int>*,int>> q;
   
   q.push({root,0});

   while(!q.empty()){
      auto curr = q.front();
      q.pop();
      TreeNode<int> * node = curr.first;
      int lev = curr.second;

      if(mp.find(lev) == mp.end()) mp[lev] = node->data;

      if(node->left) q.push({node->left, lev - 1});
      if(node->right) q.push({node->right, lev + 1});
   }

   for(auto it: mp){
       ans.push_back(it.second);
   }
   return ans;
}
