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
// void pre(TreeNode<int> *root,vector<int> &preorder){
//     if(root == NULL)
//          return ;

//     preorder.push_back(root->data);
//     pre(root->left,preorder);
//     pre(root->right,preorder)    ;
// }
void flattenBinaryTree(TreeNode<int>* root)
{
    // vector<int> preorder;
    // pre(root,preorder);

    // for(int i = 1;i < preorder.size();i++){
    //     TreeNode<int> *node = new TreeNode<int>(preorder[i]);
    //     root->right = node;
    //     root->left = NULL;
        
    //     root = node;
    // }

    if(root == NULL)
        return ;

    static TreeNode<int> * prev = NULL;

    flattenBinaryTree(root->right);
    flattenBinaryTree(root->left);
    root->right = prev;
    root->left = NULL;
   
    prev = root ;

}