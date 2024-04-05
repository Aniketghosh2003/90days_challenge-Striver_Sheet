/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

*****************************************************************/
#include <bits/stdc++.h>

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    unordered_map<Node*,int> mp;

    Node* temp1 = firstHead;

    while(temp1 != NULL){
        mp[temp1] = 1;
        temp1 = temp1->next;
    }

    Node* temp2 = secondHead;
    while(temp2 != NULL){
           if(mp.find(temp2) != mp.end()){
               return temp2;
           }
           temp2 = temp2->next;
    }
    return  NULL;
}
