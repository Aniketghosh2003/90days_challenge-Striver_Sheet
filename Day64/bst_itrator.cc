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

class BSTiterator
{  
   private: stack<TreeNode<int> *> st;
    
    public:
    BSTiterator(TreeNode<int> *root)
    {
       pushall(root);
    }

    int next()
    {
        TreeNode<int> *temp = st.top();
        st.pop();
        pushall(temp->right);
        return temp->data;
    }

    bool hasNext()
    {
        return !st.empty();
    }

    void pushall(TreeNode<int> * node){
        for(;node != NULL; st.push(node),node = node->left);
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/