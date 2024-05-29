*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
class trienode
{
public:
    char data;
    trienode *children[26];
    bool isterminalnode;

    trienode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isterminalnode = false;
    }
};

class Trie {

public:
      
     trienode *root;
    /** Initialize your data structure here. */
    Trie() {
        root = new trienode('\0');
    }

    void insertuntill(trienode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isterminalnode = true;
            return;
        }

        int index = word[0] - 'a';
        trienode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new trienode(word[0]);
            root->children[index] = child;
        }

        insertuntill(child, word.substr(1));
    }

     
    /** Inserts a word into the trie. */
    void insert(string word) {
        insertuntill(root, word);
    }
  
bool searchuntill(trienode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isterminalnode;
        }

        int index = word[0] - 'a';
        trienode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        
        return searchuntill(child,word.substr(1));
        
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
     return searchuntill(root,word);
    }
    
    bool prefixuntill(trienode *root, string word)
    {
        if (word.length() == 0)
        {
            return true;
        }

        int index = word[0] - 'a';
        trienode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        
        return prefixuntill(child,word.substr(1));
        
    }
    

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return prefixuntill(root, prefix);
    }
};