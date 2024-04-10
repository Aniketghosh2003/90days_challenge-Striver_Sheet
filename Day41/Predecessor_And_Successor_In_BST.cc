/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

int mini(TreeNode* root){
    int mi ;
    TreeNode* temp = root;
    while(temp){
          mi = temp->data;
          temp= temp->left;
    }

    return mi;
}

int maxi(TreeNode* root){
    int ma ;
    TreeNode* temp = root;
    while(temp){
          ma = temp->data;
          temp= temp->right;
    }

    return ma;
}

pair<int, int> predecessorSuccessor(TreeNode *root, int key) {
    
    TreeNode* temp = root;
    int suc = -1,pre = -1;

    while(temp && temp -> data != key){
           if(temp->data >key){
               suc = temp->data;
               temp  = temp->left;
           }
           else{
               pre = temp->data;
               temp = temp->right;
           }
    }
    
    if(temp){
        if(temp->left){
            pre = maxi(temp->left);
        }
        if(temp->right){
            suc = mini(temp->right);
        }
    }

     pair<int, int> ans = make_pair(pre,suc);
     return ans;
}