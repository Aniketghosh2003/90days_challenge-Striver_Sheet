/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

void preorder(TreeNode *root,vector<int> &ans){
        if(root == NULL){
            return;
        }
        ans.push_back(root->data);

       preorder(root->left, ans);
       preorder(root->right,ans);
       
}
void inorder(TreeNode *root,vector<int> &ans){
        if(root == NULL){
            return;
        }
       inorder(root->left, ans);
       ans.push_back(root->data);
       inorder(root->right,ans);
}


void postorder(TreeNode *root,vector<int> &ans){
        if(root == NULL){
            return;
        }
       postorder(root->left, ans);
       postorder(root->right,ans);
       ans.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<int>pree;
    vector<int>ine;
    vector<int>poste;
    vector<vector<int>> ans;
     inorder(root,ine);
     preorder(root, pree);
     postorder(root, poste);
     

     ans.push_back(ine);
     ans.push_back(pree);
     ans.push_back(poste);
     return ans;
}