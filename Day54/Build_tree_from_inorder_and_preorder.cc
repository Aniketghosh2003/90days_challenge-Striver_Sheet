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

int position(vector<int> inorder, int elem, int n){

 

    for(int i=0; i<n; i++){

 

        if(inorder[i] == elem)

           return i;

 

    }

 

    return -1;

 

}

 

TreeNode<int>* solve(vector<int> &inorder, vector<int> &preorder, int &index, int start, int end, int n){

 

    // Base case

    if(index >= n || start > end)

       return NULL;

 

    int elem = preorder[index++];

    TreeNode<int>* root = new TreeNode<int>(elem);

    int pos = position(inorder, elem, n);

 

    root->left = solve(inorder, preorder, index, start, pos - 1, n);

    root->right = solve(inorder, preorder, index, pos + 1, end, n);

 

    return root;

 

}

 

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder){

 

    int preIndex = 0;

    TreeNode<int>* ans = solve(inorder, preorder, preIndex, 0, inorder.size() - 1, inorder.size());

    return ans;

 

}