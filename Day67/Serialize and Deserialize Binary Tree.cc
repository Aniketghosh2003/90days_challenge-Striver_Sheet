#include <bits/stdc++.h> 

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

string serializeTree(TreeNode<int> *root)
{
if (!root)

        return "";

 

    string ans;

    queue<TreeNode<int>*> q;

    q.push(root);

 

    while (!q.empty()) {

 

        TreeNode<int>* front = q.front();

        q.pop();

 

        if (front) {

            ans += to_string(front->data) + " ";  

            q.push(front->left);

            q.push(front->right);

        } else {

            ans += "-1 ";  

        }

    }

 

    return ans;

}

TreeNode<int>* deserializeTree(string &serialized)
{
 if(serialized.empty()) return NULL;

 

    TreeNode<int> *root = new TreeNode<int>(stoi(serialized.substr(0, serialized.find(' '))));

 

    queue<TreeNode<int>*> q;

    q.push(root);

 

    int i = serialized.find(' ') + 1;

    int n = serialized.length();

 

    while(!q.empty() && i < n){

 

        TreeNode<int> *front = q.front();

        q.pop();

 

        string token;

        while(i < n && serialized[i] != ' '){

 

            token += serialized[i++];

 

        }

 

        i++; 

 

        if(token != "-1"){

 

            front->left = new TreeNode<int>(stoi(token));

            q.push(front->left);

 

        }

 

        token.clear();

 

        while(i < n && serialized[i] != ' '){

 

            token += serialized[i++];

 

        }

 

        i++; // Skip the space

 

        if(token != "-1"){

 

            front->right = new TreeNode<int>(stoi(token));

            q.push(front->right);

 

        }

    

 

    }

 

    return root;

 

    

}

