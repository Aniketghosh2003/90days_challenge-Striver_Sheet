/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
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
   };
   
   
 ************************************************************/

int position(vector<int> inorder, int elem, int s,int e){

 

    for(int i=s; i<=e; i++){

 

        if(inorder[i] == elem)

           return i;

 

    }

 

    return -1;

 

}

 

TreeNode<int>* solve(vector<int> &inorder, vector<int> &postorder, int &index, int start, int end, int n){

 

    // Base case

    if(index <0  || start > end)

       return NULL;

 

    int elem = postorder[index--];

    TreeNode<int>* root = new TreeNode<int>(elem);

    int pos = position(inorder, elem, start,end);

 
root->right = solve(inorder, postorder, index, pos + 1, end, n);
    root->left = solve(inorder, postorder, index, start, pos - 1, n);

    

 

    return root;

 

}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder){
     int n = postOrder.size();
     int ind = n-1;
	return solve(inOrder,postOrder,ind,0,n-1,n);

}
