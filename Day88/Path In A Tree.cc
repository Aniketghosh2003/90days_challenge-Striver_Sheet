#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
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
*/

bool solve(TreeNode<int> *root, int x,vector<int> &ans){
        if(!root)
	       return false;

	    if(root->data == x){
			ans.push_back(root->data);
			return true;
		}	   

        bool left = solve(root->left,x,ans);
		bool right = solve(root->right,x,ans);

		if(left || right) ans.push_back(root->data);

		return left || right;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> ans;
	solve(root,x,ans);
	reverse(ans.begin(),ans.end());
	return ans;
}
