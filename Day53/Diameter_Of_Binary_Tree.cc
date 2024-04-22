/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int diameter(TreeNode<int> *root,int& dia){
     if(!root){
         return 0;
     }
     int lf = diameter(root->left, dia);
     int rt = diameter(root->right, dia);

     dia = max(dia,lf+rt);
     return 1+max(lf,rt);
}

int diameterOfBinaryTree(TreeNode<int> *root){
	int ans = 0;
    int height = diameter(root, ans);
    return ans;
}
