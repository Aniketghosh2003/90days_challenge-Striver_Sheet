/*
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
*/

int count(Node* head){
    int cnt  = 0;
     Node* temp = head;
     while(temp){
         temp = temp->next;
         cnt++;
     }
     return cnt;
}


Node* removeKthNode(Node* head, int K)
{
       int len = count(head) - K;
       if(len == 0){
           head = head->next;
           return head;
       }
       Node* temp = head;
       for(int i = 0;i < len-1;i++){
           temp = temp->next;
       }

       temp->next = temp->next->next;
       return head;
}
