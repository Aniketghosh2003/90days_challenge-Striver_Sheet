#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
       map<int ,map< int,vector<int> > > nodes;
       queue< pair < TreeNode<int>* , pair<int ,int > > > q;
       vector <int> ans;
       if(root == NULL){
           return ans;
       }

       q.push({root,{0,0}});

       while(!q.empty()){
           auto temp = q.front();
           q.pop();
           TreeNode<int>* frontnode = temp.first;
           int hd = temp.second.first;
           int lev = temp.second.second;

           nodes[hd][lev].push_back(frontnode->data);

           if(frontnode->left)
                q.push(make_pair(frontnode->left, make_pair(hd-1, lev+1) ));
                
            if(frontnode->right)
                q.push(make_pair(frontnode->right, make_pair(hd+1, lev+1))); 
       }

       for(auto i: nodes) {
            
            for(auto j:i.second) {
                
                for(auto k:j.second)
                {
                    ans.push_back(k);
                }
            }
        }

       return ans;
}