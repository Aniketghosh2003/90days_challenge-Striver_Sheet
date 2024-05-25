#include <bits/stdc++.h>

class Node
{

    Node *list[26];

    int cntPrefix = 0;

    int cntEndWith = 0;

public:
    bool isNull(char ch)
    {

        return list[ch - 'a'] == NULL;
    }

    void insertNode(char ch, Node *newNode)
    {

        list[ch - 'a'] = newNode;
    }

    Node *moveToNextNode(char ch)
    {

        return list[ch - 'a'];
    }

    void setEnd()
    {

        cntEndWith++;
    }

    void setPrefixCnt()
    {

        cntPrefix++;
    }

    void setPrefix()
    {

        cntPrefix++;
    }

    int getPrefixCnt()
    {

        return cntPrefix;
    }

    int getEnd()
    {

        return cntEndWith;
    }

    void removePrefix()
    {

        cntPrefix--;
    }

    void removeNode()
    {

        cntEndWith--;
    }
};

class Trie
{

    Node *root;

public:
    Trie()
    {

        root = new Node();
    }

    void insert(string &word)
    {

        Node *node = root;

        for (char ch : word)
        {

            if (node->isNull(ch))

                node->insertNode(ch, new Node());

            node = node->moveToNextNode(ch);

            node->setPrefixCnt();
        }

        node->setEnd();
    }

    int countWordsEqualTo(string &word)
    {

        Node *node = root;

        for (char ch : word)
        {

            if (node->isNull(ch))
                return 0;

            else
                node = node->moveToNextNode(ch);
        }

        return node->getEnd();
    }

    int countWordsStartingWith(string &word)
    {

        Node *node = root;

        for (char ch : word)
        {

            if (node->isNull(ch))
                return 0;

            else
                node = node->moveToNextNode(ch);
        }

        return node->getPrefixCnt();
    }

    void erase(string &word)
    {

        Node *node = root;

        for (char ch : word)
        {

            if (node->isNull(ch))
                return;

            node = node->moveToNextNode(ch);

            node->removePrefix();
        }

        node->removeNode();
    }
};
