/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void left(TreeNode<int> *root,vector<int> &ans){
       if(root == NULL  || (root->left == NULL && root->right == NULL))
            return ;

        ans.push_back(root->data);    

        if(root->left) 
             left(root->left,ans);

        else
            left(root->right,ans);
}

void leaf(TreeNode<int> *root,vector<int> &ans){
        if(root == NULL)
            return;

        if (root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);
            return;
        }

            leaf(root->left, ans);
            leaf(root->right, ans);
}

void right(TreeNode<int> *root,vector<int> &ans){
            
            if(root == NULL  || (root->left == NULL && root->right == NULL))
                    return ;

            if(root->right) right(root->right, ans);
            else right(root->left,ans);

            ans.push_back(root->data);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
	vector<int> ans;
    if(root == NULL)
           return ans;

   ans.push_back(root->data);
   
   left(root->left, ans);

   leaf(root->left,ans);
   leaf(root->right,ans);

   right(root->right,ans);

   return ans;
}
