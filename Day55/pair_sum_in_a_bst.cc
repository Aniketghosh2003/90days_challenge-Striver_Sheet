/**********************************************************
    Following is the Binary Tree Node structure:

    class BinaryTreeNode
    {
    public:
        int data;
        BinaryTreeNode *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(int x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(int x, BinaryTreeNode *left, BinaryTreeNode *right) : data(x), left(left), right(right) {}
    };
***********************************************************/
void func(BinaryTreeNode *root,vector<int> &arr){
    if(root == NULL)
       return ;

    func(root->left, arr);
    arr.push_back(root->data);
    func(root->right,arr);
}

bool pairSumBst(BinaryTreeNode *root, int k)
{
    vector<int> arr;
    func(root,arr);
    
    int i,j;
    int n = arr.size();
    i = 0,j = n-1;
    while(i < j){
       if(arr[i] + arr[j] == k) return true;
       else if(arr[i] + arr[j] > k) j--;
       else i++;
    }
    return false;
}