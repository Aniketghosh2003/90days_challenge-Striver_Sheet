/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int height(TreeNode<int>* root){
    if(root == NULL) return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return 1+max(lh,rh);
}

bool isBalancedBT(TreeNode<int>* root){
   if(root == NULL) return true;
   int diff = abs(height(root->left) - height(root->right));
   if(diff > 1) return false;

   return isBalancedBT(root->left) && isBalancedBT(root->right);
}