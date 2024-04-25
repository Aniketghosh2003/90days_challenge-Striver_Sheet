/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

void in(BinaryTreeNode<int>* root,vector<int> &arr){
       if(root == NULL){
           return;
       }
       in(root->left,arr);
       arr.push_back(root->data);
       in(root->right,arr);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    vector<int> arr;
    in(root,arr);
    
    int n = arr.size();
    int i = 0,j = n-1;
    while(i < j){
        if(arr[i] != arr[j])
             return false;
        else{
            i++;
            j--;
        }     
    }
    return true;
}